/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:33:22 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/10 23:41:14 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	process_line(t_info *info, char *line, int row_count)
{
	if (ft_strlen(line) != info->map_cols)
		return (0);
	if (!validate_line(line, info))
		return (0);
	if (row_count >= info->map_rows)
		return (0);
	ft_strncpy(info->map[row_count], line, info->map_cols);
	info->map[row_count][info->map_cols] = '\0';
	return (1);
}

int	read_map(t_info *info)
{
	int		row_count;
	char	line[BUFFER_SIZE];
	int		bytes_read;

	row_count = 0;
	bytes_read = allocate_and_check_first_line(info, line);
	if (bytes_read == 0)
		return (0);
	while (bytes_read > 0 && row_count < info->map_rows)
	{
		if (!process_line(info, line, row_count))
			break ;
		row_count++;
		bytes_read = read_line(info->fd, line, BUFFER_SIZE);
		if (bytes_read > 0 && row_count == info->map_rows)
			row_count++;
	}
	if (row_count != info->map_rows)
	{
		free_map(info);
		return (0);
	}
	return (1);
}

int	init_map(t_info *info, int idx, char *argv[])
{
	char	line[BUFFER_SIZE];

	if (info->fd == -1)
		info->fd = open(argv[idx], O_RDONLY);
	if (info->fd < 0)
		return (ft_error("map error\n", 0));
	if (!parse_first_line(line, BUFFER_SIZE, info) || !read_map(info))
	{
		if (info->fd > 0)
			close(info->fd);
		return (ft_error("map error\n", 0));
	}
	if (info->fd > 0)
		close(info->fd);
	return (1);
}

void	reset_info(t_info *info)
{
	info->map = NULL;
	info->map_rows = 0;
	info->map_cols = 0;
	info->empty = 0;
	info->obstacle = 0;
	info->full = 0;
	info->fd = -1;
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		i;

	reset_info(&info);
	if (argc == 1)
	{
		argc = 2;
		info.fd = 0;
	}
	i = 1;
	while (i < argc)
	{
		if (init_map(&info, i, argv))
		{
			if (find_and_fill_largest_square(&info))
				print_map(&info);
		}
		free_map(&info);
		reset_info(&info);
		if (i + 1 < argc)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
