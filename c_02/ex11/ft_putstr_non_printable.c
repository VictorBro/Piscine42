/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:39:06 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/24 18:29:59 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_num_to_hex(char c)
{
	if (c < 10)
		c += '0';
	else
		c = c - 10 + 'a';
	return (c);
}

void	ft_printhex(char c)
{
	char	tmp;

	write(1, "\\", 1);
	tmp = c & 0xF0;
	tmp >>= 4;
	tmp &= 0x0F;
	tmp = ft_num_to_hex(tmp);
	write(1, &tmp, 1);
	tmp = c & 0x0F;
	tmp = ft_num_to_hex(tmp);
	write(1, &tmp, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (str && *str)
	{
		if (' ' <= *str && *str <= '~')
			write(1, str, 1);
		else
			ft_printhex(*str);
		str++;
	}
}
