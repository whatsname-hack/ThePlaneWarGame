#include "bmp.h"
#include "mmap.h"

extern int * plcd;
int bmp_fd;

void draw_point(int x,int y,int color)
{
	if(x>=0 && x<800 && y>=0 && y<480 )
	{
		*(plcd+800*y+x) = color ;
	}
}
/*
函数功能：在屏幕的任意一个位置  显示任意一张  任意大小的bmp图片 
函数参数： 
		@pathname : 要显示的图片 的路径名 
		@x ： 在屏幕X轴值为x的地方开始显示
		@y ：  在屏幕Y轴值为y的地方开始显示
*/
void show_bmp (char * pathname ,int x ,int y)
{
	bmp_fd = open(pathname,O_RDONLY);
	if(bmp_fd == -1)
	{
		perror("open error\n");
		return ;
	}
	
	int width,height;
	short depth;
	unsigned char buf[4] ;
	//读取宽度
	lseek(bmp_fd,0x12,SEEK_SET);
	read(bmp_fd,buf,4);
	width = buf[3]<<24 | buf[2]<< 16 | buf[1] << 8 | buf[0];
	//读取高度
	read(bmp_fd,buf,4);
	height  = buf[3]<<24 | buf[2]<< 16 | buf[1] << 8 | buf[0];
	//读取色深
	lseek(bmp_fd,0x1c,SEEK_SET);
	read(bmp_fd,buf,2);
	depth = buf[1] << 8  | buf[0];

	//像素数组 
	int line_valid_bytes = abs(width) * depth / 8 ; //一行本有的有效字节
	int laizi=0;//填充字节
	if( (line_valid_bytes % 4) !=0   )
	{
		laizi =  4 - line_valid_bytes%4;
	}
	int line_bytes = line_valid_bytes  +  laizi ;//一行所有的字节数
	
	int total_bytes = line_bytes * abs(height) ; //整个像素数组的大小
	
	unsigned char * p1  = malloc(total_bytes);
	
	lseek(bmp_fd,54,SEEK_SET);
	read(bmp_fd,p1,total_bytes);
	
	//调用draw_point 函数 。
	unsigned char a ,r ,g, b ;
	int i = 0;//用来做指针运动的
	int x0=0,y0=0; //用来循环计数
	int color ;
	for(y0=0;y0<abs(height);y0++)//画满每一列
	{
		for(x0=0;x0<abs(width);x0++)//画满每一行
		{
			//现在开始一个字节一个字节写入颜色
			// i++  先用后加     
			// ++i  先加后用
			b = p1[i++];
			g = p1[i++];
			r = p1[i++];
			if(depth == 32)
			{
				a=p1[i++];
			}
			if(depth == 24)
			{
				a = 0;
			}
			color = a << 24 | r << 16 | g << 8 | b ;
			draw_point(width>0?x+x0:abs(width)+x-1-x0,
					height>0? y+height-1-y0 : y+y0,color);
			
			
		}
		i = i +laizi ;//每一行后面的癞子数 跳过去。
			
	}
}

void close_bmp()
{
    close(bmp_fd);
}