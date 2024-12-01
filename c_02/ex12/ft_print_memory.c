/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:06:43 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/24 19:06:49 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char *ptr, unsigned int size, unsigned int pos)
{
	unsigned int	j;
	char			*base;
	char			hex[2];

	base = "0123456789abcdef";
	j = 0;
	while (j < 16)
	{
		if (pos + j < size)
		{
			hex[0] = base[ptr[pos + j] / 16];
			hex[1] = base[ptr[pos + j] % 16];
			write(1, &hex, 2);
		}
		else
			write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
}

void	print_str(unsigned char *ptr, unsigned int size, unsigned int pos)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (pos + j < size)
		{
			if (ptr[pos + j] >= 32 && ptr[pos + j] <= 126)
				write(1, &ptr[pos + j], 1);
			else
				write(1, ".", 1);
		}
		j++;
	}
}

void	print_address(unsigned long addr)
{
	char	address[16];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		address[15 - i] = base[addr % 16];
		addr /= 16;
		i++;
	}
	write(1, address, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	if (size == 0)
		return (addr);
	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long)(ptr + i));
		print_hex(ptr, size, i);
		print_str(ptr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
