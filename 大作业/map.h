#ifndef MAP_H
#define MAP_H

#include<stdio.h>
#include <stdarg.h>
#include"corn.h"
#include"hge.h"
#include"hgesprite.h"
#include<string>
#include <sstream>

class Map   // �����洢��ͼ��Ϣ
{
private:
	Corn corn[6][6];          // 6*6�����׾�ՁE
public:
	Map();

	void Set_color(int i,int j, COLOR c);         // ���õ�i�У���j�е���ɫΪc
	void Set_kind(int i,int j, KIND k);           // ���õ�i�У���j�е�����Ϊk
	void Set_state(int i,int j,STATE s);          // ���õ�i�У���j�е�״̬Ϊs
	void Set_effect(int i,int j,EFFECT e);        // ���õ�i�У���j�е�Ч��Ϊe
	void Set_location(int i,int j,pair<double,double> location);   // ���õ�i�У���j�е�λ��Ϊlocation
	void Set_corn(int i1,int j1,int i2,int j2);   // ����j1�е�i1�е����׸�����j2�е�i2�е�����
	void Set_corn(int i,int j,Corn& c);           // ���õ�i�У���j�е�����Ϊc
	void Set_texture(int i,int j,HTEXTURE h);     // ���õ�i�У���j�е������h
	
	void Render();             // ��ʾ
	void initial();            // ��ʼ��

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