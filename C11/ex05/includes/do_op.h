#ifndef DO_OP_H
# define DO_OP_H
# define MAX_OPS 11

int	op_to_idx(char op);
void	init_ops(void(*ops[MAX_OPS])(int, int));
#endif
