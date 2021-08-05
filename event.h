#ifndef __EVENT_H__
#define __EVENT_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <math.h>
#include <stdlib.h>
#include <linux/input.h>

extern void open_event();

extern void close_event();

#endif

