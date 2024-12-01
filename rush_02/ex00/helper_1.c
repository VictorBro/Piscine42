/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:46:13 by mbendidi          #+#    #+#             */
/*   Updated: 2024/07/06 19:15:31 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*trim_leading(char *str)
{
	char	*prev;

	str = ft_trim(str);
	prev = str;
	while (*str == '0')
	{
		prev = str;
		str++;
	}
	if (*str == '\0' && *prev == '0')
		return (prev);
	else if (*prev == '0')
		prev++;
	return (prev);
}

int	init_info(t_info *info, char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		info->until19[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		info->tens[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 13)
		info->level[i++] = NULL;
	info->str = trim_leading(str);
	i = 0;
	while (info->str[i])
		if (info->str[i] < '0' || info->str[i++] > '9')
			return (0);
	return (1);
}

void	init_words(char *words[])
{
	int	i;

	i = 0;
	while (i < 255)
	{
		words[i] = NULL;
		i++;
	}
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		free(info->until19[i]);
		info->until19[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		free(info->tens[i]);
		info->tens[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 13)
	{
		free(info->level[i]);
		info->level[i] = NULL;
		i++;
	}
}

void	free_words(char *words[], int word_count)
{
	word_count--;
	while (word_count >= 0)
	{
		free(words[word_count]);
		words[word_count] = NULL;
		word_count--;
	}
}
