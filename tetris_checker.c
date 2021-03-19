/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 05:06:14 by nabouzah          #+#    #+#             */
/*   Updated: 2019/06/20 19:13:40 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_form(char *tetrim, int hash, int point)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (tetrim[i])
	{
		if (tetrim[i] == '.')
			point++;
		else if (tetrim[i] == '#')
		{
			hash++;
			if (tetrim[i + 1] == '#')
				link++;
			if (tetrim[i + 5] == '#')
				link++;
			if (i >= 1 && tetrim[i - 1] == '#')
				link++;
			if (i >= 5 && tetrim[i - 5] == '#')
				link++;
		}
		i++;
	}
	return ((point == 12 && hash == 4 && (link == 6 || link == 8)));
}

int			ft_check_tetrim(char *tetrim)
{
	int		point;
	int		hash;

	point = 0;
	hash = 0;
	if (!(tetrim[4] == tetrim[9] && tetrim[9] == tetrim[14] &&\
				tetrim[14] == tetrim[19] && tetrim[19] == '\n'\
				&& (tetrim[20] == '\n' || !tetrim[20])))
		return (-1);
	return ((!(ft_check_form(tetrim, hash, point))) ? -1 : 1);
}

int			ft_read_file(int fd, t_tetri **list_tetris)
{
	char	buff[22];
	int		ret;
	int		tetrim;
	t_tetri *curr;

	tetrim = 0;
	while ((ret = read(fd, buff, 21)) > 0 && tetrim <= 26)
	{
		buff[ret] = '\0';
		if ((ft_check_tetrim(buff)) < 0)
			return (-1);
		if (tetrim == 0)
		{
			*list_tetris = make_tetri(buff, ('A' + tetrim));
			curr = *list_tetris;
		}
		else
		{
			curr->next = make_tetri(buff, ('A' + tetrim));
			curr = curr->next;
		}
		tetrim++;
	}
	curr->next = NULL;
	return (((!ret && buff[20] != '\0') || tetrim > 26) ? -1 : tetrim);
}
