#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include <stdarg.h>
#include"hgemenuitem.h"
#include <math.h>

class Menu
{
private:
	bool enter;          // enter�ж��Ƿ��ȁE��?
	HEFFECT	snd;         // sndΪ��ť����Ч
	HTEXTURE tex;        // texΪ��E�����E
	hgeQuad	background;  // backgroundΪ����
	hgeQuad touch;       // touchΪenter��ͼƬ
	hgeGUI* hgui;        // hguiΪbutton�����ӽ�ÁE
	hgeFont	*mfnt;       // mfntΪ��ť����́E
	hgeSprite *spr;      // sprΪ��E���E
public:
	bool Frame();        // �߼�����
	bool Render();       // ��ʾ����
	void initial();      // ��ʼ��
	~Menu();             // ����ƁE
};

#endif