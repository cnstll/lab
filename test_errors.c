#include <errno.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int i;

	i = 0;
	while (i < 200)
		printf("%s\n", strerror(i++));
	return (0);
}
