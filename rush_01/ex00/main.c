/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:17:55 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/29 22:17:54 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init_grid(char grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = '0';
			col++;
		}
		row++;
	}
}

void	print_grid(char grid[4][4])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		ft_putchar(grid[row][0]);
		ft_putchar(' ');
		ft_putchar(grid[row][1]);
		ft_putchar(' ');
		ft_putchar(grid[row][2]);
		ft_putchar(' ');
		ft_putchar(grid[row][3]);
		write(1, "\n", 1);
		row++;
	}
}

int	solve(char *view_points, char grid[4][4], int row, int col)
{
	char	box;
	int		next_row;
	int		next_col;

	box = '0';
	while (box++ < '4')
	{
		grid[row][col] = box;
		if (is_valid(view_points, grid, row, col))
		{
			next_row = row;
			next_col = col + 1;
			if (next_col == 4)
			{
				next_row = row + 1;
				if (next_row == 4)
					return (TRUE);
				next_col = 0;
			}
			if (solve(view_points, grid, next_row, next_col))
				return (TRUE);
		}
	}
	grid[row][col] = '0';
	return (FALSE);
}

int	main(int argc, char **argv)
{
	char	view_points[16];
	char	grid[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (ERROR);
	}
	init_grid(grid);
	if (!parse_main(argv, view_points) || !solve(view_points, grid, 0, 0))
	{
		write(1, "Error\n", 6);
		return (ERROR);
	}
	print_grid(grid);
	return (OK);
}
