/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:35:14 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/29 22:18:02 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_valid_left(char *view_points, char grid[4][4], int row, int col)
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
	if (count > view_points[ROW1LEFT + row])
		return (FALSE);
	if (col == 3 && count != view_points[ROW1LEFT + row])
		return (FALSE);
	return (TRUE);
}

int	is_valid_up(char *view_points, char grid[4][4], int row, int col)
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
		return (FALSE);
	if (row == 3 && count != view_points[0 + col])
		return (FALSE);
	return (TRUE);
}

int	is_valid_right(char *view_points, char grid[4][4], int row)
{
	int		i;
	char	count;
	char	max_until_now;

	max_until_now = '0';
	count = '0';
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max_until_now)
		{
			count++;
			max_until_now = grid[row][i];
		}
		i--;
	}
	if (count != view_points[12 + row])
		return (FALSE);
	return (TRUE);
}

int	is_valid_down(char *view_points, char grid[4][4], int col)
{
	int		i;
	char	count;
	char	max_until_now;

	max_until_now = '0';
	count = '0';
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_until_now)
		{
			count++;
			max_until_now = grid[i][col];
		}
		i--;
	}
	if (count != view_points[4 + col])
		return (FALSE);
	return (TRUE);
}

int	is_valid(char *view_points, char grid[4][4], int row, int col)
{
	if (!is_valid_left(view_points, grid, row, col))
		return (FALSE);
	if (!is_valid_up(view_points, grid, row, col))
		return (FALSE);
	if (col == 3 && !is_valid_right(view_points, grid, row))
		return (FALSE);
	if (row == 3 && !is_valid_down(view_points, grid, col))
		return (FALSE);
	return (TRUE);
}