/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:52:25 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/01 21:10:58 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str && *str)
	{
		n++;
		str++;
	}
	return (n);
}

void	ft_copy(char *dst, int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	i = 0;
	while (i < size)
	{
		str = strs[i];
		while (*str)
			*dst++ = *str++;
		if (i < size - 1)
		{
			str = sep;
			while (*str)
				*dst++ = *str++;
		}
		i++;
	}
	*dst = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (size == 0)
	{
		ret = (char *)malloc((1) * sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	while (i < size)
	{
		n += ft_strlen(strs[i]);
		i++;
	}
	n += ft_strlen(sep) * (size - 1);
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_copy(ret, size, strs, sep);
	return (ret);
}
