/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:13:05 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/26 23:35:37 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprime(int nb)
{
	int	x;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	x = 3;
	while (x * x <= nb)
	{
		if (nb % x == 0)
			return (0);
		x += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	prime;

	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	prime = nb;
	if (prime % 2 == 0)
		prime++;
	while (1)
	{
		if ((prime - 1) % 6 == 0 || (prime + 1) % 6 == 0)
		{
			if (ft_isprime(prime))
				break ;
		}
		prime += 2;
	}
	return (prime);
}
