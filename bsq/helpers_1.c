/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:39:52 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/09 21:39:56 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	word_count(char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!(*str == sep) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

char	*word_dup(char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char sep)
{
	char	**result;
	int		i;
	int		word_len;
	int		words;

	words = word_count(str, sep);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && (*str == sep))
			str++;
		word_len = 0;
		while (str[word_len] && !(str[word_len] == sep))
			word_len++;
		if (word_len > 0)
		{
			result[i] = word_dup(str, word_len);
			if (!result[i])
			{
				while (i > 0)
					free(result[--i]);
				free(result);
				return (NULL);
			}
			i++;
			str += word_len;
		}
	}
	result[i] = NULL;
	return (result);
}
