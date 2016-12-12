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
extern int fall_speed; // 玉米的掉落速度

enum STAGE{MENU,GAME};

// GUI类用来柄婢整个图形环境
class GUI
{
private:
	STAGE stage;  // stage用来记录是在菜单还是游戏中
	Line* line;   // line用来记录连线以及消除的信息
	Map* map;     // map用来记录6*6corn的所有信息
	HGE* hge;     // hge框架
	Count* count; // count用来时间分数等信息
	HEFFECT music;
	hgeSprite background;    // background为背景
	Menu* menu;   // menu即为菜单信息

	static void draw_corn();         // 绘制玉米
	static void draw_background();   // 绘制背景
	static void draw_count();        // 绘制计分皝E
	static void draw_menu();         // 绘制菜单
	
	static void initial_menu();      // 初始化菜单
	static void initial_corn();      // 初始化玉米
	static void initial_background();// 初始化背景
	static void initial_hge();       // 初始化hge框架
	static void initial_count();     // 初始化计分皝E
	static void initial_music();
	
	static bool MenuRender();        // 菜单时的RenderFunc
	static bool GameRender();        // 游戏时的RenderFunc
public:
	GUI();                      // GUI构詠E丒

	HGE* get_hge();             // 返回hge
	Line* get_line();           // 取得连线信息
	Map* get_map();             // 取得地图（玉米）信息
	Count* get_count();         // 取得计分信息
	Menu* get_menu();           // 取得菜单信息
	STAGE get_stage();          // 取得是在游戏或菜单

	void set_stage(STAGE s);    // 设置stage

	static bool RenderFunc();   // hge每一帧调用的绘图函数
	static void initial();      // 初始化
	static void reinitial();    // 重新初始化

	~GUI();                     // 析构
};

extern GUI* gui;

#endif
