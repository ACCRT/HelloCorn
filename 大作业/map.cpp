#include"map.h"
#include"GUI.h"

Map::Map()
{}

void Map::Set_color(int i,int j, COLOR c){corn[i][j].Set_color(c);}
void Map::Set_kind(int i,int j, KIND k){corn[i][j].Set_kind(k);}
void Map::Set_state(int i,int j,STATE s){corn[i][j].Set_state(s);}
void Map::Set_effect(int i,int j,EFFECT e){corn[i][j].Set_effect(e);}
void Map::Set_location(int i,int j,pair<double,double> location){corn[i][j].Set_location(location);}
void Map::Set_corn(int i1,int j1,int i2,int j2){corn[i1][j1] = corn[i2][j2];}
void Map::Set_corn(int i,int j,Corn& c){corn[i][j] = c;}
void Map::Set_texture(int i,int j,HTEXTURE h){corn[i][j].SetTexture(h);}

void Map::Render()
{
	for(int i =0;i<6;i++)
		for(int j =0;j<6;j++)
			if(corn[i][j].GetTexture() != 0)
			{
				string choose_name= corn[i][j].Get_name();

				choose_name[0]=ftoa(corn[i][j].Get_color())[0];
				choose_name[1]=ftoa(corn[i][j].Get_state())[0];
				choose_name[2]=ftoa(corn[i][j].Get_kind())[0];
				choose_name[3]=ftoa(corn[i][j].Get_effect())[0];

				HTEXTURE temp = corn[i][j].GetTexture();
				gui->get_hge()->Texture_Free(temp);
				tex = gui->get_hge()->Texture_Load(choose_name.c_str());
				corn[i][j].SetTexture(tex);

				if(int(corn[i][j].Get_location().second) < j*corn_length)
					corn[i][j].Set_location(pair<double,double>(corn[i][j].Get_location().first,gui->get_map()->corn[i][j].Get_location().second+fall_speed*gui->get_hge()->Timer_GetDelta()));
				else
					corn[i][j].Set_location(pair<double,double>(i*corn_length,j*corn_length));
				
					corn[i][j].Render(corn[i][j].Get_location().first,corn[i][j].Get_location().second);
			}
}

void Map::initial()
{
	for(int i = 0;i < 6;i++)
		for(int j = 0;j < 6;j++)
		{
			Logic::create(i,j);
			gui->get_map()->Set_location(i,j,pair<double,double>(i*corn_length,-(6-j)*corn_length));
		}
}

string Map::Get_name(int i,int j){return corn[i][j].Get_name();}
COLOR Map::Get_color(int i,int j){return corn[i][j].Get_color();}
KIND Map::Get_kind(int i, int j){return corn[i][j].Get_kind();}
STATE Map::Get_state(int i,int j){return corn[i][j].Get_state();}
EFFECT Map::Get_effect(int i, int j){return corn[i][j].Get_effect();}
pair<double,double> Map::Get_location(int i,int j){return corn[i][j].Get_location();}
HTEXTURE Map::Get_texture(int i,int j){return corn[i][j].GetTexture();}

Map::~Map()
{
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		{
			HTEXTURE temp = gui->get_map()->Get_texture(i,j);
			gui->get_hge()->Texture_Free(temp);
		}
}