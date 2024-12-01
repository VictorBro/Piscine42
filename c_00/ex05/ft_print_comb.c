/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:13:35 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/19 17:24:07 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_result(int x, int y, int z)
{
	char	ch;

	if (x != 0 || y != 1 || z != 2)
		write(1, ", ", 2);
	ch = '0' + x;
	write(1, &ch, 1);
	ch = '0' + y;
	write(1, &ch, 1);
	ch = '0' + z;
	write(1, &ch, 1);
}

void	ft_print_comb(void)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	while (x <= 7)
	{
		y = x + 1;
		while (y <= 8)
		{
			z = y + 1;
			while (z <= 9)
			{
				ft_print_result(x, y, z);
				z++;
			}
			y++;
		}
		x++;
	}
}
