/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:57:48 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/23 21:43:04 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char c)
{
	return (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;

	ret = str;
	while (str && *str)
	{
		if (str == ret && 'a' <= *str && *str <= 'z')
			*str -= 32;
		else if ('A' <= *str && *str <= 'Z' && ft_isalnum(*(str - 1)))
			*str += 32;
		else if ('a' <= *str && *str <= 'z' && !ft_isalnum(*(str - 1)))
			*str -= 32;
		str++;
	}
	return (ret);
}
