/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:40:46 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/25 18:37:22 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	n;

	n = 0;
	while (str && *str)
	{
		str++;
		n++;
	}
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	dest_len;

	dest_len = 0;
	while (dest && *dest && dest_len < size)
	{
		dest++;
		dest_len++;
	}
	n = dest_len + ft_strlen(src);
	if (!dest || !src || size == 0)
		return (n);
	while (*dest)
		dest++;
	while (*src && dest_len < size - 1)
	{
		*dest++ = *src++;
		dest_len++;
	}
	*dest = '\0';
	return (n);
}
