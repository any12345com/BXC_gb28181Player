//
// Created by bxc on 2023/4/18.
// ���ߣ���С��
// ���䣺bilibili_bxc@126.com
// ������Ƶ��ҳ��https://www.ixigua.com/home/4171970536803763
// ����������ҳ��https://space.bilibili.com/487906612/
//

#ifndef GB28181PLAYER_GB28181PLAYER_H
#define GB28181PLAYER_GB28181PLAYER_H

#include <windows.h>
#include <atomic>
#define  SDL_MAIN_HANDLED
#include <SDL.h>

extern "C"
{
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
	#include <libswscale/swscale.h>
}
#define GB28181Player_buffer_max_size 4194304 // 4M = 4 * 1024 * 1024 = 4194304 �ֽ�

class GB28181Player
{
public:
	GB28181Player();
	~GB28181Player();
public:
	bool probe();//����ʽ̽�����������ȡ�������
	void play();//��̽��������ɹ��Ժ󣬽��벢��Ⱦ������Ƶ��
public:
	std::atomic<char> buffer[GB28181Player_buffer_max_size];
	std::atomic_int   bufferSize = 0;
private:
	AVFormatContext    * mFmtCtx;
	AVIOContext        * mAvioCtx;
	const AVInputFormat* mInputFmt;
	int                  mVideoStream = -1;
	AVCodecParameters  * mVideoCodecPar;
	AVCodecContext     * mVideoCodecCtx;

	AVDictionary* net_options;//�������Ӳ���
	AVDictionary* codec_options;//�������

};
#endif //GB28181PLAYER_GB28181PLAYER_H