/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:47:45 by mbendidi          #+#    #+#             */
/*   Updated: 2024/07/06 17:58:02 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	while (src && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}

void	ft_putstr(char *str)
{
	while (str && *str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_words(char *words[], int word_count)
{
	word_count--;
	while (word_count >= 0)
	{
		ft_putstr(words[word_count]);
		if (word_count > 0)
			ft_putstr(" ");
		else
			ft_putstr("\n");
		word_count--;
	}
}

int	read_line(char *buffer, int n, int fd)
{
	char	ch;
	int		bytes_read;
	int		i;

	i = 0;
	while (i < n)
	{
		bytes_read = read(fd, &ch, 1);
		if (bytes_read > 0)
		{
			buffer[i] = ch;
			i++;
			if (ch == '\n')
				break ;
		}
		else
			break ;
	}
	if (i == n)
		return (-1);
	buffer[i] = '\0';
	if (bytes_read < 0)
		return (bytes_read);
	return (i);
}
