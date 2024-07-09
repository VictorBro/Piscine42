/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:36:42 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/07 23:13:39 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_issep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strdup1(char *str)
{
	int		len;
	char	*ret;
	int		i;

	len = ft_strlen(str);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_count_substrs_with_alloc(char *str, char *charset)
{
	int		count;
	int		in_substr;
	char	**res;

	count = 0;
	in_substr = 0;
	while (*str)
	{
		if (!ft_issep(*str, charset) && !in_substr)
		{
			in_substr = 1;
			count++;
		}
		else if (ft_issep(*str, charset))
			in_substr = 0;
		str++;
	}
	res = (char **)malloc((count + 2) * sizeof(char *));
	if (res)
		res[0] = ft_strdup1("FREE");
	return (res);
}

char	*ft_strdup(char *start, char *end)
{
	int		len;
	char	*ret;
	int		i;

	len = end - start;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = start[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**res;
	char	*start;

	res = ft_count_substrs_with_alloc(str, charset);
	if (!res)
		return (NULL);
	i = 1;
	while (*str)
	{
		if (!ft_issep(*str, charset))
		{
			start = str;
			while (*str && !ft_issep(*str, charset))
				str++;
			res[i] = ft_strdup(start, str);
			if (!res[i])
				return (NULL);
			i++;
		}
		else
			str++;
	}
	res[i] = NULL;
	return (res);
}
