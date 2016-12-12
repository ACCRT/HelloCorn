#include"logic.h"
#include"file.h"

int score_one = 10;

bool Logic::esc()
{
	if (gui->get_hge()->Input_KeyUp(HGEK_ESCAPE)) return true;
}

void Logic::return_to_menu(){gui->set_stage(MENU);}
void Logic::return_to_game(){gui->set_stage(GAME);}

bool Logic::MenuFrame()
{
	if(esc()) 
		return_to_game();
	return gui->get_menu()->Frame();
}

bool Logic::GameFrame()
{
	if(esc())
	{
		if(is_reviewing())
			stop_review();
		return_to_menu();
	}
	if(is_reviewing())
	{
		review();
		return false;
	}
	connect();
	associate();
	if(gui->get_hge()->Input_KeyUp(HGEK_LBUTTON) && can_vanish())
	{
		save("previous.txt");
		gui->get_count()->add_step();
		vanish();
		fall();
		statistic();
		if(can_add_special())
			add_special();
		clean();
	}
	if(!gui->get_hge()->Input_GetKeyState(HGEK_LBUTTON))
	{
		clean();
		fresh();
	}
	return false;
}

bool Logic::FrameFunc()
{
	gui->get_count()->add_time();
	switch(gui->get_stage())
	{
	case GAME:
		if(is_recording())
			record();
		gui->get_count()->add_game_time();
		return GameFrame();
		break;
	case MENU:
		return MenuFrame();
		break;
	}
}

bool Logic::same_color(int i1,int j1,int i2,int j2)
{
	return gui->get_map()->Get_color(i1,j1) == gui->get_map()->Get_color(i2,j2);
}

void Logic::connect()
{
	float x = 0;
	float y = 0;
	gui->get_hge()->Input_GetMousePos(&x,&y);
	x = int(x)/100;
	y = int(y)/100;
	if(0 <= x && x < 6 && 0 <= y && y < 6) 
		if(gui->get_hge()->Input_GetKeyState(HGEK_LBUTTON))
		{
			if(gui->get_line()->dot_is_empty() || (gui->get_line()->last_round(x,y) && Logic::same_color(int(x),int(y),gui->get_line()->last_dot().first,gui->get_line()->last_dot().second)))
			{
				gui->get_line()->add_dot(int(x),int(y));
				gui->get_map()->Set_state(int(x),int(y),AWAKE);
			}
			if(gui->get_line()->dot_number()-2>=0 && gui->get_line()->compare_dot_i(gui->get_line()->dot_number()-2,int(x),int(y)))
			{
				gui->get_map()->Set_state(gui->get_line()->get_dot(gui->get_line()->dot_number()-1).first,gui->get_line()->get_dot(gui->get_line()->dot_number()-1).second,SLEEP);
				gui->get_line()->delete_last_dot();
			}
		}
}

void Logic::associate()
{
	gui->get_line()->clean_vanish();
	fresh();

	for(int i = 0;i<gui->get_line()->dot_number();i++)
		gui->get_line()->add_vanish(gui->get_line()->get_dot(i).first,gui->get_line()->get_dot(i).second);

	for(int i=0;i<gui->get_line()->vanish_number(); i++)
	{
		EFFECT effect = gui->get_map()->Get_effect(gui->get_line()->get_vanish(i).first,gui->get_line()->get_vanish(i).second);
		switch(effect)
		{
		case ENORMAL:
			{
				gui->get_line()->add_vanish(gui->get_line()->get_vanish(i).first,gui->get_line()->get_vanish(i).second);
				gui->get_map()->Set_state(gui->get_line()->get_vanish(i).first,gui->get_line()->get_vanish(i).second,AWAKE);
				break;
			}
		case BOMB:
			{
				for(int x=-1;x<2;x++)
					for(int y=-1;y<2;y++)
					{
						if(gui->get_line()->get_vanish(i).first+x<6 && gui->get_line()->get_vanish(i).first+x>-1 && gui->get_line()->get_vanish(i).second+y<6 && gui->get_line()->get_vanish(i).second+y>-1)
						{
							gui->get_line()->add_vanish(gui->get_line()->get_vanish(i).first+x,gui->get_line()->get_vanish(i).second+y);
							gui->get_map()->Set_state(gui->get_line()->get_vanish(i).first+x,gui->get_line()->get_vanish(i).second+y,AWAKE);
						}
					}
				break;
			}
		case HORIZONTAL:
			{
				for(int x=0;x<6;x++)
				{
					gui->get_line()->add_vanish(x,gui->get_line()->get_vanish(i).second);
					gui->get_map()->Set_state(x,gui->get_line()->get_vanish(i).second,AWAKE);
				}
				break;
			}
		case VERTICAL:
			{
				for(int y=0;y<6;y++)
				{
					gui->get_line()->add_vanish(gui->get_line()->get_vanish(i).first,y);
					gui->get_map()->Set_state(gui->get_line()->get_vanish(i).first,y,AWAKE);
				}
				break;
			}
		}
	}

}

bool Logic::can_vanish()
{
	return gui->get_line()->dot_number() >= 3;
}

