/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:12:07 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/10 21:07:08 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_rows)
	{
		write(1, info->map[i], info->map_cols);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(t_info *info)
{
	int	i;

	i = 0;
	if (info->map)
	{
		while (i < info->map_rows)
		{
			if (info->map[i])
				free(info->map[i]);
			i++;
		}
		free(info->map);
		info->map = NULL;
	}
}

int	read_char(int fd, char *ch)
{
	int	bytes_read;

	bytes_read = read(fd, ch, 1);
	if (bytes_read < 0)
		return (-1);
	return (bytes_read);
}

int	process_char(char *line, size_t *i, char c, size_t line_size)
{
	line[*i] = c;
	(*i)++;
	if (c == '\n' || *i == line_size - 1)
		return (0);
	return (1);
}

int	read_line(int fd, char *line, size_t line_size)
{
	char	ch;
	int		bytes_read;
	size_t	i;

	i = 0;
	while (i < line_size - 1)
	{
		bytes_read = read_char(fd, &ch);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (0);
		if (!process_char(line, &i, ch, line_size))
			break ;
	}
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		line[i - 1] = '\0';
	return (i);
}
