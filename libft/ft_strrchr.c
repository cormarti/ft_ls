/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:16:26 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/13 04:11:08 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == (char)c)
			return ((char*)s + len);
		len--;
	}
	if (s[0] == (char)c)
		return ((char*)s);
	return (NULL);
}
