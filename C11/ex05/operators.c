#include "operators.h"
#include "str_utils.h"

void	ft_mod(int x, int y)
{
	char	res[15];
	
	if (y == 0)
	{
		ft_print("Stop : modulo by zero");
		return ;
	}
	ft_itoa(x % y, res);
	ft_print(res);
}

void	ft_sum(int x, int y)
{
	char	res[15];

	ft_itoa(x + y, res);
	ft_print(res);
}

void	ft_sub(int x, int y)
{
	char	res[15];
	
	ft_itoa(x - y, res);
	ft_print(res);
}

void	ft_div(int x, int y)
{
	char	res[15];
	
	if (y == 0)
	{
		ft_print("Stop : division by zero");
		return ;
	}
	ft_itoa(x / y, res);
	ft_print(res);
}
