/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:12:26 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/10 21:02:22 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	validate_first_line(char *line, t_info *info)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	info->full = line[i - 1];
	info->obstacle = line[i - 2];
	info->empty = line[i - 3];
	if (info->empty == info->obstacle || info->empty == info->full
		|| info->obstacle == info->full)
		return (0);
	line[i - 3] = '\0';
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != '\0')
		return (0);
	info->map_rows = ft_atoi(line);
	if (info->map_rows <= 0)
		return (0);
	return (1);
}

int	parse_first_line(char *line, size_t line_size, t_info *info)
{
	int	bytes_read;

	bytes_read = read_line(info->fd, line, line_size);
	if (bytes_read <= 0 || !validate_first_line(line, info))
		return (0);
	return (1);
}

int	allocate_map(t_info *info)
{
	int	i;
	int	j;

	info->map = (char **)malloc(sizeof(char *) * info->map_rows);
	if (!info->map)
		return (ft_error("map error\n", 0));
	i = 0;
	while (i < info->map_rows)
	{
		info->map[i] = (char *)malloc(sizeof(char) * (info->map_cols + 1));
		if (!info->map[i])
		{
			j = 0;
			while (j < i)
			{
				free(info->map[j]);
				j++;
			}
			free(info->map);
			info->map = NULL;
			return (ft_error("map error\n", 0));
		}
		i++;
	}
	return (1);
}

int	allocate_and_check_first_line(t_info *info, char *line)
{
	int	bytes_read;

	bytes_read = read_line(info->fd, line, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		info->map_cols = ft_strlen(line);
		if (!allocate_map(info))
			return (0);
	}
	return (bytes_read);
}

int	validate_line(char *line, t_info *info)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != info->empty && line[i] != info->obstacle)
			return (0);
		i++;
	}
	return (1);
}
