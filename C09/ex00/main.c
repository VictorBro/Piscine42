#include <stdio.h>
#include "libft.h"
#include <string.h>

int	main(void)
{
	char str1[] = "hello my name is tal";
	char str2[] = " victor is the king of hackers";
	int a = 75;
	int b = -30;
	char c = 'O';
	ft_putchar(c);
	printf("a is now  %d  and b is now %d \n ", a, b);
	ft_swap(&a, &b);
	printf("a is now  %d  and b is now %d \n ", a, b);
	ft_putstr(str1);
	printf("my string is %s \n ", str2);
	printf("the lenght of this string is  %d \n ", ft_strlen(str2));
	printf("the value of the comparison is %d \n", ft_strcmp(str1, str2));
	printf("this is the same value %d\n", strcmp(str1, str2));
	return (0);
}
