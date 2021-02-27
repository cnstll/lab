#include <stdlib.h>
#include <stdio.h>

void exit_me(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			printf("%c\n", s[i++]);
		else
			exit(1);
	}
}

int main()
{
	char *s;

	s = NULL;
	s = malloc(sizeof(char) * 10);
	s = "Hello sia";
	exit_me(s);
	printf("After exit me");
}

//exit does not free allocated memory
//Function atexit() might be a way to correct this as
//this function can call a built in function to free mem
