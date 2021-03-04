#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup_till_char(char *s, char c, int start)
{
	int		i;
	int		size;
	char	*dup;

	i = start;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	size = i - start;
	dup = (char *)(malloc(sizeof(char) * (size + 1)));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < size)
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}

int main()
{
	char *dup;

	dup = ft_strdup_till_char("hello\n all", '\n', 8);
	printf("'%s'\n", dup);
	free(dup);
	return (1);
}
