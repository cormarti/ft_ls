/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 08:05:55 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/12 23:42:02 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpdst;
	char	*tmpsrc;

	tmpdst = (char*)dst;
	tmpsrc = (char*)src;
	if (tmpdst == tmpsrc)
		return (dst);
	if (tmpdst > tmpsrc)
	{
		tmpdst += len - 1;
		tmpsrc += len - 1;
		while (len--)
			*tmpdst-- = *tmpsrc--;
	}
	else
	{
		while (len--)
			*tmpdst++ = *tmpsrc++;
	}
	return (dst);
}
