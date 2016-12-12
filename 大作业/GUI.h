#ifndef GUI_H
#define GUI_H

#include<stdio.h>
#include <stdarg.h>
#include<time.h>
#include<string>
#include <sstream>
#include<iostream>
#include<stdlib.h>
#include"hgeGUI.h"
#include"corn.h"
#include"map.h"
#include"line.h"
#include"logic.h"
#include"count.h"
#include"menu.h"

using namespace std;

string ftoa(double value);
extern int fall_speed; // ���׵ĵ����ٶ�

enum STAGE{MENU,GAME};

// GUI�������������ͼ�λ���
class GUI
{
private:
	STAGE stage;  // stage������¼���ڲ˵�������Ϸ��
	Line* line;   // line������¼�����Լ���������Ϣ
	Map* map;     // map������¼6*6corn��������Ϣ
	HGE* hge;     // hge���
	Count* count; // count����ʱ���������Ϣ
	HEFFECT music;
	hgeSprite background;    // backgroundΪ����
	Menu* menu;   // menu��Ϊ�˵���Ϣ

	static void draw_corn();         // ��������
	static void draw_background();   // ���Ʊ���
	static void draw_count();        // ���ƼƷְ�E
	static void draw_menu();         // ���Ʋ˵�
	
	static void initial_menu();      // ��ʼ���˵�
	static void initial_corn();      // ��ʼ������
	static void initial_background();// ��ʼ������
	static void initial_hge();       // ��ʼ��hge���
	static void initial_count();     // ��ʼ���Ʒְ�E
	static void initial_music();
	
	static bool MenuRender();        // �˵�ʱ��RenderFunc
	static bool GameRender();        // ��Ϸʱ��RenderFunc
public:
	GUI();                      // GUI��ԁE�E

	HGE* get_hge();             // ����hge
	Line* get_line();           // ȡ��������Ϣ
	Map* get_map();             // ȡ�õ�ͼ�����ף���Ϣ
	Count* get_count();         // ȡ�üƷ���Ϣ
	Menu* get_menu();           // ȡ�ò˵���Ϣ
	STAGE get_stage();          // ȡ��������Ϸ��˵�

	void set_stage(STAGE s);    // ����stage

	static bool RenderFunc();   // hgeÿһ֡���õĻ�ͼ����
	static void initial();      // ��ʼ��
	static void reinitial();    // ���³�ʼ��

	~GUI();                     // ����
};

extern GUI* gui;

#endif