void Logic::vanish()
{
	for(int i=0;i<gui->get_line()->vanish_number(); i++)
	{
		HTEXTURE temp = gui->get_map()->Get_texture(gui->get_line()->get_vanish(i).first,gui->get_line()->get_vanish(i).second);
		gui->get_hge()->Texture_Free(temp);
		gui->get_map()->Set_texture(gui->get_line()->get_vanish(i).first,gui->get_line()->get_vanish(i).second,0);
	}
}

void Logic::create(int i,int j)
{
	string name = "0000.png";
	name[0] = ftoa(rand()%5)[0];
	//name[2] = ftoa(rand()%2)[0];
	//name[3] = ftoa(rand()%4)[0];

	tex=gui->get_hge()->Texture_Load(name.c_str());
	Corn temp_c(tex,name);
	gui->get_map()->Set_corn(i,j,temp_c);
}

bool Logic::is_vanished(int i,int j)
{
	return gui->get_map()->Get_texture(i,j) == 0;
}

void Logic::fall()
{
	for(int i = 5;i>=0;i--)
	{
		int fall_order = 0;
		bool stop_flag =0;
		bool has_frozen =0;
		for(int j =5;j>=0;j--)
			if(gui->get_map()->Get_kind(i,j) == FROZEN && !is_vanished(i,j))
				has_frozen = 1;
		if(has_frozen)
		{
			for(int j = 5;j>=0;j--)
			{
				while(is_vanished(i,j) && gui->get_map()->Get_name(i,j)!="bubble")
				{
					for(int k=j;k>0;k--)
					{
						if(gui->get_map()->Get_kind(i,k-1) == FROZEN && !is_vanished(i,k-1))
						{
							stop_flag = 1;
							gui->get_map()->Set_corn(i,k,Corn(0,"bubble"));
							break;
						}
						gui->get_map()->Set_corn(i,k,i,k-1);
					}
					if(stop_flag)
						continue;
					create(i,0);
					fall_order++;
					gui->get_map()->Set_location(i,0,pair<double,double>(i*corn_length,-fall_order*corn_length));
				}
			}
		}
		else
		{
			for(int j = 5;j>=0;j--)
			{
				while(is_vanished(i,j))
				{
					for(int k=j;k>0;k--)
						gui->get_map()->Set_corn(i,k,i,k-1);
					create(i,0);
					fall_order++;
					gui->get_map()->Set_location(i,0,pair<double,double>(i*corn_length,-fall_order*corn_length));
				}
			}
		}
	}
	/*for(int i=0;i<6;i++)
		for(int j = 0;j<6;j++)
		{
			while(is_vanished(i,j))
			{
				{
					if(i<5)
					{
						if(gui->get_map()->Get_kind(i,j) != FROZEN)
						{
							gui->get_map()->Set_corn(i,j,i+1,j-1);
							gui->get_map()->Set_corn(i+1,j-1,Corn(0,"bubble"));
							for(int k=j-1;k>0;k--)
								gui->get_map()->Set_corn(i+1,k,i+1,k-1);
							create(i+1,0);
							gui->get_map()->Set_location(i+1,0,pair<double,double>((i+1)*corn_length,gui->get_map()->Get_location(i+1,1).second-corn_length));
							int k =0;
							while(is_vanished(i,j+k+1))
							{
								gui->get_map()->Set_corn(i,j+k+1,i,j+k);
								gui->get_map()->Set_corn(i,j+k,Corn(0,"bubble"));
							}
						}
					}
				}
				create(i,0);
				gui->get_map()->Set_location(i,0,pair<double,double>(i*corn_length,-fall_order*corn_length));
			}
		}*/
}

bool Logic::can_add_special()
{
	return gui->get_line()->dot_number()>=5;
}

void Logic::add_special()
{
	gui->get_map()->Set_effect(rand()%6,rand()%6,EFFECT(rand()%3+1));
}

void Logic::fresh()
{
	for(int i = 0;i<6;i++)
		for(int j = 0;j<6;j++)
			gui->get_map()->Set_state(i,j,SLEEP);
}

void Logic::clean()
{
	if(!(gui->get_line()->dot_is_empty()))
		gui->get_line()->clean_dot();
	if(!(gui->get_line()->vanish_is_empty()))
	gui->get_line()->clean_vanish();
}

void Logic::statistic()
{
	gui->get_count()->add_score(score_one * gui->get_line()->vanish_number());
	if(gui->get_count()->get_score()>gui->get_count()->get_best_score())
		gui->get_count()->set_best_score(gui->get_count()->get_score());
	file->write_best_score();
}

void Logic::save(string filename){file->write_file(filename);}
void Logic::load(string filename)
{
	file->read_file(filename);
	gui->set_stage(GAME);
}

void Logic::record()
{
	file->record_file();
}

bool Logic::is_recording()
{
	return file->get_is_recording();
}

bool Logic::is_reviewing()
{
	return file->get_is_reviewing();
}


void Logic::review()
{
	file->review_file();
}

void Logic::start_review()
{
	file->set_is_reviewing(true);
	file->open_review();
	save("temp.txt");
}

void Logic::stop_review()
{
	file->set_is_reviewing(false);
	file->close_review();
	load("temp.txt");
}
void Logic::start_record()
{
	file->set_is_recording(true);
	file->open_record();
}
void Logic::stop_record()
{
	file->set_is_recording(false);
	file->close_record();
}

//void Logic::previous()
//{
//	load("previous.txt");
//}