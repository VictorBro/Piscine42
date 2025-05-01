/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 23:09:27 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/02 23:28:54 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = ft_strdup(av[i]);
		if (ret[i].copy == NULL)
		{
			i--;
			while (i >= 0)
				free(ret[i--].copy);
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
