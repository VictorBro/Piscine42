/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:24:10 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/25 21:37:24 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(char *str)
{
	int	ret;
	int	count;

	count = 0;
	ret = 0;
	while (str && *str && ft_isspace(*str))
		str++;
	while (str && *str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (str && *str && ft_isdigit(*str))
	{
		if (count % 2 == 1 && ret == 214748364 && *str == '8')
			return (-2147483648);
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (count % 2 == 1)
		ret *= -1;
	return (ret);
}
