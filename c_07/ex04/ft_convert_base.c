/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:39:37 by vbronov           #+#    #+#             */
/*   Updated: 2024/07/01 16:29:20 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid_base(char *base);
int	base_index(char c, char *base);
int	ft_get_num_len(int nbr, int base_len);

void	ft_putnbr_base_helper(long nbr, char *base, char *ret, int n)
{
	int		base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (nbr < base_len)
	{
		ret[n--] = base[nbr];
		return ;
	}
	while (nbr > 0)
	{
		ret[n--] = base[nbr % base_len];
		nbr /= base_len;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;
	int		len;
	char	*ret;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	len = ft_get_num_len(nbr, base_len);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	nb = nbr;
	if (nb < 0)
	{
		*ret = '-';
		nb = -nb;
	}
	ft_putnbr_base_helper(nb, base, ret, len - 1);
	return (ret);
}

int	ft_convert(char *str, int base_len, char *base, int sign)
{
	int	value;
	int	result;

	result = 0;
	while (*str != '\0')
	{
		value = base_index(*str, base);
		if (value == -1)
			break ;
		if (result == 214748364 && sign % 2 == 1 && value == 8)
			return (-2147483648);
		result = result * base_len + value;
		str++;
	}
	if (sign % 2 == 1)
		result = -result;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;

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
	return (ft_convert(str, base_len, base, sign));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(n, base_to));
}
