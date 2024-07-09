/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:32:46 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/09 21:32:54 by vbronov          ###   ########.fr       */
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
}	t_info;

char	**ft_split(char *str, char sep);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strncpy(char *dst, char *src, size_t n);
int		ft_error(char *str, int ret);
int		ft_atoi(char *str);

#endif
