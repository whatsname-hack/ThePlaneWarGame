#ifndef __BMP_H__
#define __BMP_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <math.h>
#include <stdlib.h>

void draw_point(int x,int y,int color);
extern void show_bmp (char * pathname ,int x ,int y);
extern void close_bmp();

#endif