/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:36:40 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/27 21:16:14 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_valid(int col, int *board)
{
	int	x;
	int	i;

	i = 0;
	while (i < col)
	{
		x = board[i] - board[col];
		if (x < 0)
			x = -x;
		if (board[col] == board[i] || col - i == x)
			return (0);
		i++;
	}
	return (1);
}

void	ft_helper(int col, int *board, int	*count)
{
	int	i;

	if (col == 10)
	{
		(*count)++;
		ft_print_solution(board);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		board[col] = i;
		if (ft_is_valid(col, board))
			ft_helper(col + 1, board, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	ft_helper(0, board, &count);
	return (count);
}
