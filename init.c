#include "init.h"

int lcd_fd;

void open_lcd()
{
	
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
		{
			printf("open lcd error!!\n");
			return ;
		}
}

void close_lcd()
{
	close(lcd_fd);
}

