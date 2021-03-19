/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:32:50 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/24 12:11:39 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetri	*list_tetris;
	int		fd;

	if (ac != 2)
		usage();
	if ((fd = open(av[1], O_RDONLY)) < 0)
		exit_error();
	if ((ft_read_file(fd, &list_tetris)) < 0)
	{
		free_all_list(list_tetris);
		exit_error();
	}
	solve(list_tetris);
	free_all_list(list_tetris);
	return (0);
}
