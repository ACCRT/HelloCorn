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
	hgeFont* fnt;    // fnt用来加载字体，显示计分皝E
	int score;       // score用来记录分数
	int time;        // time用来记录总帧数
	double game_time;  // game_time用来记录游戏时紒E
	int best_score;  // best_score用来记录匮分数
	int step;        // step用来记录消除次数
public:
	Count();         // 构詠E丒

	void add_score(int s);   // 加分，分数上涨s
	void add_time();         // 加帧数1
	void add_game_time();    // 加游戏时间（每一帧调用之间的δt）
	void add_step();         // 加消除次数1

	int get_time();          // 取得帧数
	double get_game_time();  // 取得游戏时紒E
	int get_score();         // 取得分数
	int get_best_score();    // 取得匮分数
	int get_step();          // 取得消除次数

	void set_fnt(string s);  // 设置字体fnt为s
	void set_game_time(double g);  // 设置游戏时间为g
	void set_score(int s);   // 设置分数为s
	void set_best_score(int b);    // 设置匮分数为b
	void set_step(int s);    // 设置消除次数为s
	void Render();           // 显示

	void initial(string s);  // 初始化

	~Count();    // 析构苼E
};

#endif