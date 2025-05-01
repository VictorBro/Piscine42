/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:34:44 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/29 22:21:37 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	convert(char **argv, char result[32])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '8'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		else if (j == 64)
			return (0);
		else if (argv[1][i] >= '1' && argv[1][i] <= '8')
			result[j++] = argv[1][i];
		i++;
	}
	return (1);
}

int	parse_main(char **argv, char *view_points)
{
	if (!convert(argv, view_points))
		return (0);
	return (1);
}
