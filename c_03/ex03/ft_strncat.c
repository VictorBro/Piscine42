/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:08:06 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/25 17:13:08 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (*src && nb > 0)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (ret);
}
