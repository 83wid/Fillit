/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:27:12 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/21 16:21:32 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				count_tetris(t_tetri *list_tetri)
{
	int			count;

	count = 0;
	while (list_tetri)
	{
		count++;
		list_tetri = list_tetri->next;
	}
	return (count);
}

int				round_up_sqrt(int num)
{
	int			size_mp;

	size_mp = 2;
	while (size_mp * size_mp < num)
		size_mp++;
	return (size_mp);
}

t_map			*new_map(int size_map)
{
	t_map		*map;
	int			i;

	i = 0;
	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if (!(map->array = (char**)ft_memalloc(sizeof(char *) * size_map)))
		return (NULL);
	while (i < size_map)
	{
		map->array[i] = ft_strnew(size_map);
		ft_memset(map->array[i], '.', size_map);
		i++;
	}
	return (map);
}

void			print_map(t_map *map, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map->array[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			free_map(t_map *map, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void**)&map->array[i]);
		i++;
	}
	ft_memdel((void**)&map->array);
	ft_memdel((void**)&map);
}
