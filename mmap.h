#ifndef __MMAP_H__
#define __MMAP_H__

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

extern void open_mmap();
extern void close_mmap();

#endif