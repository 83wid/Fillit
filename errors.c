/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 02:14:45 by gayoub            #+#    #+#             */
/*   Updated: 2019/06/24 18:12:58 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		exit_error(void)
{
	ft_putendl("error");
	exit(1);
}

void		usage(void)
{
	ft_putendl("usage: ./fillit [file_name]");
	exit(1);
}
