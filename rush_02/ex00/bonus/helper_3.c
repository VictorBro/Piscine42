/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:58:33 by mbendidi          #+#    #+#             */
/*   Updated: 2024/07/07 21:19:31 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_trim(char *str)
{
	int	i;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	i = 0;
	while (str && str[i])
		i++;
	while (i - 1 >= 0 && (str[i - 1] == ' '
			|| (str[i - 1] >= 9 && str[i - 1] <= 13)))
		i--;
	str[i] = '\0';
	return (str);
}

int	add_to_until19(char *buffer, char *until19[])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (buffer[i] != '\0' && buffer[i] >= '0' && buffer[i] <= '9')
	{
		n = n * 10 + buffer[i] - '0';
		i++;
	}
	if (until19[n] != NULL)
		return (0);
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '\0' || buffer[i++] != ':')
		return (0);
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '\0')
		return (0);
	until19[n] = (char *)malloc((ft_strlen(ft_trim(&buffer[i])) + 1));
	if (until19[n] == NULL)
		return (0);
	ft_strcpy(until19[n], &buffer[i]);
	return (1);
}

int	add_to_tens(char *buffer, char *tens[])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (buffer[i] != '\0' && buffer[i] >= '0' && buffer[i] <= '9')
	{
		n = n * 10 + buffer[i] - '0';
		i++;
	}
	if (tens[n / 10] != NULL)
		return (0);
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '\0' || buffer[i++] != ':')
		return (0);
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '\0')
		return (0);
	tens[n / 10] = (char *)malloc((ft_strlen(ft_trim(&buffer[i])) + 1));
	if (tens[n / 10] == NULL)
		return (0);
	ft_strcpy(tens[n / 10], &buffer[i]);
	return (1);
}

int	add_to_level(char *buffer, char *level[])
{
	int	i;
	int	n;

	i = 1;
	while (buffer[i] != '\0' && buffer[i] == '0')
		i++;
	n = i;
	if ((buffer[i] != ' ' && buffer[i] != ':') || (n != 3 && (n - 1) % 3 != 0))
		return (0);
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '\0' || buffer[i] != ':')
		return (0);
	i++;
	while (buffer[i] != '\0' && buffer[i] == ' ')
		i++;
	if (buffer[i] == '\0')
		return (0);
	n = (n - 1) / 3;
	level[n] = (char *)malloc((ft_strlen(ft_trim(&buffer[i])) + 1));
	if (level[n] == NULL)
		return (0);
	ft_strcpy(level[n], &buffer[i]);
	return (1);
}

int	ft_add_word(char **words, int *word_count, char **dict, int idx)
{
	words[*word_count] = (char *)malloc(ft_strlen(dict[idx]) + 1);
	if (words[*word_count] == NULL)
	{
		free_words(words, *word_count);
		return (0);
	}
	ft_strcpy(words[*word_count], dict[idx]);
	(*word_count)++;
	return (1);
}
