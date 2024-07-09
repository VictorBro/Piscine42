/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:17:04 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/01 13:43:15 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;
	int		n;

	if (!src)
		return (NULL);
	n = ft_strlen(src);
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
		ret[i++] = *src++;
	ret[i] = '\0';
	return (ret);
}
