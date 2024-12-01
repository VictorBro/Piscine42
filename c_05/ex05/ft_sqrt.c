/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:46:41 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/26 22:53:20 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	x = 2;
	while (x * x < nb)
		x++;
	if (x * x > nb)
		return (0);
	return (x);
}
