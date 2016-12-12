#include"menu.h"
#include"GUI.h"
#include"file.h"

bool Menu::Frame()
{
	if(!enter && gui->get_hge()->Input_GetKeyState(HGEK_LBUTTON))
	{
		enter =1;
		hgui->AddCtrl(new hgeGUIMenuItem(2,mfnt,snd,516,240,0.1f,"New game"));
		hgui->AddCtrl(new hgeGUIMenuItem(4,mfnt,snd,516,280,0.2f,"Load"));
		hgui->AddCtrl(new hgeGUIMenuItem(5,mfnt,snd,516,360,0.4f,"Exit"));
		hgui->AddCtrl(new hgeGUIMenuItem(6,mfnt,snd,516,320,0.3f,"video"));
	}
	

	float dt=gui->get_hge()->Timer_GetDelta();
	static float t=0.0f;
	float tx,ty;
	int id;
	static int lastid=0;

	// If ESCAPE was pressed, tell the GUI to finish
	//if(gui->get_hge()->Input_GetKey() == HGEK_ESCAPE) { lastid=5; hgui->Leave(); }
	
	// We update the GUI and take an action if
	// one of the menu items was selected
	id=hgui->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			{
				Logic::return_to_game();
				break;
			}
		case 2:
			{
				hgui->DelCtrl(1);
				hgui->DelCtrl(2);
				hgui->DelCtrl(3);
				hgui->DelCtrl(4);
				hgui->DelCtrl(5);
				hgui->DelCtrl(6);
				hgui->DelCtrl(7);
				hgui->DelCtrl(8);
				hgui->AddCtrl(new hgeGUIMenuItem(9,mfnt,snd,516,240,0.1f,"Level 1"));
				hgui->AddCtrl(new hgeGUIMenuItem(10,mfnt,snd,516,280,0.2f,"Level 2"));
				hgui->AddCtrl(new hgeGUIMenuItem(12,mfnt,snd,516,360,0.4f,"Free"));
				hgui->AddCtrl(new hgeGUIMenuItem(11,mfnt,snd,516,320,0.3f,"Level 3"));
				break;
			}
		case 3:
			{
				Logic::save("save.txt");
				break;
			}
		case 4:
			{
				Logic::load("save.txt");
				hgui->DelCtrl(1);
				hgui->DelCtrl(2);
				hgui->DelCtrl(3);
				hgui->DelCtrl(4);
				hgui->DelCtrl(5);
				hgui->DelCtrl(6);
				hgui->DelCtrl(7);
				hgui->DelCtrl(8);
				hgui->AddCtrl(new hgeGUIMenuItem(2,mfnt,snd,516,200,0.1f,"New game"));
				hgui->AddCtrl(new hgeGUIMenuItem(4,mfnt,snd,516,280,0.3f,"Load"));
				hgui->AddCtrl(new hgeGUIMenuItem(5,mfnt,snd,516,400,0.6f,"Exit"));
				hgui->AddCtrl(new hgeGUIMenuItem(1,mfnt,snd,516,160,0.0f,"Continue"));
				hgui->AddCtrl(new hgeGUIMenuItem(6,mfnt,snd,516,360,0.5f,"Video"));
				hgui->AddCtrl(new hgeGUIMenuItem(3,mfnt,snd,516,240,0.2f,"Save"));
				hgui->AddCtrl(new hgeGUIMenuItem(7,mfnt,snd,516,320,0.4f,"Record"));
				break;
			}
		case 5: 
			{
				return true;
				break;
			}
		case 6:
			{
				Logic::return_to_game();
				Logic::start_review();
				break;
			}
		case 7:
			{
				Logic::start_record();
				Logic::return_to_game();
				hgui->DelCtrl(7);
				hgui->AddCtrl(new hgeGUIMenuItem(8,mfnt,snd,516,320,0.4f,"Stop"));
				break;
			}
		case 8:
			{
				Logic::stop_record();
				Logic::return_to_game();
				hgui->DelCtrl(8);
				hgui->AddCtrl(new hgeGUIMenuItem(7,mfnt,snd,516,320,0.4f,"Record"));
				break;
			}
		case 9:
			{
				gui->reinitial();
				file->read_map(1);
				Logic::return_to_game();
				hgui->DelCtrl(9);
				hgui->DelCtrl(10);
				hgui->DelCtrl(11);
				hgui->DelCtrl(12);
				hgui->AddCtrl(new hgeGUIMenuItem(2,mfnt,snd,516,200,0.1f,"New game"));
				hgui->AddCtrl(new hgeGUIMenuItem(4,mfnt,snd,516,280,0.3f,"Load"));
				hgui->AddCtrl(new hgeGUIMenuItem(5,mfnt,snd,516,400,0.6f,"Exit"));
				hgui->AddCtrl(new hgeGUIMenuItem(1,mfnt,snd,516,160,0.0f,"Continue"));
				hgui->AddCtrl(new hgeGUIMenuItem(6,mfnt,snd,516,360,0.5f,"Video"));
				hgui->AddCtrl(new hgeGUIMenuItem(3,mfnt,snd,516,240,0.2f,"Save"));
				hgui->AddCtrl(new hgeGUIMenuItem(7,mfnt,snd,516,320,0.4f,"Record"));
				break;
			}
		case 10:
			{
				gui->reinitial();
				file->read_map(2);
				Logic::return_to_game();
				hgui->DelCtrl(9);
				hgui->DelCtrl(10);
				hgui->DelCtrl(11);
				hgui->DelCtrl(12);
				hgui->AddCtrl(new hgeGUIMenuItem(2,mfnt,snd,516,200,0.1f,"New game"));
				hgui->AddCtrl(new hgeGUIMenuItem(4,mfnt,snd,516,280,0.3f,"Load"));
				hgui->AddCtrl(new hgeGUIMenuItem(5,mfnt,snd,516,400,0.6f,"Exit"));
				hgui->AddCtrl(new hgeGUIMenuItem(1,mfnt,snd,516,160,0.0f,"Continue"));
				hgui->AddCtrl(new hgeGUIMenuItem(6,mfnt,snd,516,360,0.5f,"Video"));
				hgui->AddCtrl(new hgeGUIMenuItem(3,mfnt,snd,516,240,0.2f,"Save"));
				hgui->AddCtrl(new hgeGUIMenuItem(7,mfnt,snd,516,320,0.4f,"Record"));
				break;
			}
		case 11:
			{
				gui->reinitial();
				file->read_map(3);
				Logic::return_to_game();
				hgui->DelCtrl(9);
				hgui->DelCtrl(10);
				hgui->DelCtrl(11);
				hgui->DelCtrl(12);
				hgui->AddCtrl(new hgeGUIMenuItem(2,mfnt,snd,516,200,0.1f,"New game"));
				hgui->AddCtrl(new hgeGUIMenuItem(4,mfnt,snd,516,280,0.3f,"Load"));
				hgui->AddCtrl(new hgeGUIMenuItem(5,mfnt,snd,516,400,0.6f,"Exit"));
				hgui->AddCtrl(new hgeGUIMenuItem(1,mfnt,snd,516,160,0.0f,"Continue"));
				hgui->AddCtrl(new hgeGUIMenuItem(6,mfnt,snd,516,360,0.5f,"Video"));
				hgui->AddCtrl(new hgeGUIMenuItem(3,mfnt,snd,516,240,0.2f,"Save"));
				hgui->AddCtrl(new hgeGUIMenuItem(7,mfnt,snd,516,320,0.4f,"Record"));
				break;
			}
		case 12:
			{
				gui->reinitial();
				Logic::return_to_game();
				hgui->DelCtrl(9);
				hgui->DelCtrl(10);
				hgui->DelCtrl(11);
				hgui->DelCtrl(12);
				hgui->AddCtrl(new hgeGUIMenuItem(2,mfnt,snd,516,200,0.1f,"New game"));
				hgui->AddCtrl(new hgeGUIMenuItem(4,mfnt,snd,516,280,0.3f,"Load"));
				hgui->AddCtrl(new hgeGUIMenuItem(5,mfnt,snd,516,400,0.6f,"Exit"));
				hgui->AddCtrl(new hgeGUIMenuItem(1,mfnt,snd,516,160,0.0f,"Continue"));
				hgui->AddCtrl(new hgeGUIMenuItem(6,mfnt,snd,516,360,0.5f,"Video"));
				hgui->AddCtrl(new hgeGUIMenuItem(3,mfnt,snd,516,240,0.2f,"Save"));
				hgui->AddCtrl(new hgeGUIMenuItem(7,mfnt,snd,516,320,0.4f,"Record"));
				break;
			}
		}
		hgui->SetFocus(1);
		hgui->Enter();
	}
	else if(id) { lastid=id; hgui->Leave(); }

	// Here we update our background animation
	t+=dt;
	tx=50*cosf(t/60);
	ty=50*sinf(t/60);

	background.v[0].tx=0;        background.v[0].ty=0;
	background.v[1].tx=1;		 background.v[1].ty=0;
	background.v[2].tx=1;		 background.v[2].ty=1;
	background.v[3].tx=0;        background.v[3].ty=1;

	touch.v[0].tx=0;        touch.v[0].ty=0;
	touch.v[1].tx=1;		touch.v[1].ty=0;
	touch.v[2].tx=1;		touch.v[2].ty=1;
	touch.v[3].tx=0;        touch.v[3].ty=1;

	return false;
}

