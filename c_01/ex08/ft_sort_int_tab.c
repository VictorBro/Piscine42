/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:02:17 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/20 22:31:34 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	end;
	int	start;

	end = size - 1;
	while (end > 0)
	{
		start = 1;
		while (start <= end)
		{
			if (tab[start - 1] > tab[start])
			{
				tab[start - 1] ^= tab[start];
				tab[start] ^= tab[start - 1];
				tab[start - 1] ^= tab[start];
			}
			start++;
		}
		end--;
	}
}
