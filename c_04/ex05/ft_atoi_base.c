/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:39:37 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/26 20:21:41 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert(char *str, int base_len, char *base)
{
	int	value;
	int	result;

	result = 0;
	while (*str != '\0')
	{
		value = base_index(*str, base);
		if (value == -1)
			break ;
		result = result * base_len + value;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;

	if (!is_valid_base(base))
		return (0);
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	if (sign % 2 == 1)
		return (-1 * ft_convert(str, base_len, base));
	return (ft_convert(str, base_len, base));
}
