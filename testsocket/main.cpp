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
	//���Ӷ�̬�����ã������ؽ�����һ��Ҫ��socket����ǰ���ã���Ҫ�ͷţ���
	WSAStartup(MAKEWORD(2, 2), &ws);
#endif // !linux

	//Э�飨�˴���tcp/ip,tcp��������������ɲ��裩
	auto sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		cout << "Create socket failed" << endl;
	}
	cout << "[" << sock << "]";
	closesocket(sock);
	return 0;
}