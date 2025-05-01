#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if(f(tab[i], tab[i + 1]) > 0 ) 
			return (0);
		i++;
	}
	return (1);
}
/*
int	check_if_sort(int x, int y)
{
	if (x < y)
		return (-1);
	else if (x == y)
		return (0);
	else
		return (1);
}

int	main(void)
{
	int tab[] = {0, 1, 5, 20, 30, -50};
	int tab1[] = {-111, -90, -72, -50, -10};
	int size = sizeof(tab) / sizeof(tab[0]);
	int size1 = sizeof(tab1) / sizeof(tab1[0]);
	int ret = ft_is_sort(tab, size, check_if_sort);
	if (ret == 1)
		printf("the answer if tab is sort is yes %d\n", ret);
	else if (ret == 0)
		printf("the answer if tab is sort is no  %d\n", ret);	
	ret = ft_is_sort(tab1, size1, check_if_sort);
	if (ret == 0)
		printf("the answer if tab1 is sort is no %d\n", ret);
	else if (ret == 1)
		printf("the answer if tab1 is sort is yes %d\n", ret);
	return (0);

}*/
