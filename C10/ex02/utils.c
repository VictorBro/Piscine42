#include "utils.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}


void	ft_puterr(void)
{
	char	*err;

	err = strerror(errno);
	while (*err != '\0')
	{
		write(1, err, 1);
		err++;
	}
	write(1, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
