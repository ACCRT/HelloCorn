#ifndef COUNT_H
#define COUNT_H

#include<stdio.h>
#include <stdarg.h>
#include"hgefont.h"
#include<string>

using namespace std;

class Count
{
private:
	hgeFont* fnt;    // fnt�����������壬��ʾ�Ʒְ�E
	int score;       // score������¼����
	int time;        // time������¼��֡��
	double game_time;  // game_time������¼��Ϸʱ��E
	int best_score;  // best_score������¼���ѷ���
	int step;        // step������¼��������
public:
	Count();         // ��ԁE�E

	void add_score(int s);   // �ӷ֣���������s
	void add_time();         // ��֡��1
	void add_game_time();    // ����Ϸʱ�䣨ÿһ֡����֮��Ħ�t��
	void add_step();         // ����������1

	int get_time();          // ȡ��֡��
	double get_game_time();  // ȡ����Ϸʱ��E
	int get_score();         // ȡ�÷���
	int get_best_score();    // ȡ�����ѷ���
	int get_step();          // ȡ����������

	void set_fnt(string s);  // ��������fntΪs
	void set_game_time(double g);  // ������Ϸʱ��Ϊg
	void set_score(int s);   // ���÷���Ϊs
	void set_best_score(int b);    // �������ѷ���Ϊb
	void set_step(int s);    // ������������Ϊs
	void Render();           // ��ʾ

	void initial(string s);  // ��ʼ��

	~Count();    // ����ƁE
};

#endif