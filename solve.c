/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:27:21 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/24 18:18:33 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			in_bounds(t_tetri *tetri, int size_map, char offset)
{
	if (offset == 'y')
		return (tetri->blockcoords[1] + tetri->offset_y < size_map &&
				tetri->blockcoords[3] + tetri->offset_y < size_map &&
				tetri->blockcoords[5] + tetri->offset_y < size_map &&
				tetri->blockcoords[7] + tetri->offset_y < size_map);
	else
		return (tetri->blockcoords[0] + tetri->offset_x < size_map &&
				tetri->blockcoords[2] + tetri->offset_x < size_map &&
				tetri->blockcoords[4] + tetri->offset_x < size_map &&
				tetri->blockcoords[6] + tetri->offset_x < size_map);
}

int			overlap(t_map *map, t_tetri *tetri)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	x = tetri->blockcoords[i] + tetri->offset_x;
	y = tetri->blockcoords[i + 1] + tetri->offset_y;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = tetri->blockcoords[i] + tetri->offset_x;
		y = tetri->blockcoords[i + 1] + tetri->offset_y;
	}
	return (i != 8);
}

void		place(t_tetri *tetri, t_map *map, char letter)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = tetri->blockcoords[i] + tetri->offset_x;
		y = tetri->blockcoords[i + 1] + tetri->offset_y;
		map->array[y][x] = letter;
		i += 2;
	}
}

int			solve_map(t_map *map, t_tetri *tetri, int size_map)
{
	if (!tetri)
		return (1);
	tetri->offset_x = 0;
	tetri->offset_y = 0;
	while (in_bounds(tetri, size_map, 'y'))
	{
		while (in_bounds(tetri, size_map, 'x'))
		{
			if (!overlap(map, tetri))
			{
				place(tetri, map, tetri->tetri_letter);
				if (solve_map(map, tetri->next, size_map))
					return (1);
				else
					place(tetri, map, '.');
			}
			tetri->offset_x++;
		}
		tetri->offset_x = 0;
		tetri->offset_y++;
	}
	return (0);
}

void		solve(t_tetri *list_tetris)
{
	t_map	*map;
	int		size_map;

	size_map = round_up_sqrt(count_tetris(list_tetris) * 4);
	if (!(map = new_map(size_map)))
		return ;
	while (!solve_map(map, list_tetris, size_map))
	{
		free_map(map, size_map);
		size_map++;
		map = new_map(size_map);
	}
	print_map(map, size_map);
	free_map(map, size_map);
}
