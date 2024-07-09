/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <marvin@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:19:39 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/22 16:20:24 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
