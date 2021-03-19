/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:40:34 by nabouzah          #+#    #+#             */
/*   Updated: 2019/06/12 12:19:57 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	s = 0;
	i = 0;
	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero((void*)s, ft_strlen(s));
	return (s);
}
