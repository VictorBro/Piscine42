/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <marvin@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:31:21 by akabbaj           #+#    #+#             */
/*   Updated: 2024/06/22 17:31:56 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

long	calculate(int char_count, char *str)
{
	int		counter;
	int		tens_counter;
	int		dig_count;
	long	total;
	long	tens;

	counter = 0;
	dig_count = 0;
	total = 0;
	while (str[dig_count + char_count] >= '0'
		&& str[dig_count + char_count] <= '9')
		dig_count++;
	while (counter < dig_count)
	{
		tens_counter = 0;
		tens = 1;
		while (tens_counter < (dig_count - counter - 1))
		{
			tens *= 10;
			tens_counter++;
		}
		total += (tens * (str[char_count + counter] - '0'));
		counter++;
	}
	return (total);
}

int	ft_atoi(char *str)
{
	int		minus_count;
	int		char_count;

	minus_count = 0;
	char_count = 0;
	while (str[char_count] == ' ')
		char_count++;
	while (str[char_count] == '-' || str[char_count] == '+')
	{
		if (str[char_count] == '-')
			minus_count++;
		char_count++;
	}	
	if (minus_count % 2 == 1)
		return (calculate(char_count, str) * -1);
	return (calculate(char_count, str));
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
			if ((row == 0 && col == 0) || (row == y - 1 && col == 0))
				ft_putchar('A');
			else if ((row == 0 && col == x - 1)
				|| (row == y - 1 && col == x - 1))
				ft_putchar('C');
			else if (row == 0 || row == y - 1 || col == 0 || col == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
