/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:28:56 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/01 13:41:23 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ret;

	if (min >= max)
		return (NULL);
	ret = (int *)malloc((max - min) * sizeof(int));
	if (!ret)
		return (NULL);
	i = min;
	while (i < max)
	{
		ret[i - min] = i;
		i++;
	}
	return (ret);
}
