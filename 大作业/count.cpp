#include"count.h"
#include"GUI.h"
#include"file.h"

Count::Count():score(0),fnt(0),best_score(0),step(0){}

void Count::add_score(int s){score+=s;}
void Count::add_time(){time=time+1;}
void Count::add_game_time(){game_time+=gui->get_hge()->Timer_GetDelta();}
void Count::add_step(){step++;}
int Count::get_score(){return score;}
int Count::get_time(){return time;}
int Count::get_best_score(){return best_score;}
double Count::get_game_time(){return game_time;}
int Count::get_step(){return step;}

void Count::set_fnt(string s)
{
	delete fnt;
	fnt = new hgeFont(s.c_str());
}

void Count::Render()
{
	fnt->SetColor(0xFF000000);
	fnt->SetScale(2);
	fnt->printf(700, 100, HGETEXT_LEFT, "score:%d\nbest:%d\nstep:%d\ntime:%d", score,best_score,step,int(game_time));
}

Count::~Count()
{
	delete fnt;
}

void Count::initial(string s)
{
	set_fnt("font1.fnt");
	score = 0;
	time = 0;
	step = 0;
	game_time =0;
	file->read_best_score();
}

void Count::set_game_time(double g){game_time =g;}
void Count::set_score(int s){score = s;}
void Count::set_best_score(int b){best_score = b;}
void Count::set_step(int s){step = s;}
