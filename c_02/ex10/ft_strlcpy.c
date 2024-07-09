/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:10:41 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/24 17:37:50 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	n;

	n = 0;
	while (str && *str)
	{
		n++;
		str++;
	}
	return (n);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;

	n = ft_strlen(src);
	while (src && *src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	if (size >= 1)
		*dest = '\0';
	return (n);
}
