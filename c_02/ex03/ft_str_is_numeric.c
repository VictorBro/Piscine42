/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:25:07 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/23 19:27:06 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (str && *str)
	{
		if ('0' <= *str && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}