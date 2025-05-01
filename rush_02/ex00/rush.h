/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:44:17 by mbendidi          #+#    #+#             */
/*   Updated: 2024/07/07 21:18:33 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 512

typedef struct s_digits
{
	int	x;
	int	y;
	int	z;
}	t_digits;

typedef struct s_info
{
	char	*until19[20];
	char	*tens[10];
	char	*level[13];
	char	*str;
}	t_info;

int		init_info(t_info *info, char *str);
void	init_words(char *words[]);
void	free_all(t_info *info);
void	free_words(char *words[], int word_count);
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_putstr(char *str);
void	print_words(char *words[], int word_count);
int		read_line(char *buffer, int n, int fd);
int		add_to_until19(char *buffer, char *until19[]);
int		add_to_tens(char *buffer, char *tens[]);
int		add_to_level(char *buffer, char *level[]);
int		ft_error(char *str, int ret);
int		ft_add_word(char **words, int *word_count, char **dict, int idx);
char	*ft_trim(char *str);
char	*trim_leading(char *str);
void	get_digits(t_digits *d, t_info *info, int *i);
int		handle_under100(char *words[255],
			int *word_count, t_info *info, t_digits d);
int		has_non_printable(char *str);

#endif
