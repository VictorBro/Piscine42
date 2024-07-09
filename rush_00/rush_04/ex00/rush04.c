/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:39:22 by moutdili          #+#    #+#             */
/*   Updated: 2024/06/22 00:01:39 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_rendre(int row, int col, int x, int y)
{
	if (row == 0 && col == 0)
		ft_putchar('A');
	else if (row == 0 && col == x - 1)
		ft_putchar('C');
	else if (row == y - 1 && col == 0)
		ft_putchar('C');
	else if (row == y - 1 && col == x - 1)
		ft_putchar('A');
	else if (row == 0 || row == y - 1 || col == 0 || col == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x < 1 || y < 1)
		return ;
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			ft_rendre(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
