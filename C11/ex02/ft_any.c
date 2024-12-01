#include <stdio.h>
int	ft_any(char **tab, int(*f)(char*))
{
	
	while (*tab != NULL)
	{
		if(f(*tab) != 0)
			return (1);
		tab++;
	}
	return (0);
	
}
/*
int search_for_p(char *str)
{
	while (*str != '\0')
	{
		if (*str == 'p')
			return (1);
		str++;
	}
	return (0);
}
int	main(int, char *argv[])
{
	int ret;
	ret = ft_any(argv, search_for_p);
	printf("the answer is %d\n", ret);
	return (0);
}*/
