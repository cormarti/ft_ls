/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:07:26 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/16 02:24:53 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s1_len;
	size_t	i;

	i = 0;
	s1_len = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[s1_len] && s1_len < size)
		s1_len++;
	while (src[i] && (s1_len + i) < size - 1)
	{
		dst[s1_len + i] = src[i];
		i++;
	}
	if (s1_len < size)
		dst[s1_len + i] = '\0';
	return (s1_len + ft_strlen(src));
}
