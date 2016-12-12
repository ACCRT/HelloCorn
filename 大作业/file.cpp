#include"file.h"
#include"GUI.h"

File* file =0;

File::File()
	:save(),record(),load(),is_recording(false),is_reviewing(false)
{
	if(!save)
		exit(0);
	file = this;
}

void File::write_file(string filename)
{
	save.open(filename.c_str());
	save<<gui->get_count()->get_game_time()<<"\n";
	save<<gui->get_count()->get_score()<<"\n";
	for(int i=0;i<6;i++)
		for(int j =0;j<6;j++)
		{
			save<<gui->get_map()->Get_color(i,j)<<" ";
			save<<gui->get_map()->Get_state(i,j)<<" ";
			save<<gui->get_map()->Get_kind(i,j)<<" ";
			save<<gui->get_map()->Get_effect(i,j)<<" ";
			save<<"\n";
		}
	save.close();
}
void File::read_file(string filename)
{
	double temp;
	load.open(filename.c_str());

	load>>temp;
	gui->get_count()->set_game_time(temp);
	load>>temp;
	gui->get_count()->set_score(temp);
	for(int i=0;i<6;i++)
		for(int j =0;j<6;j++)
		{
			load>>temp;
			gui->get_map()->Set_color(i,j,COLOR(int(temp)));
			load>>temp;
			gui->get_map()->Set_state(i,j,STATE(int(temp)));
			load>>temp;
			gui->get_map()->Set_kind(i,j,KIND(int(temp)));
			load>>temp;
			gui->get_map()->Set_effect(i,j,EFFECT(int(temp)));
		}
	load.close();
}

void File::record_file()
{
	record<<gui->get_count()->get_game_time()<<"\n";
	record<<gui->get_count()->get_score()<<"\n";
	for(int i=0;i<6;i++)
		for(int j =0;j<6;j++)
		{
			record<<gui->get_map()->Get_color(i,j)<<" ";
			record<<gui->get_map()->Get_state(i,j)<<" ";
			record<<gui->get_map()->Get_kind(i,j)<<" ";
			record<<gui->get_map()->Get_effect(i,j)<<" ";
			record<<gui->get_map()->Get_location(i,j).first<<" ";
			record<<gui->get_map()->Get_location(i,j).second<<" ";
			record<<"\n";
		}
}
void File::review_file()
{
	double temp;
	double temp2;

	review>>temp;
	if(review.eof())
	{
		Logic::stop_review();
		Logic::return_to_menu();
		return;
	}
	gui->get_count()->set_game_time(temp);
	review>>temp;
	gui->get_count()->set_score(temp);
	for(int i=0;i<6;i++)
		for(int j =0;j<6;j++)
		{
			review>>temp;
			gui->get_map()->Set_color(i,j,COLOR(int(temp)));
			review>>temp;
			gui->get_map()->Set_state(i,j,STATE(int(temp)));
			review>>temp;
			gui->get_map()->Set_kind(i,j,KIND(int(temp)));
			review>>temp;
			gui->get_map()->Set_effect(i,j,EFFECT(int(temp)));
			review>>temp;
			review>>temp2;
			gui->get_map()->Set_location(i,j,pair<double,double>(temp,temp2));
		}
}

void File::read_map(int i)
{
	string s = "map0.txt";
	s[3]=ftoa(i)[0];
	read_file(s.c_str());
}

void File::open_record(){record.open("video.txt");}
void File::close_record(){record.close();}
void File::open_review(){review.open("video.txt");}
void File::close_review(){review.close();}

bool File::get_is_recording()
{
	return is_recording;
}
void File::set_is_recording(bool b)
{
	is_recording = b;
}

bool File::get_is_reviewing()
{
	return is_reviewing;
}
void File::set_is_reviewing(bool b)
{
	is_reviewing = b;
}

void File::read_best_score()
{
	load.open("best.txt");
	int temp;
	load>>temp;
	gui->get_count()->set_best_score(temp);
	load.close();
}

void File::write_best_score()
{
	save.open("best.txt");
	save<<gui->get_count()->get_best_score();
	save.close();
}