bool Menu::Render()
{
	gui->get_hge()->Gfx_BeginScene();
	gui->get_hge()->Gfx_RenderQuad(&background);
	if(!enter)
	{
		gui->get_hge()->Texture_Free(touch.tex);
		string s = "touch1.png";
		s[5] = ftoa((gui->get_count()->get_time()%64+32)/32)[0];
		touch.tex = gui->get_hge()->Texture_Load(s.c_str());
		gui->get_hge()->Gfx_RenderQuad(&touch);
	}
	else
		hgui->Render();
	//mfnt->SetColor(0xFFFFFFFF);
	//mfnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", gui->get_hge()->Timer_GetDelta(),gui->get_hge()->Timer_GetFPS());
	gui->get_hge()->Gfx_EndScene();

	return false;
}

void Menu::initial()
{
	enter = 0;

	background.tex=gui->get_hge()->Texture_Load("bp.jpg");
	touch.tex = gui->get_hge()->Texture_Load("touch1.png");
	tex=gui->get_hge()->Texture_Load("cursor.png");
	snd=gui->get_hge()->Effect_Load("menu.wav");
	if(!background.tex || !tex || !snd)
	{
		// If one of the data files is not found, display
		// an error message and shutdown.
		//MessageBox(NULL, "Can't load BG.PNG, CURSOR.PNG or MENU.WAV", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}

	// Set up the quad we will use for background animation
	background.blend=BLEND_ALPHABLEND | BLEND_COLORMUL | BLEND_NOZWRITE;
	touch.blend=BLEND_ALPHABLEND | BLEND_COLORMUL | BLEND_NOZWRITE;

	for(int i=0;i<4;i++)
	{
		// Set up z-coordinate of vertices
		background.v[i].z=0.5f;
		// Set up color. The format of DWORD col is 0xAARRGGBB
		background.v[i].col=0xFFFFFFFF;
		// Set up z-coordinate of vertices
		touch.v[i].z=1.0f;
		// Set up color. The format of DWORD col is 0xAARRGGBB
		touch.v[i].col=0xFFFFFFFF;
	}

	background.v[0].x=0; background.v[0].y=0; 
	background.v[1].x=1032; background.v[1].y=0; 
	background.v[2].x=1032; background.v[2].y=600; 
	background.v[3].x=0; background.v[3].y=600; 
	touch.v[0].x=0; touch.v[0].y=0; 
	touch.v[1].x=1032;touch.v[1].y=0; 
	touch.v[2].x=1032;touch.v[2].y=600; 
	touch.v[3].x=0;touch.v[3].y=600; 


	// Load the font, create the cursor sprite
	mfnt=new hgeFont("font1.fnt");
	spr=new hgeSprite(tex,0,0,32,32);

	// Create and initialize the GUI
	hgui = new hgeGUI();

	hgui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	hgui->SetCursor(spr);
	hgui->SetFocus(1);
	hgui->Enter();
}

Menu::~Menu()
{
	delete hgui;
	delete mfnt;
	delete spr;
	gui->get_hge()->Effect_Free(snd);
	gui->get_hge()->Texture_Free(tex);
	gui->get_hge()->Texture_Free(background.tex);
}