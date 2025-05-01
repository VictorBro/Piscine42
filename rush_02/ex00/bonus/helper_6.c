/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:22:00 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/07 23:22:31 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	handle_read(int *argc, char **argv[])
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	**args;

	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
	if (bytes_read < 0)
		ft_error("Error\n", 0);
	buffer[bytes_read] = '\0';
	args = ft_split(buffer, " \r\t\v\f\n");
	if (!args)
		ft_error("Error\n", 0);
	*argc = 0;
	while (args[*argc])
		(*argc)++;
	*argv = args;
	return (1);
}
