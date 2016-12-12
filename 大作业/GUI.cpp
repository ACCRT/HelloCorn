#include"GUI.h"
GUI* gui = 0;

int fall_speed = 700;

GUI::GUI()
	:background(tex, 0, 0, 1032, 600),stage(MENU)
{
	menu = new Menu;
	line = new Line;
	map =new Map;
	count = new Count;
	gui = this;
	initial();
}

void GUI::initial()
{
	initial_hge();
	if(gui->hge->System_Initiate())
	{
		srand((unsigned)time(NULL));
		initial_corn();
		initial_menu();
		initial_background();
		initial_count();
		initial_music();
		gui->hge->System_Start();
	}
	else
	{	
		//MessageBox(NULL, gui->hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}
}

void GUI::initial_menu(){gui->menu->initial();}
void GUI::initial_corn(){gui->map->initial();}
void GUI::initial_count(){gui->count->initial("font1.fnt");}
void GUI::initial_music()
{
	gui->music = gui->hge->Effect_Load("ED6020.ogg");
	gui->hge->Effect_Play(gui->music);
}

void GUI::initial_background()
{
	tex = gui->hge->Texture_Load("1394171165001.jpg");
	gui->background.SetTexture(tex);
}

void GUI::initial_hge()
{
	gui->hge = hgeCreate(HGE_VERSION);
	gui->hge->System_SetState(HGE_FRAMEFUNC, Logic::FrameFunc);
	gui->hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	gui->hge->System_SetState(HGE_SHOWSPLASH,false);
	gui->hge->System_SetState(HGE_TITLE, "Corn");
	gui->hge->System_SetState(HGE_WINDOWED, true);
	gui->hge->System_SetState(HGE_USESOUND, true);
	gui->hge->System_SetState(HGE_HIDEMOUSE, false);
	gui->hge->System_SetState(HGE_SCREENWIDTH, 1032);
	gui->hge->System_SetState(HGE_SCREENHEIGHT, 600);
}

void GUI::draw_corn(){gui->get_map()->Render();}
void GUI::draw_background(){gui->background.Render(0,0);}
void GUI::draw_count(){gui->get_count()->Render();}

bool GUI::RenderFunc()
{
	switch(gui->stage)
	{
	case MENU:
			return MenuRender();
			break;
	case GAME:
			return GameRender();
			break;
	}
}

HGE* GUI::get_hge(){return hge;}
Map* GUI::get_map(){return map;}
Line* GUI::get_line(){return line;}
Count* GUI::get_count(){return count;}
Menu* GUI::get_menu(){return menu;}
STAGE GUI::get_stage(){return stage;}

GUI::~GUI()
{
	delete menu;
	delete count;
	delete map;
	delete line;
	hge->Effect_Free(music);
	tex = background.GetTexture();
	hge->Texture_Free(tex);
	hge->System_Shutdown();
	hge->Release();
}

string ftoa(double value)  
{
  std::ostringstream o;
  if(!(o << value)) 
   return "";
  return o.str();
}

bool GUI::MenuRender(){return gui->menu->Render();}

bool GUI::GameRender()
{
	gui->hge->Gfx_BeginScene();//开始渲染 
	draw_background();
	draw_corn();
	draw_count();
	gui->hge->Gfx_EndScene();//结束渲染
	return false;//总是返回false 
}

void GUI::set_stage(STAGE s){stage = s;}

void GUI::reinitial()
{
	initial_corn();
	initial_count();
}
