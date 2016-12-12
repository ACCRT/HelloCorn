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

enum COLOR {PURPLE, RED, YELLOW, BLUE, GREEN}; // ﾓﾃﾀｴｱ桄ｾﾓﾗﾑﾕﾉｫ
enum STATE {SLEEP, AWAKE}; // ﾓﾃﾀｴｱ桄ｾﾓﾗﾊﾇｷｻｵ羹・
enum KIND {KNORMAL, FROZEN};
enum EFFECT {ENORMAL, BOMB, HORIZONTAL, VERTICAL}; // ﾓﾃﾀｴｱ桄ｾﾓﾗﾖﾖﾀ・

class Corn : public hgeSprite {
private:
	string name;  // ﾓﾗﾍｼﾆｬﾃ錥ﾖ
	COLOR color;  // ﾓﾗﾑﾕﾉｫ
	STATE state;  // ﾓﾗﾗｴﾌｬ｣ｬﾊﾇｷｻｵ羹・
	KIND kind;    // ﾓﾗﾖﾖﾀ爛ｬﾊﾇｷｳ
	EFFECT effect;// ﾓﾗｵﾄﾐｧｹ・
	pair<double,double> location;
public:
	Corn();       // ﾄｬﾈﾏｸｴﾖﾆｹｹﾔ・ｯﾊ?
	Corn(HTEXTURE tex,string s); // cornﾎﾆﾀ﨔ｪtex｣ｬﾃ錥ﾖﾎｪs｣ｬﾗ・ｪx｣ｬy

	string Get_name(); // ﾈ｡cornｵﾄﾃ錥ﾖ
	COLOR Get_color(); // ﾈ｡cornｵﾄﾑﾕﾉｫ
	STATE Get_state(); // ﾈ｡cornｵﾄﾗｴﾌｬ｣ｬﾊﾇｷｻｵ羹・
	KIND Get_kind();   // ﾈ｡cornｵﾄﾖﾖﾀ爛ｬﾊﾇｷｳ
	EFFECT Get_effect();// ﾈ｡cornｵﾄﾐｧｹ・
	pair<double,double> Get_location();   // ﾈ｡cornｵﾄｵﾘﾖｷ｣ｬfirstﾎｪx｣ｨｵﾚxﾁﾐ｣ｩ｣ｬsecondﾎｪy｣ｨｵﾚyﾐﾐ｣ｩ
	
	void Set_color(COLOR c);  // ﾉ靹ﾃcornｵﾄﾑﾕﾉｫﾎｪc
	void Set_state(STATE s);  // ﾉ靹ﾃcornｵﾄﾗｴﾌｬﾎｪs
	void Set_kind(KIND k);    // ﾉ靹ﾃcornｵﾄﾖﾖﾀ猥ｪk
	void Set_effect(EFFECT e);// ﾉ靹ﾃcornｵﾄﾐｧｹ鉸ｪe
	void Set_location(pair<double,double> p);   // ﾉ靹ﾃcornｵﾄｵﾘﾖｷﾎｪp
};

#endif