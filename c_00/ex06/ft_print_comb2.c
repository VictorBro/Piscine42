/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:50:32 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/19 23:34:14 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int x, int y, int z, int w)
{
	char	ch;

	if (x != 0 || y != 0 || z != 0 || w != 1)
		write(1, ", ", 2);
	ch = '0' + x;
	write(1, &ch, 1);
	ch = '0' + y;
	write(1, &ch, 1);
	write(1, " ", 1);
	ch = '0' + z;
	write(1, &ch, 1);
	ch = '0' + w;
	write(1, &ch, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_print(x / 10, x % 10, y / 10, y % 10);
			y++;
		}
		x++;
	}
}
