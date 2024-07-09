/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:20:43 by cdorig            #+#    #+#             */
/*   Updated: 2024/07/07 23:19:58 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_error(char *str, int ret)
{
	ft_putstr(str);
	return (ret);
}

void	get_digits(t_digits *d, t_info *info, int *i)
{
	d->x = -1;
	d->y = -1;
	d->z = info->str[*i] - '0';
	(*i)--;
	if (*i >= 0)
	{
		d->y = info->str[*i] - '0';
		(*i)--;
	}
	if (*i >= 0)
	{
		d->x = info->str[*i] - '0';
		(*i)--;
	}
}

int	handle_under100(char *words[255], int *word_count, t_info *info, t_digits d)
{
	if (d.z > 0 && d.y <= 0)
	{
		if (!ft_add_word(words, word_count, info->until19, d.z))
			return (0);
	}
	else if (d.y == 1)
	{
		d.y = d.y * 10 + d.z;
		if (!ft_add_word(words, word_count, info->until19, d.y))
			return (0);
	}
	else if (d.y >= 2)
	{
		if (d.z > 0)
			if (!ft_add_word(words, word_count, info->until19, d.z))
				return (0);
		if (!ft_add_word(words, word_count, info->tens, d.y))
			return (0);
	}
	return (1);
}

int	has_non_printable(char *str)
{
	while (str && *str)
	{
		if (*str < 32 || *str > 126)
			return (1);
		str++;
	}
	return (0);
}

void	ft_free_split(char *str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
