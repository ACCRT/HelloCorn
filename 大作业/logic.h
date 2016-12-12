#ifndef LOGIC_H
#define LOGIC_H

#include"GUI.h"

extern int score_one;

// �߼��࣬���������߼���ׁE
class Logic {
private:
	static bool esc();       // ��E��Ƿ������esc�˳�E

	static bool is_vanished(int i, int j);    // ��E��i�У���j�������Ƿ���ʧ
	static bool is_recording();     // ��E��Ƿ��ڼ��?
	static bool is_reviewing();     // ��E��Ƿ��ڻط?
	static bool can_vanish();       // ��E��Ƿ����?
	static bool can_add_special();  // ��E��Ƿ��������ȁE��׵�������Ϊ���ߵ���?����
	
	static bool MenuFrame(); // menuʱ���õ��߼�
	static bool GameFrame(); // gameʱ���õ��߼�

	static bool same_color(int i1,int j1,int i2,int j2);  // ��E�i1,j1����ӁE2,j2�����Ƿ�ͬɫ
public:
	static void connect();   // ��E���E������?
	static void associate(); // ��E����б��������������?

	static void save(string filename);    // �洢������Ϣ��filename��
	static void load(string filename);    // ��filename�ж�ȡ������Ϣ
	static void record();    // ��¼��һ֡����Ƶ
	static void review();    // �ط���һ֡����Ƶ

	//static void previous();

	static void vanish();    // ������ʧ
	static void fall();      // ���׵�E
	static void add_special();   // ��ȁE������?
	static void statistic(); // ͳ�Ʒ�����ʱ�����Ϣ

	static void fresh();     // ˢ��ͼƬΪȫ��δ���״̬
	static void clean();     // ������߼���������

	static void create(int i,int j);   // �ڵ�i��,j���������һ������

	static void start_review();     // ��ʼ�ط�
	static void stop_review();      // �����ط�
	static void start_record();     // ��ʼ��¼
	static void stop_record();      // ������¼

	static void return_to_menu();   // ���ص�menu stage
	static void return_to_game();   // ���ص�game stage
	static bool FrameFunc(); // hgeÿһ֡���õ��߼�����

};

#endif