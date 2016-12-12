#include"hge.h"
#include"GUI.h"
#include"file.h"

using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	file = new File;
	gui = new GUI;
	delete gui;
	delete file;
	return 0;
}