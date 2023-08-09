 ///
 /// @file    tcp_client.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-14 16:41:23
 ///
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define ERROR_EXIT(msg)\
	::perror(msg);\
	::exit(EXIT_FAILURE);
 
void test()
{

	int clientfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(clientfd == -1)
	{
		ERROR_EXIT("socket");
	}

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8888);
	serveraddr.sin_addr.s_addr = ::inet_addr("192.168.30.128");//直接返回一个网络字节序

	cout << "  >> client is connecting to server " << endl;
	int ret = ::connect(
			clientfd,
			(const struct sockaddr*)&serveraddr,
			sizeof(serveraddr));

	if(ret == -1)
	{
		::close(clientfd);
		ERROR_EXIT("connect");
	}

	//发送数据
	string data;
	cout << "  >> pls input data " << endl;
	cin >> data;
	ret = ::send(clientfd, data.c_str(), data.size(), 0);
	if(ret == -1)
	{
		::close(clientfd);
		ERROR_EXIT("send");
	}

	//接受数据
	
	char buff[1024] = {0};
	ret = ::recv(clientfd, buff, sizeof(buff), 0);
	if(ret > 0){
		cout << "  >> client received data from server : " << buff << endl;	
	}else if(ret == 0){
		::close(clientfd);
	}else if(ret == -1){
			::close(clientfd);
			ERROR_EXIT("recv");
	}
}
int main(void)
{
	test();
	return 0;
}
