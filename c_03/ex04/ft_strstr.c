/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:15:26 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/25 17:39:20 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_ptr;
	char	*to_find_ptr;

	if (!to_find || *to_find == '\0')
		return (str);
	while (*str)
	{
		str_ptr = str;
		to_find_ptr = to_find;
		while (*to_find_ptr && *str_ptr == *to_find_ptr)
		{
			str_ptr++;
			to_find_ptr++;
		}
		if (*to_find_ptr == '\0')
			return (str);
		str++;
	}
	return (0);
}
