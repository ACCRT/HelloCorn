#ifndef MAP_H
#define MAP_H

#include<stdio.h>
#include <stdarg.h>
#include"corn.h"
#include"hge.h"
#include"hgesprite.h"
#include<string>
#include <sstream>

class Map   // 用来存储地图信息
{
private:
	Corn corn[6][6];          // 6*6的玉米矩諄E
public:
	Map();

	void Set_color(int i,int j, COLOR c);         // 设置第i列，第j行的颜色为c
	void Set_kind(int i,int j, KIND k);           // 设置第i列，第j行的种类为k
	void Set_state(int i,int j,STATE s);          // 设置第i列，第j行的状态为s
	void Set_effect(int i,int j,EFFECT e);        // 设置第i列，第j行的效果为e
	void Set_location(int i,int j,pair<double,double> location);   // 设置第i列，第j行的位置为location
	void Set_corn(int i1,int j1,int i2,int j2);   // 将第j1行第i1列的玉米赋给第j2行第i2列的玉米
	void Set_corn(int i,int j,Corn& c);           // 设置第i列，第j行的玉米为c
	void Set_texture(int i,int j,HTEXTURE h);     // 设置第i列，第j行的纹历戟h
	
	void Render();             // 显示
	void initial();            // 初始化

	string Get_name(int i,int j);        //
	COLOR Get_color(int i,int j);        //
	KIND Get_kind(int i, int j);
	STATE Get_state(int i,int j);
	EFFECT Get_effect(int i, int j);
	pair<double,double> Get_location(int i,int j);
	HTEXTURE Get_texture(int i,int j);

	~Map();
};

#endif