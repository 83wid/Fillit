/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:38:43 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/20 18:32:15 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_all_list(t_tetri *list)
{
	t_tetri	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void		align(t_tetri *tetri)
{
	while (tetri->blockcoords[0] != 0 && tetri->blockcoords[2] != 0 &&\
			tetri->blockcoords[4] != 0 && tetri->blockcoords[6] != 0)
		shift_x(tetri, -1);
	while (tetri->blockcoords[1] != 0 && tetri->blockcoords[3] != 0 &&\
			tetri->blockcoords[5] != 0 && tetri->blockcoords[7] != 0)
		shift_y(tetri, -1);
}

t_tetri		*make_tetri(char *tetris, char letter)
{
	int		i;
	int		x;
	int		y;
	t_tetri	*piece;

	i = 0;
	x = 0;
	y = 1;
	piece = (t_tetri*)ft_memalloc(sizeof(t_tetri));
	while (i < 20)
	{
		if (tetris[i] == '#')
		{
			piece->blockcoords[x] = (i >= 5) ? (i % 5) : i;
			piece->blockcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece->tetri_letter = letter;
	piece->offset_x = 0;
	piece->offset_y = 0;
	align(piece);
	return (piece);
}
