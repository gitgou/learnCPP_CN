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
#include <pthread.h>

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define ERROR_EXIT(msg)\
	::perror(msg);\
	::exit(EXIT_FAILURE); 
struct thread_data
{
	string ip;
	unsigned port;
	int peerfd;
};
void * process(void * arg)
{
	struct thread_data *local_thread_data = (struct thread_data*)arg;
	int peerfd = local_thread_data->peerfd;
	//打印客户端ip/port
	cout << " >> server serve client with peerfd = " << local_thread_data->peerfd << endl;
	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(sockaddr_in);
	getpeername(local_thread_data->peerfd, (struct sockaddr*)&clientaddr, &len);
	int clientport = clientaddr.sin_port;
	string clientip(inet_ntoa(clientaddr.sin_addr));//传参struct in_addr
	cout << "server socket: " << local_thread_data->ip << ":" << local_thread_data->port << " << ---- >> "
		 << "client socket: " << clientip << ":" << clientport << endl;

	//接受客户端数据
	char buff[1024] = {0};
	int ret = ::recv(peerfd, buff, sizeof(buff), 0);
	if(ret > 0){
	//接受成功
	cout << "buff data from client = " << buff << endl;
	}else if(ret == 0){
		::close(peerfd);
	}else if(ret == -1){
		if(ret == -1 && errno == EINTR){
			return nullptr;
		}else{
			::close(peerfd);
			ERROR_EXIT("recv");
		}
	}
	
	//发送数据
	int ret_send = ::send(peerfd, buff, strlen(buff), 0);
	if(ret_send == -1)
	{
		ERROR_EXIT("send");
		::close(peerfd);
	}
}


struct thread_data  pth_data;
void test()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
	{
		ERROR_EXIT("socket");
		//perror("socket()");
		//EXIT_FAILURE 表示没有成功执行一个程序
		//EXIT_SUCCESS 表示成功执行一个程序
		//exit(EXIT_FAILURE);
	}
	
	//网络地址，端口号初始化
	unsigned port = 8888;
	string ip("192.168.30.128");
	
	pth_data.port = port;
	pth_data.ip = ip;
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);//端口号
	addr.sin_addr.s_addr = inet_addr(ip.c_str()); //ip.data()
	
	//socket绑定网络地址
	if(-1 == ::bind(listenfd, (const struct  sockaddr *)&addr, sizeof(addr)))
	{
		ERROR_EXIT("bind");
	}

	// 对新链接进行监听
	if(-1 == ::listen(listenfd, 10))
	{
		ERROR_EXIT("listen");
	}
	//struct sockaddr clientaddr;
	//建立链接，完成三次握手
	vector<pthread_t> pthreads;
	while(1)
	{
		cout << "  >>> server listenfd = " << listenfd << endl;
		cout << "  >> server is accepting a new link " << endl;
		int peerfd = ::accept(listenfd, nullptr, nullptr);
		if(peerfd == -1)
		{
			//<unistd.h>头文件
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		//创建线程
		//struct thread_data * pth_data;
		pth_data.peerfd = peerfd;
		pthread_t pthid = 0;
		if(pthread_create(&pthid, NULL, process, (void*)&pth_data))
		{
			ERROR_EXIT("pthread_create");
		}
		
		pthreads.push_back(pthid);
	
	}//end of while

	for(auto & pthread_id: pthreads)
	{
		pthread_join(pthread_id, NULL);
	}
	::close(listenfd);
} //end of test


int main(void)
{
	test();
	return 0;
}
