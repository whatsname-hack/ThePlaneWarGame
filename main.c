#include "init.h"
#include "mmap.h"
#include "bmp.h"
#include "event.h"
#include "planemove.h"

extern int x_read;
extern int y_read;

void* music()
{
	system("madplay ./plane_war_music_bg.mp3 &");
}


int main()
{
	pthread_t music_th;
	// int i=0;
	// char *bmp[5]={"./1.bmp","./3.bmp","./4.bmp","./5.bmp","./8.bmp"};
	pthread_create(&music_th,NULL,music,NULL);//背景音乐线程
	open_lcd();
	open_mmap();
	
	show_bmp("homePage_800x480_bg.bmp",0,0);
	show_bmp("btn_60x163_gameStart.bmp",370,160);//“开始游戏”的按钮范围x0 = 370,x1 = 430;y0 = 160,y1 = 323;

	open_event();

	
	if(x_read >= 0 && x_read < 1024 && y_read >= 0 && y_read < 600)
	{
		show_bmp("./gamePage_800x480_bg.bmp",0,0);//显示游戏界面背景图
		show_bmp("./plane_57x57_hero.bmp",730,240);//显示飞机图片
		planemove();
	}
	
	close_event();
	close_mmap();
	close_lcd();
	return 0;
}