#include <stdlib.h>
#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ret;
	int	i;

	ret = (int*)malloc(sizeof(int) * length);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ret[i] = f(tab[i]);
		i++;
	}
	return (ret);
}
/*
int	ft_calc(int x)
{
	int ret;
	ret = x * 2 - 5;
	return (ret);
}

int	main(void)
{
	int	tab[] = {12, 4, 2, -8};
	int	*x;
	int resett;
	int	size;

	size = sizeof(tab) / sizeof(tab[0]);

	x = ft_map(tab, size, ft_calc);
	resett = 0;
	while (resett < size)
	{
		printf("%d \n", x[resett]);
		resett++;
	}
	free(x);
	return (0);
}*/

