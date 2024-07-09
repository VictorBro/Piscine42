/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:34:30 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/29 22:25:18 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid(char *view_points, char grid[8][8], int row, int col);
int		parse_main(char **argv, char *view_points);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init_grid(char grid[8][8])
{
	int	row;
	int	col;

	row = 0;
	while (row < 8)
	{
		col = 0;
		while (col < 8)
		{
			grid[row][col] = '0';
			col++;
		}
		row++;
	}
}

void	print_grid(char grid[8][8])
{
	int	row;
	int	col;

	row = 0;
	while (row < 8)
	{
		col = 0;
		ft_putchar(grid[row][col]);
		col++;
		while (col < 8)
		{
			ft_putchar(' ');
			ft_putchar(grid[row][col]);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	solve(char *view_points, char grid[8][8], int row, int col)
{
	char	box;
	int		next_row;
	int		next_col;

	box = '0';
	while (box++ < '8')
	{
		grid[row][col] = box;
		if (is_valid(view_points, grid, row, col))
		{
			next_row = row;
			next_col = col + 1;
			if (next_col == 8)
			{
				next_row = row + 1;
				if (next_row == 8)
					return (1);
				next_col = 0;
			}
			if (solve(view_points, grid, next_row, next_col))
				return (1);
		}
	}
	grid[row][col] = '0';
	return (0);
}

int	main(int argc, char **argv)
{
	char	view_points[32];
	char	grid[8][8];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_grid(grid);
	if (parse_main(argv, view_points) == 0
		|| !solve(view_points, grid, 0, 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_grid(grid);
}
