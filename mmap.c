#include "mmap.h"
#include "init.h"

int *plcd = NULL;
extern int lcd_fd;

void open_mmap()
{
	
	plcd = mmap(NULL,480*800*4,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_SHARED,lcd_fd,0);
}

void close_mmap()
{

	munmap(plcd,480*800*4);
}

