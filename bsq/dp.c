/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:19:55 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/10 21:02:35 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(t_info *info, t_rect *rect)
{
	int	i;
	int	j;

	i = rect->row - rect->size + 1;
	while (i <= rect->row)
	{
		j = rect->col - rect->size + 1;
		while (j <= rect->col)
		{
			info->map[i][j] = info->full;
			j++;
		}
		i++;
	}
}

void	prep_dp_for_next_row(t_info *info, int *dp[2], t_rect *rect, int row)
{
	int	col;

	col = 0;
	while (col < info->map_cols)
	{
		dp[0][col] = dp[1][col];
		if (rect->size < dp[0][col])
			*rect = (t_rect){dp[0][col], row, col};
		col++;
	}
}

void	apply_dp(t_info *info, int *dp[2], t_rect *rect)
{
	int	row;
	int	col;

	row = 1;
	while (row < info->map_rows)
	{
		dp[1][0] = 0;
		if (info->map[row][0] == info->empty)
			dp[1][0] = 1;
		col = 1;
		while (col < info->map_cols)
		{
			dp[1][col] = 0;
			if (info->map[row][col] == info->empty)
				dp[1][col] = 1 + ft_min(dp[0][col - 1],
						dp[0][col], dp[1][col - 1]);
			col++;
		}
		prep_dp_for_next_row(info, dp, rect, row);
		row++;
	}
}

void	init_dp(t_info *info, int *dp[2], t_rect *rect)
{
	int	col;

	col = 0;
	while (col < info->map_cols)
	{
		dp[0][col] = 0;
		if (info->map[0][col] == info->empty)
		{
			dp[0][col] = 1;
			if (rect->size < 1)
				*rect = (t_rect){1, 0, col};
		}
		col++;
	}
}

int	find_and_fill_largest_square(t_info *info)
{
	int		*dp[2];
	t_rect	rect;

	rect = (t_rect){0, -1, -1};
	dp[0] = (int *)malloc(sizeof(int) * info->map_cols);
	if (!dp[0])
		return (ft_error("map error\n", 0));
	dp[1] = (int *)malloc(sizeof(int) * info->map_cols);
	if (!dp[1])
	{
		free(dp[0]);
		return (ft_error("map error\n", 0));
	}
	init_dp(info, dp, &rect);
	apply_dp(info, dp, &rect);
	free(dp[0]);
	free(dp[1]);
	fill_square(info, &rect);
	return (1);
}
