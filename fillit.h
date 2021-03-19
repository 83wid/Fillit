/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:50:04 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/20 19:17:33 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetri
{
	int				blockcoords[8];
	int				offset_x;
	int				offset_y;
	char			tetri_letter;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	char			**array;
}					t_map;

void				exit_error(void);
void				usage(void);
int					ft_check_form(char *tetrim, int hash, int point);
int					ft_check_tetrim(char *tetrim);
int					ft_read_file(int fd, t_tetri **list_tetris);
t_tetri				*make_tetri(char *tetris, char letter);
void				align(t_tetri *tetri);
void				free_all_list(t_tetri *list);
void				shift_x(t_tetri *tetri, int n);
void				shift_y(t_tetri *tetri, int n);
int					count_tetris(t_tetri *list_tetri);
int					round_up_sqrt(int num);
t_map				*new_map(int size_map);
void				print_map(t_map *map, int size_map);
void				free_map(t_map *map, int size);
void				solve(t_tetri *list_tetris);
int					solve_map(t_map *map, t_tetri *tetri, int size_map);
int					in_bounds(t_tetri *tetri, int size_map, char offset);
int					is_overlap(t_map *map, t_tetri *tetri);
void				place(t_tetri *tetri, t_map *map, char letter);
#endif
