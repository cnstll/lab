//Light version of a atoi hexa

#define HEXA "0123456789ABCDEF"

int c_in_s(char c, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{	
		if (c == s[i])
			return (i);
		i++;
	}
	return (-1);
}

int		string_to_int(char *s)
{
	


}

int		*ft_atoa_hexa(char *s)
{
	int i;
	int ret;

	i = 0;
	while (c_in_s(s[i], HEXA) == 1)
	{
		if (c_in_s(s[i + 1], HEXA) > -1)
			ret = (ret + c_in_s(s[i], HEXA)
		else
	}
}
