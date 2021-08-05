#include "event.h"

int touch_fd;
int x_read =-1;
int y_read =-1;

void open_event()
{
	//打开触摸屏文件
    
    touch_fd=open("/dev/input/event0",O_RDWR);
    if(touch_fd==-1)
    {
        printf("open error!!\n");
        return ;
    }
        
	
	struct input_event val;
	while(1)
	{
		read(touch_fd,&val,sizeof(val));
		// if(val.type == EV_KEY&&val.code == BTN_TOUCH)
		// {
		// 	if(val.value == 1)
		// 	//printf("press\n");
		// 	if(val.value == 0)
        //     //printf("songkai\n");
		// }
		if(val.type == EV_ABS)
		{
			if(val.code == ABS_X)
			x_read = val.value;
			if(val.code == ABS_Y)
			y_read = val.value;
			if(x_read>=0&&y_read>=0)
			{
				//printf("(%d,%d)\n",x_read,y_read);
                break;
			}
			
		
		}
		
	}
}

void close_event()
{
    close(touch_fd);
}