#include <stdio.h>
int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	counter;
	int	x;
	
	counter = 0;
	x = 0;
	while (x < length)
	{
		if (f(tab[x]) != 0)
			counter++;
		x++;
	}
	return (counter);
}

int	count_x(char *str)
{
	while (*str != '\0')
	{
		if (*str == 'x')
			return (1);
		str++;
	}
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	int	ret;
	ret = ft_count_if(argv, argc, count_x);
	printf("the counter of x in each strings in total is %d\n", ret);
	return (0);
}*/
