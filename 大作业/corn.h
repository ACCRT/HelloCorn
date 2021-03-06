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

enum COLOR {PURPLE, RED, YELLOW, BLUE, GREEN}; // 用来柄婢玉米颜色
enum STATE {SLEEP, AWAKE}; // 用来柄婢玉米是否被点粊E
enum KIND {KNORMAL, FROZEN};
enum EFFECT {ENORMAL, BOMB, HORIZONTAL, VERTICAL}; // 用来柄婢玉米种纴E

class Corn : public hgeSprite {
private:
	string name;  // 玉米图片名字
	COLOR color;  // 玉米颜色
	STATE state;  // 玉米状态，是否被点粊E
	KIND kind;    // 玉米种类，是否冰冻
	EFFECT effect;// 玉米的效箒E
	pair<double,double> location;
public:
	Corn();       // 默认复制构詠E?
	Corn(HTEXTURE tex,string s); // corn纹历戟tex，名字为s，坐眮E獂，y

	string Get_name(); // 取corn的名字
	COLOR Get_color(); // 取corn的颜色
	STATE Get_state(); // 取corn的状态，是否被点粊E
	KIND Get_kind();   // 取corn的种类，是否冰冻
	EFFECT Get_effect();// 取corn的效箒E
	pair<double,double> Get_location();   // 取corn的地址，first为x（第x列），second为y（第y行）
	
	void Set_color(COLOR c);  // 设置corn的颜色为c
	void Set_state(STATE s);  // 设置corn的状态为s
	void Set_kind(KIND k);    // 设置corn的种类为k
	void Set_effect(EFFECT e);// 设置corn的效果为e
	void Set_location(pair<double,double> p);   // 设置corn的地址为p
};

#endif