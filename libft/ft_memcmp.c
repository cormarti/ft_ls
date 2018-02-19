/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:23:09 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/13 01:25:48 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	tmps1 = (unsigned char*)s1;
	tmps2 = (unsigned char*)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n--)
		if (*tmps1++ != *tmps2++)
			return ((*--tmps1) - (*--tmps2));
	return (0);
}
