#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include <stdarg.h>
#include"hgemenuitem.h"
#include <math.h>

class Menu
{
private:
	bool enter;          // enter判定是否进葋E蜗?
	HEFFECT	snd;         // snd为按钮的音效
	HTEXTURE tex;        // tex为鼠眮E奈评丒
	hgeQuad	background;  // background为背景
	hgeQuad touch;       // touch为enter的图片
	hgeGUI* hgui;        // hgui为button的连接界脕E
	hgeFont	*mfnt;       // mfnt为按钮的字虂E
	hgeSprite *spr;      // spr为鼠眮E丒
public:
	bool Frame();        // 逻辑函数
	bool Render();       // 显示函数
	void initial();      // 初始化
	~Menu();             // 析构苼E
};

#endif