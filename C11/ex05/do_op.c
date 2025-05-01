#include "do_op.h"
#include "str_utils.h"
#include "operators.h"
#include <unistd.h>

int	op_to_idx(char op)
{
	return (op - '%');
}

void	init_ops(void(*ops[MAX_OPS])(int, int))
{
	int	i;
	
	i = 0;
	while(i < MAX_OPS)
	{
		ops[i] = NULL;
		i++;
	}
	ops[op_to_idx('%')] = ft_mod;
	ops[op_to_idx('+')] = ft_sum;
	ops[op_to_idx('-')] = ft_sub;
	ops[op_to_idx('/')] = ft_div;
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	op_idx;
	void(*ops[MAX_OPS])(int, int);
	
	init_ops(ops);
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	op_idx = op_to_idx(argv[2][0]);
	if (op_idx < 0 || op_idx >= MAX_OPS ||
		ops[op_idx] == NULL || argv[2][1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	ops[op_idx](x, y);
	return (0);
}
