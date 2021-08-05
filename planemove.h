#ifndef __PLANEMOVE_H__
#define __PLANEMOVE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <math.h>
#include <stdlib.h>
#include <linux/input.h>
#include <pthread.h>

int plane_x;
int plane_y;



int enemyplane_Y;
int enemyplane_X;

extern void planemove();
#endif