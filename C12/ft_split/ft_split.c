/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkashi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:56 by tkashi            #+#    #+#             */
/*   Updated: 2023/09/21 16:49:33 by tkashi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strchr(char ch, char *str)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return (1);
		str++;
	}
	return (0);
}

int	ft_calc_size(char *str, char *charset)
{
	char	*prev;
	char	*curr;
	int		count;

	prev = NULL;
	curr = str;
	count = 0;
	while (*curr != '\0')
	{
		if (ft_strchr(*curr, charset))
		{
			if (prev != NULL && curr - prev > 1)
				count++;
			prev = curr;
		}
		curr++;
	}
	return (count);
}

void	ft_apply_split(char *str, char *charset, char **ret)
{
	char	*prev;
	char	*curr;
	int		i;

	prev = NULL;
	curr = str;
	i = 0;
	while (*curr != '\0')
	{
		if (ft_strchr(*curr, charset))
		{
			if (prev != NULL && curr - prev > 1)
			{
				ret[i] = prev + 1;
				i++;
			}
			prev = curr;
		}
		curr++;
	}
	ret[i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		size;

	size = ft_calc_size(str, charset);
	ret = (char **)malloc((size + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ft_apply_split(str, charset, ret);
	return (ret);
}
/*
int	main(int argc, char *argv[])
{
	char	**ret;

	if (argc == 3)
	{
		ret = ft_split(argv[1], argv[2]);
		while (*ret != NULL)
		{
			printf("%s\n", *ret);
			ret++;
		}
	}
	return (0);
}
*/
