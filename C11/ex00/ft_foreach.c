#include <stdio.h>

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;
	
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

void	ft_calc(int x)
{
	printf("the answer is %d\n", x * 2 - 4);
}

int	main(void)
{
	int	tab[] = {12, 4, 2, -8};

	ft_foreach(tab, sizeof(tab) / sizeof(tab[0]), ft_calc);
}
