/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:56:07 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/27 22:59:43 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*ptr;

	i = argc - 1;
	while (i > 0)
	{
		ptr = argv[i];
		while (*ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
