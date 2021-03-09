#include <stdio.h>

unsigned long createRGB(int r, int g, int b)
{   
    return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int deconstruct_hexa(int color, char rgb)
{
	if (rgb == 'R')
		return ((color & 0xff0000) >> 16);
	if (rgb == 'G')
		return ((color & 0x00ff00) >> 8);
	if (rgb == 'B')
		return (color & 0x0000ff);
	return (-1);
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
	printf("R -- %d\n", deconstruct_hexa(0xff0ff0, 'R'));
	printf("G -- %d\n", deconstruct_hexa(0xff0ff0, 'G'));
	printf("B -- %d\n", deconstruct_hexa(0xff0ff0, 'B'));
	printf("R -- %d\n", deconstruct_hexa(0xc00f80, 'R'));
	printf("G -- %d\n", deconstruct_hexa(0xc00f80, 'G'));
	printf("B -- %d\n", deconstruct_hexa(0xc00f80, 'B'));
	return (0);
}
