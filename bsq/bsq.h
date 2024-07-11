/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:32:46 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/10 20:53:04 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 4096

typedef struct s_info
{
	char	**map;
	int		map_rows;
	int		map_cols;
	char	empty;
	char	obstacle;
	char	full;
	int		fd;
}	t_info;

typedef struct s_rect
{
	int	size;
	int	row;
	int	col;
}	t_rect;

int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strncpy(char *dst, char *src, size_t n);
int		ft_error(char *str, int ret);
int		ft_atoi(char *str);
int		find_and_fill_largest_square(t_info *info);
int		ft_min(int a, int b, int c);
void	print_map(t_info *info);
void	free_map(t_info *info);
int		read_line(int fd, char *line, size_t line_size);
int		parse_first_line(char *line, size_t line_size, t_info *info);
int		allocate_and_check_first_line(t_info *info, char *line);
int		validate_line(char *line, t_info *info);

#endif
