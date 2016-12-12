#include"corn.h"
#include"GUI.h"
HTEXTURE tex = 0;
int corn_length = 100;

Corn::Corn() :
	 hgeSprite(tex, 1, 2, corn_length, corn_length), state(SLEEP)
{
}

Corn::Corn(HTEXTURE tex,string s) : 
	hgeSprite(tex, 0, 0, corn_length, corn_length), state(SLEEP),name(s)
{
	switch(s[0]) {
	case '0':
		color = PURPLE;
		break;
	case '1':
		color = RED;
		break;
	case '2':
		color = YELLOW;
		break;
	case '3':
		color = BLUE;
		break;
	case '4':
		color = GREEN;
		break;
	}
	switch(s[2]) {
	case '0':
		kind = KNORMAL;
		break;
	case '1':
		kind = FROZEN;
		break;
	}
	switch(s[3]) {
	case '0':
		effect = ENORMAL;
		break;
	case '1':
		effect = BOMB;
		break;
	case '2':
		effect = HORIZONTAL;
		break;
	case '3':
		effect = VERTICAL;
		break;
	}
}

COLOR Corn::Get_color(){return color;}
EFFECT Corn::Get_effect(){return effect;}
string Corn::Get_name(){return name;}
STATE Corn::Get_state(){return state;}
KIND Corn::Get_kind(){return kind;}
pair<double,double> Corn::Get_location(){return location;}

void Corn::Set_color(COLOR c){color = c;}
void Corn::Set_state(STATE s){state = s;}
void Corn::Set_effect(EFFECT e){effect = e;}
void Corn::Set_kind(KIND k){kind = k;}
void Corn::Set_location(pair<double,double> p){location = p;}
