int		c_in_s(char c, char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		if (s[i++] == c)
			return (1);
	return (0);
}

int main()
{
	c_in_s('x', " 1");
	return (1);
}

