#ifndef TCPSOCKET_H_
#define TCPSOCKET_H_

#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include "Magicnumbers.h"

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

using std::string;


typedef
	int socklen_t;

using std::cout;
using std::endl;

class TcpSocket{

private: 
	int m_Sock;
	struct sockaddr_in m_SockAddr;

public:
	TcpSocket();
	bool Create();
	void SetToNonBlock();
	bool Bind(string address, int port);
	bool Listen(int que);
	bool Accept(TcpSocket &clientSock);
	bool Connect(string address, int port);
	int Receive(char *buff, int buffSize);
	int Send(const char *buff, int len);
	bool Close();
};

#endif