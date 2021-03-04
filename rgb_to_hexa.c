#include <stdio.h>

unsigned long createRGB(int r, int g, int b)
{   
    return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

unsigned long bitwiseAND(int r)
{   
    return ((r & 0xff));
}

int main()
{
	printf("Hexa -- %lx\n", createRGB(15, 15, 15));
	printf("Dec -- %lu\n", createRGB(255, 255, 255));
	printf("Dec -- %lu\n", bitwiseAND(15));
	printf("Dec -- %lu\n", bitwiseAND(255));
	printf("Hex -- %lx\n", bitwiseAND(13));
	printf("Hex -- %lx\n", bitwiseAND(255));
	printf("0xff -- %d\n", 0xff);
	return (0);
}
