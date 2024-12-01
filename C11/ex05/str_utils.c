#include "str_utils.h"
#include <unistd.h>

void	ft_strcpy(char *src, char *dst)
{
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

int	is_known(int num, char *str)
{
	if (num == -2147483648)
	{
		ft_strcpy("-2147483648", str);
		return (1);
	} 
	if (num == 0)
	{
		ft_strcpy("0", str);
		return (1);
	}
	return (0);
}

void	ft_itoa(int num, char *str)
{
	int	i;
	int	j;
	
	if (is_known(num, str))
		return ;
	i = 0;
	j = 0;
	if (num < 0)
	{
		num *= -1;
		str[i++] = '-';
		j++;
	}
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	str[i--] = '\0';
	while (j < i)
	{
		str[j] ^= str[i];
		str[i] ^= str[j];
		str[j++] ^= str[i--];
	}
}

void	ft_print(char *str)
{
	while(*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	counter;
	
	while (*str == ' ' || *str == '\t')
		str++;
	counter = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			counter++;
		str++;
	}
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (ret == 214748364 && *str == '8' && counter % 2 == 1)
			return (-2147483648);
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (counter % 2 == 1)
		ret = ret * -1;
	return (ret);
}




