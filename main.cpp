//
// Created by bxc on 2023/4/18.
// ���ߣ���С��
// ���䣺bilibili_bxc@126.com
// ������Ƶ��ҳ��https://www.ixigua.com/home/4171970536803763
// ����������ҳ��https://space.bilibili.com/487906612/
//
#include "Server.h"
#include "gb28181Player.h"
#include <thread>

int main() {

	const char* ip = "127.0.0.1";
	uint16_t port = 8020;
	bool isUdp = false;// tcp or udp

	GB28181Player *player = new GB28181Player;
	std::thread([](GB28181Player* player1) {

		if (player1->probe()) {
			player1->play();
		}

	}, player).detach();
	Server server(ip, port, isUdp, player);
	server.start();

	return 0;
}