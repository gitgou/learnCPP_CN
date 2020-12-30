 ///
 /// @file    tcp_server.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-13 20:37:42
 ///


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include<sys/epoll.h>
#include <sys/time.h>
#include <fcntl.h>

#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::cout;
using std::endl;
using std::string;

#define ERROR_EXIT(msg)\
	::perror(msg);\
	::exit(EXIT_FAILURE); 

int create_tcp_socket()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
	{
		ERROR_EXIT("socket");
	}
	cout << "  >>> server listenfd = " << listenfd << endl;
	return listenfd;
}

void set_addr_reuse(int fd)
{
	int reuse = 1;
	if(::setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const void*)&reuse, sizeof(socklen_t)) == -1)
	{
		ERROR_EXIT("setsockopt");
	}
}

void set_port_reuse(int fd)
{
	int reuse = 1;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, (const void*)& reuse, sizeof(socklen_t)) == -1)
	{
		ERROR_EXIT("setsockopt");
	}
}
int bind_inet_addr(int fd, const char * ip, unsigned short port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);//端口号
	addr.sin_addr.s_addr = inet_addr(ip); //ip.data()
	int ret = ::bind(fd, (const struct sockaddr*)&addr, sizeof(sockaddr_in));
	if(ret == -1)
	{
		::close(fd);
		ERROR_EXIT("bind");
	}
	return ret;
}

int mylisten(int fd)
{
	int ret = ::listen(fd, 10);//加入监听队列
	if(-1 == ret)
	{
		::close(fd);
		ERROR_EXIT("listen");
	}
	return ret;
}

int my_accept(int fd)
{
		int peerfd = ::accept(fd, nullptr, nullptr);
		if(peerfd == -1)
		{
			//<unistd.h>头文件
			::close(fd);
			perror("accept");
		}
		return peerfd;
}
int hand_new_connection(int listenfd)
{
		cout << "  >> server is accepting a new link " << endl;
		int peerfd = my_accept(listenfd);
		
		//打印客户端ip/port
		cout << " >> server serve client with peerfd = " << peerfd << endl;
		struct sockaddr_in clientaddr;
		socklen_t len = sizeof(sockaddr_in);
		::getpeername(peerfd, (struct sockaddr*)&clientaddr, &len);
		unsigned short clientport = clientaddr.sin_port;
		string clientip(inet_ntoa(clientaddr.sin_addr));//传参struct in_addr
		
		//得到服务器端ip/port
		struct sockaddr_in serveraddr;
		socklen_t client_len = sizeof(struct sockaddr_in);
		::getsockname(peerfd, (struct sockaddr*)&serveraddr, &client_len);
		unsigned short serverport = serveraddr.sin_port;
		string serverip(inet_ntoa(serveraddr.sin_addr));
		cout << "server socket: " << serverip << ":" << serverport << " << ---- >> "
			 << "client socket: " << clientip << ":" << clientport << endl;

		return peerfd;
}

void add_epoll_readfd(int epfd, int fd)
{
	struct epoll_event value;
	value.data.fd = fd;
	value.events = EPOLLIN;
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &value);
	if(ret == -1)
	{
		perror("epoll_ctl");
	}
}

void delete_epoll_readfd(int epfd, int fd)
{
	struct epoll_event value;
	value.data.fd = fd;
	value.events = EPOLLIN;
	int ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &value);
	if(ret == -1)
	{
		perror("epoll_ctl");
	}
}
void hand_client_message(int epfd,  int peerfd, unordered_set<int> & client_set)
{
		//接受客户端数据
		char buff[1024] = {0};
		int ret = ::recv(peerfd, buff, sizeof(buff), 0);
		if(ret > 0){
			//接受成功
			cout << "buff data from client = " << buff << endl;
			//发送数据
			int ret_send = ::send(peerfd, buff, strlen(buff), 0);
			if(ret_send == -1)
			{
				perror("send");
				::close(peerfd);
			}
		//	::sleep(1);
		//	delete_epoll_readfd(epfd, peerfd);
		//	::close(peerfd);
		//	client_set.erase(peerfd);
			//完成发送数据需要把peerfd清除，因为客户端将断开1链接，此文件描述符将不存在
		}else if(ret == 0){
			::close(peerfd);
			delete_epoll_readfd(epfd, peerfd);
			client_set.erase(peerfd);
		}else if(ret == -1){
			if(ret == -1 && errno == EINTR){
				return ;
			}else{
				perror("recv");
			}
		}
}
//将文件描述符设置为非阻塞
void set_non_block(int fd)
{
	int flag = ::fcntl(fd, F_GETFL, 0);//得到文件的状态
	if(flag == -1)
	{
		ERROR_EXIT("fcntl");
	}
	int ret = ::fcntl(fd, F_SETFL, O_NONBLOCK|flag);
	if(ret == -1)
	{
		ERROR_EXIT("fcntl");
	}
}

void test()
{
	int listenfd = create_tcp_socket();	
	set_addr_reuse(listenfd);
	set_port_reuse(listenfd);
	//网络地址，端口号初始化
	unsigned short port = 8888;
	string ip("192.168.30.128");
	bind_inet_addr(listenfd, ip.c_str(), port);	

	// 对新链接始终进行监听
	
	mylisten(listenfd);
	//struct sockaddr clientaddr;
	//建立链接，完成三次握手
	
	//创建epoll对象
	int epfd = epoll_create1(0);
	add_epoll_readfd(epfd, listenfd);
	unordered_set<int> client_set;
	vector<struct epoll_event> event_list(1024);
	while(1) 
	{
		//event_list提供给内核存放就绪的文件描述符
		int ready = epoll_wait(epfd, &*event_list.begin(), event_list.size(), 6000);
		if(ready == event_list.size())
		{
			event_list.resize(event_list.size()*2);
		}
		cout << ">>> epoll retval = " << ready << endl;
		if(ready == -1 && errno == EINTR)
		{
			continue;
		}else if(ready == -1){
			ERROR_EXIT("epoll");
		}else if(ready == 0){
			cout << "epoll timeout" << endl;
		}else{
			//返回的ready为就绪的文件描述符数量，全都存放在event_list容器中
			
			for(int idx = 0; idx < ready; ++idx){
				if(event_list[idx].data.fd == listenfd && (event_list[idx].events & EPOLLIN)){
					//处理新连接
					int peerfd = hand_new_connection(listenfd);
					set_non_block(peerfd);
					add_epoll_readfd(epfd, peerfd);
					cout << "has connected!" << endl;
					client_set.insert(peerfd);
				}
				else if(event_list[idx].events & EPOLLIN){
					hand_client_message(epfd, event_list[idx].data.fd, client_set);
				}

			}//end of for
		}
	}//end of while
	::close(listenfd);
	delete_epoll_readfd(epfd, listenfd);
} //end of test


int main(void)
{
	test();
	return 0;
}
