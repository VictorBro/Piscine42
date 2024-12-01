/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:57:21 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/07 21:16:44 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	parse_line(char *buffer, t_info *info)
{
	int	i;
	int	j;

	if (has_non_printable(buffer))
		return (0);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	else if (i == 1 || (i == 2 && buffer[0] < '2'))
		return (add_to_until19(buffer, info->until19));
	else if (i == 2 && buffer[1] == '0')
		return (add_to_tens(buffer, info->tens));
	else if (i == 2)
		return (1);
	if (buffer[0] != '1' || i > 37)
		return (1);
	j = 1;
	while (j < i)
		if (buffer[j++] != '0')
			return (1);
	return (add_to_level(buffer, info->level));
}

int	read_dictionary(char *fname, t_info *info)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	*str;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (ft_error("Dict Error\n", 0));
	bytes_read = read_line(buffer, BUFFER_SIZE, fd);
	while (bytes_read > 0)
	{
		str = ft_trim(buffer);
		if (ft_strlen(str) > 0 && !parse_line(str, info))
		{
			close(fd);
			return (ft_error("Dict Error\n", 0));
		}
		bytes_read = read_line(buffer, BUFFER_SIZE, fd);
	}
	close(fd);
	if (bytes_read < 0)
		return (ft_error("Dict Error\n", 0));
	return (1);
}

int	ft_main_loop(char *words[255], int *word_count, int i, t_info *info)
{
	t_digits	d;
	int			lvl;

	lvl = 0;
	while (i >= 0)
	{
		if (lvl >= 13)
		{
			free_words(words, *word_count);
			return (-1);
		}
		get_digits(&d, info, &i);
		if (lvl && !ft_add_word(words, word_count, info->level, lvl))
			return (0);
		if (!handle_under100(words, word_count, info, d))
			return (0);
		if (d.x > 0)
		{
			if (!ft_add_word(words, word_count, info->level, 0)
				|| !ft_add_word(words, word_count, info->until19, d.x))
				return (0);
		}
		lvl++;
	}
	return (1);
}

int	number_to_word(t_info *info)
{
	int			i;
	int			word_count;
	char		*words[255];

	init_words(words);
	word_count = 0;
	i = ft_strlen(info->str) - 1;
	if (i == 0 && info->str[0] == '0')
	{
		if (!ft_add_word(words, &word_count, info->until19, 0))
			return (0);
		i = -1;
	}
	i = ft_main_loop(words, &word_count, i, info);
	if (i == 0)
		return (0);
	else if (i == -1)
		return (ft_error("Dict Error\n", 1));
	print_words(words, word_count);
	free_words(words, word_count);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	char	*fname;
	char	*str;

	if (argc >= 2 && argc <= 3)
	{
		fname = "numbers.dict";
		str = argv[1];
		if (argc == 3)
		{
			fname = argv[1];
			str = argv[2];
		}
		if (init_info(&info, str)
			&& (!read_dictionary(fname, &info) || number_to_word(&info)))
		{
			free_all(&info);
			return (0);
		}
		free_all(&info);
	}
	write(1, "Error\n", 6);
	return (0);
}
