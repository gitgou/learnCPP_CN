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
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <iostream>
#include <unordered_set>
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

void hand_client_message(int peerfd, fd_set *rfds, unordered_set<int> & client_set)
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
			::sleep(1);
			::close(peerfd);
			FD_CLR(peerfd, rfds);
			client_set.erase(peerfd);
			//完成发送数据需要把peerfd清除，因为客户端将断开1链接，此文件描述符将不存在
		}else if(ret == 0){
			::close(peerfd);
			FD_CLR(peerfd, rfds);
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
void select_fds_init(int & maxfd, fd_set *rfds, unordered_set<int> & client_set)
{
	for(auto & fd : client_set)
	{
		FD_SET(fd, rfds);
		if(fd > maxfd) maxfd = fd;
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
	
	fd_set rfds;//文件描述符集合,读事件的集合
	unordered_set<int> client_set; //存储已经建立好链接的文件描述符
	int maxfd = 1024;
	//struct timeval tv;
	while(1) 
	{
		//每次调用select前都需要重新设置fd和时间
		//因为事件发生后.fd和时间都被内核修改了
		FD_ZERO(&rfds);
		FD_SET(listenfd, &rfds);//将文件描述符添加到集合中
		
		select_fds_init(maxfd, &rfds, client_set);
		
		//对文件描述符进行轮询监听
		int ready = select(maxfd, &rfds, nullptr, nullptr, nullptr);
		cout << ">>> select retval = " << ready << endl;
		if(ready == -1 && errno == EINTR)
		{
			continue;
		}else if(ready == -1){
			ERROR_EXIT("select");
		}else if(ready == 0){
			cout << "select timeout" << endl;
		}else{
			//select 被调用会被阻塞，进入内核区，当有数据被接受则返回，
			//进入下面的指令-->对集合轮询进行检查（是否能够进行读写以及是否为listenfd）
			
			for(int fd = 0; fd < maxfd + 1; ++fd){
				if(FD_ISSET(fd, &rfds) && fd == listenfd){
					//处理新连接
					int peerfd = hand_new_connection(listenfd);
					set_non_block(peerfd);
					cout << "has connected!" << endl;
					FD_SET(peerfd, &rfds);
					client_set.insert(peerfd);
				}
				if(FD_ISSET(fd, &rfds) && fd != listenfd){
					hand_client_message(fd, &rfds, client_set);
				}

			}//end of for
		}
	}//end of while
	::close(listenfd);
	FD_CLR(listenfd, &rfds);
} //end of test


int main(void)
{
	test();
	return 0;
}
