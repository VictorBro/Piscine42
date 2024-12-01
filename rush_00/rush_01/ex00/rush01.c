/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <moutdili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:39:22 by moutdili          #+#    #+#             */
/*   Updated: 2024/06/21 23:53:58 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_render(int row, int col, int x, int y)
{
	if (row == 0 && col == 0)
		ft_putchar('/');
	else if (row == y - 1 && col == 0)
		ft_putchar('\\');
	else if (row == 0 && col == x - 1)
		ft_putchar('\\');
	else if (row == y - 1 && col == x - 1)
		ft_putchar('/');
	else if (row == 0 || row == y - 1 || col == 0 || col == x - 1)
		ft_putchar('*');
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
			ft_render(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
