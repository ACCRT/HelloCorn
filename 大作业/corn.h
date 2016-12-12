#ifndef XXX
#define XXX

#include<stdio.h>
#include <stdarg.h>
#include"hge.h"
#include"hgesprite.h"
#include<string>
using namespace std;

extern HTEXTURE tex;
extern int corn_length;

enum COLOR {PURPLE, RED, YELLOW, BLUE, GREEN}; // �������������ɫ
enum STATE {SLEEP, AWAKE}; // ������������Ƿ񱻵㻁E
enum KIND {KNORMAL, FROZEN};
enum EFFECT {ENORMAL, BOMB, HORIZONTAL, VERTICAL}; // ���������������E

class Corn : public hgeSprite {
private:
	string name;  // ����ͼƬ����
	COLOR color;  // ������ɫ
	STATE state;  // ����״̬���Ƿ񱻵㻁E
	KIND kind;    // �������࣬�Ƿ����
	EFFECT effect;// ���׵�Ч��E
	pair<double,double> location;
public:
	Corn();       // Ĭ�ϸ��ƹ�ԁE��?
	Corn(HTEXTURE tex,string s); // corn�����tex������Ϊs������E�x��y

	string Get_name(); // ȡcorn������
	COLOR Get_color(); // ȡcorn����ɫ
	STATE Get_state(); // ȡcorn��״̬���Ƿ񱻵㻁E
	KIND Get_kind();   // ȡcorn�����࣬�Ƿ����
	EFFECT Get_effect();// ȡcorn��Ч��E
	pair<double,double> Get_location();   // ȡcorn�ĵ�ַ��firstΪx����x�У���secondΪy����y�У�
	
	void Set_color(COLOR c);  // ����corn����ɫΪc
	void Set_state(STATE s);  // ����corn��״̬Ϊs
	void Set_kind(KIND k);    // ����corn������Ϊk
	void Set_effect(EFFECT e);// ����corn��Ч��Ϊe
	void Set_location(pair<double,double> p);   // ����corn�ĵ�ַΪp
};

#endif