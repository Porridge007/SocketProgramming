#ifndef linux
#include <windows.h>
#else
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#define closesocket close
#endif 
#include <iostream>

int main()
{
	using namespace std;
#ifndef linux
	WSADATA ws;
	//增加动态库引用，并加载进来（一定要在socket函数前调用，需要释放）。
	WSAStartup(MAKEWORD(2, 2), &ws);
#endif // !linux

	//协议（此处是tcp/ip,tcp，第三参数可设可不设）
	auto sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		cout << "Create socket failed" << endl;
	}
	cout << "[" << sock << "]";
	closesocket(sock);
	return 0;
}