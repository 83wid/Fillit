/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 04:17:12 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/12 20:19:52 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		shift_x(t_tetri *tetri, int n)
{
	tetri->blockcoords[0] += n;
	tetri->blockcoords[2] += n;
	tetri->blockcoords[4] += n;
	tetri->blockcoords[6] += n;
}

void		shift_y(t_tetri *tetri, int n)
{
	tetri->blockcoords[1] += n;
	tetri->blockcoords[3] += n;
	tetri->blockcoords[5] += n;
	tetri->blockcoords[7] += n;
}
