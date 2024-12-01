/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:54:51 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/20 21:59:07 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	*ptr1;
	int	*ptr2;

	if (size < 2)
		return ;
	ptr1 = tab;
	ptr2 = tab + size - 1;
	while (ptr1 < ptr2)
	{
		*ptr1 ^= *ptr2;
		*ptr2 ^= *ptr1;
		*ptr1 ^= *ptr2;
		ptr1++;
		ptr2--;
	}
}
