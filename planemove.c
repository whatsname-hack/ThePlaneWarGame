#include "planemove.h"
#include "event.h"
#include "bmp.h"

int indexs = 0;
char *score[4]={"./1.bmp","./2.bmp","./3.bmp","./4.bmp"};

extern int x_read;
extern int y_read;


void* enemyplane()//敌机在一固定区域随机出现
{
	int i;
	//extern int index;
	int num = 0;
	int x;
	srandom(time(NULL));
	for(num = 0; num < 4; num++)
	{
		enemyplane_Y = random() % 301;
		enemyplane_X = random() % 257;
		
		
		for(i = 0; i< 200; i++)
		{
			x=enemyplane_X + 5*i;
			show_bmp("./gamePage_800x480_bg.bmp",0,0);
			close_bmp();
			show_bmp("./plane_60x60_enemy.bmp",enemyplane_X + 5*i,enemyplane_Y);
			close_bmp();
			show_bmp("./jiguang_730x28.bmp",plane_x-730,plane_y+14);//激光炮
			close_bmp();
			show_bmp("./plane_57x57_hero.bmp",plane_x,plane_y);
			close_bmp();
			show_bmp(score[indexs],0,410);
			close_bmp();
			if(enemyplane_Y>=plane_y-10 && enemyplane_Y<=plane_y+10)//当我方飞机击中敌机，敌机就消失
			{
				show_bmp("./gamePage_800x480_bg.bmp",0,0);
				close_bmp();
				show_bmp("./jiguang_730x28.bmp",plane_x-730,plane_y+14);//激光
				close_bmp();
				show_bmp("./plane_57x57_hero.bmp",plane_x,plane_y);
				close_bmp();
				indexs++;
				sleep(0.5);
				break;
				
			}
			if(x>730)//敌机超过我方飞机区域就游戏结束
			{
				show_bmp("./gameover.bmp",160,0);
				close_bmp();
				return 0;
			}
			
		}
		
		sleep(1);
	}	
}



void planemove()//我方飞机
{
    plane_x=730;
    //pthread_t th;
	pthread_t th1;
	int i=0;
    //pthread_create(&th,NULL,bullet,NULL);
	pthread_create(&th1,NULL,enemyplane,NULL);
    while (1)
	{
		open_event();
        plane_y=y_read*480/600;
		show_bmp("./gamePage_800x480_bg.bmp",0,0);
		close_bmp();
		show_bmp("./jiguang_730x28.bmp",plane_x-730,plane_y+14);//激光
		close_bmp();
		show_bmp("./plane_57x57_hero.bmp",plane_x,plane_y);
		close_bmp();	

		
		close_event();
		
	}
	
}

