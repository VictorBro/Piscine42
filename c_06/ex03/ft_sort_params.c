/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:00:36 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/27 23:24:16 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int argc, char *argv[])
{
	int		i;
	char	*ptr;

	i = 1;
	while (i < argc)
	{
		ptr = argv[i];
		while (*ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_swap(char *argv[], int j)
{
	char	*tmp;

	tmp = argv[j];
	argv[j] = argv[j + 1];
	argv[j + 1] = tmp;
}

int	ft_strcmp(char *argv[], int j)
{
	char	*s1;
	char	*s2;

	s1 = argv[j];
	s2 = argv[j + 1];
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i - 1)
		{
			if (ft_strcmp(argv, j) > 0)
				ft_swap(argv, j);
			j++;
		}
		i++;
	}
	ft_print(argc, argv);
	return (0);
}
