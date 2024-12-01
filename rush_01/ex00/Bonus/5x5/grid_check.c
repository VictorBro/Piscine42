/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:10:27 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/29 22:34:45 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_left(char *view_points, char grid[5][5], int row, int col)
{
	int		i;
	char	count;
	char	max_until_now;

	max_until_now = '0';
	count = '0';
	i = 0;
	while (i <= col)
	{
		if (i != col && grid[row][col] == grid[row][i])
			return (0);
		if (grid[row][i] > max_until_now)
		{
			count++;
			max_until_now = grid[row][i];
		}
		i++;
	}
	if (count > view_points[10 + row])
		return (0);
	if (col == 4 && count != view_points[10 + row])
		return (0);
	return (1);
}

int	is_valid_up(char *view_points, char grid[5][5], int row, int col)
{
	int		i;
	char	count;
	char	max_until_now;

	max_until_now = '0';
	count = '0';
	i = 0;
	while (i <= row)
	{
		if (i != row && grid[row][col] == grid[i][col])
			return (0);
		if (grid[i][col] > max_until_now)
		{
			count++;
			max_until_now = grid[i][col];
		}
		i++;
	}
	if (count > view_points[0 + col])
		return (0);
	if (row == 4 && count != view_points[0 + col])
		return (0);
	return (1);
}

int	is_valid_right(char *view_points, char grid[5][5], int row)
{
	int		i;
	char	count;
	char	max_until_now;

	max_until_now = '0';
	count = '0';
	i = 4;
	while (i >= 0)
	{
		if (grid[row][i] > max_until_now)
		{
			count++;
			max_until_now = grid[row][i];
		}
		i--;
	}
	if (count != view_points[15 + row])
		return (0);
	return (1);
}

int	is_valid_down(char *view_points, char grid[5][5], int col)
{
	int		i;
	char	count;
	char	max_until_now;

	max_until_now = '0';
	count = '0';
	i = 4;
	while (i >= 0)
	{
		if (grid[i][col] > max_until_now)
		{
			count++;
			max_until_now = grid[i][col];
		}
		i--;
	}
	if (count != view_points[5 + col])
		return (0);
	return (1);
}

int	is_valid(char *view_points, char grid[5][5], int row, int col)
{
	if (!is_valid_left(view_points, grid, row, col))
		return (0);
	if (!is_valid_up(view_points, grid, row, col))
		return (0);
	if (col == 4 && !is_valid_right(view_points, grid, row))
		return (0);
	if (row == 4 && !is_valid_down(view_points, grid, col))
		return (0);
	return (1);
}
