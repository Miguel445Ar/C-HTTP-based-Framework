#pragma once
#include <WinSock2.h>
#include <iostream>
#include "../routes/RoutesManager.hpp"

class HttpServer {
public:
	HttpServer();
	void run();
private:
	WSADATA* _winsockInitializer;
	SOCKET _serverSocket;
	SOCKET _clientSocket;
};