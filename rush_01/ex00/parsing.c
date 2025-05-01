/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:19:51 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/29 22:17:47 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

int	is_valid_pair(char x, char y)
{
	int		i;
	char	*invalid[5];

	invalid[0] = "11";
	invalid[1] = "24";
	invalid[2] = "33";
	invalid[3] = "34";
	invalid[4] = "44";
	i = 0;
	while (i < 5)
	{
		if ((x == invalid[i][0] && y == invalid[i][1])
			|| (x == invalid[i][1] && y == invalid[i][0]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	validate_all_pairs(char *str)
{
	int	i;

	i = COL1UP;
	while (i < ROW1RIGHT)
	{
		if (is_valid_pair(str[i], str[i + 4]) == 0)
			return (FALSE);
		if (i == COL4UP)
			i = ROW1LEFT;
		else
			i++;
	}
	return (TRUE);
}

int	view_points_validation(char **argv, char result[16])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '4'))
			return (FALSE);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (FALSE);
		else if (j == 16)
			return (FALSE);
		else if (argv[1][i] >= '1' && argv[1][i] <= '4')
			result[j++] = argv[1][i];
		i++;
	}
	return (TRUE);
}

int	parse_main(char **argv, char *view_points)
{
	if (!view_points_validation(argv, view_points))
		return (FALSE);
	if (!validate_all_pairs(view_points))
		return (FALSE);
	return (TRUE);
}
