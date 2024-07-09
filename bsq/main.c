/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:33:22 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/09 23:17:51 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(t_info *info)
{
	int	i;

	i = 0;
	if (info->map) {
		while (i < info->map_rows) {
			if (info->map[i])
				free(info->map[i]);
			i++;
		}
		free(info->map);
		info->map = NULL;
	}
}

int	read_line(int fd, char *line, size_t line_size)
{
	char	ch;
	int		bytes_read;
	size_t	i;

	i = 0;
	while (i < line_size - 1)
	{
		bytes_read = read(fd, &ch, 1);
		if (bytes_read > 0)
		{
			if (ch == '\r')
				continue ;
			line[i] = ch;
			i++;
			if (ch == '\n')
				break;
		}
		else if (bytes_read < 0)
			return (bytes_read);
		else
			break;
	}
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		line[i - 1] = '\0';
	if (bytes_read < 0)
		return (bytes_read);
	return (i);
}

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

int	parse_first_line(int fd, char *line, size_t line_size, t_info *info)
{
	int	bytes_read;

	bytes_read = read_line(fd, line, line_size);
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
		return (ft_error("malloc error\n", 0));
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
			return (ft_error("malloc error\n", 0));
		}
		i++;
	}
	return (1);
}

int	read_map(int fd, t_info *info)
{
	int		i;
	int		row_count;
	char	line[BUFFER_SIZE];
	int		bytes_read;

	row_count = 0;
	bytes_read = read_line(fd, line, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		info->map_cols = ft_strlen(line);
		if (!allocate_map(info))
			return (0);
	}

	while (bytes_read > 0)
	{
		if (ft_strlen(line) != info->map_cols)
		{
			free_map(info);
			return (0);
		}
		i = 0;
		while (line[i] != '\0') {
			if (line[i] != info->empty && line[i] != info->obstacle && line[i] != info->full)
			{
				free_map(info);
				return (0);
			}
			i++;
		}
		if (row_count >= info->map_rows)
		{
			free_map(info);
			return (0);
		}
		ft_strncpy(info->map[row_count], line, info->map_cols);
		info->map[row_count][info->map_cols] = '\0';
		row_count++;
		bytes_read = read_line(fd, line, BUFFER_SIZE);
	}
	if (row_count != info->map_rows)
	{
		free_map(info);
		return (0);
	}
	return (1);
}

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	fill_square(t_info *info, int row, int col, int size)
{
	int i;
	int j;

	i = row - size + 1;
	while (i <= row)
	{
		j = col - size + 1;
		while (j <= col)
		{
			info->map[i][j] = info->full;
			j++;
		}
		i++;
	}
}

int	find_largest_square(t_info *info)
{
	int	row;
	int	col;
	int	*dp[2];
	int	max_size;
	int	max_row;
	int	max_col;

	max_size = 0;
	max_row = -1;
	max_col = -1;
	dp[0] = (int *)malloc(sizeof(int) * info->map_cols);
	dp[1] = (int *)malloc(sizeof(int) * info->map_cols);
	if (!dp[0] || !dp[1])
		return (ft_error("malloc error\n", 0));
	col = 0;
	while (col < info->map_cols)
	{
		dp[0][col] = 0;
		if (info->map[0][col] == info->empty || info->map[0][col] == info->full)
		{
			dp[0][col] = 1;
			if (max_size < 1)
			{
				max_size = 1;
				max_row = 0;
				max_col = col;
			}
		}
		col++;
	}
	row = 1;
	while (row < info->map_rows)
	{
		dp[1][0] = 0;
		if (info->map[row][0] == info->empty || info->map[row][0] == info->full)
			dp[1][0] = 1;
		col = 1;
		while (col < info->map_cols)
		{
			dp[1][col] = 0;
			if (info->map[row][col] == info->empty || info->map[row][col] == info->full)
				dp[1][col] = 1 + ft_min(dp[0][col - 1], dp[0][col], dp[1][col - 1]);
			col++;
		}
		col = 0;
		while (col < info->map_cols)
		{
			dp[0][col] = dp[1][col];
			if (max_size < dp[0][col])
			{
				max_size = dp[0][col];
				max_row = row;
				max_col = col;
			}
			col++;
		}
		row++;
	}
	free(dp[0]);
	free(dp[1]);
	fill_square(info, max_row, max_col, max_size);
	return (1);
}

void	print_map(t_info *info)
{
	int i;

	i = 0;
	while (i < info->map_rows)
	{
		write(1, info->map[i], info->map_cols);
		write(1, "\n", 1);
		i++;
	}
}

int	init_map(t_info *info, int idx, char *argv[])
{
	int		fd;
	char	line[BUFFER_SIZE];

	fd = open(argv[idx], O_RDONLY);
	if (fd < 0)
		return (ft_error("map error\n", 0));
	if (!parse_first_line(fd, line, BUFFER_SIZE, info) || !read_map(fd, info))
	{
		free_map(info);
		close(fd);
		return (ft_error("map error\n", 0));
	}
	close(fd);
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
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		i;

	if (argc < 2)
		return (ft_error("map error\n", 0));
	i = 1;
	while (i < argc)
	{
		reset_info(&info);
		if (init_map(&info, i, argv))
		{
			find_largest_square(&info);
			print_map(&info);
		}
		free_map(&info);
		if (i + 1 < argc)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
