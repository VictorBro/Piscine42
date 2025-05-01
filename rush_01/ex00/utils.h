/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:31:32 by vbronov           #+#    #+#             */
/*   Updated: 2024/06/29 22:17:43 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define TRUE 1
# define FALSE 0

enum e_views{
	COL1UP,
	COL2UP,
	COL3UP,
	COL4UP,
	COL1DOWN,
	COL2DOWN,
	COL3DOWN,
	COL4DOWN,
	ROW1LEFT,
	ROW2LEFT,
	ROW3LEFT,
	ROW4LEFT,
	ROW1RIGHT,
	ROW2RIGHT,
	ROW3RIGHT,
	ROW4RIGHT,
};

enum e_err{
	OK,
	ERROR,
};

int		is_valid(char *view_points, char grid[4][4], int row, int col);
int		parse_main(char **argv, char *view_points);

#endif
