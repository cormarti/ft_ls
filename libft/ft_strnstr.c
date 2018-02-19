/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:37:17 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/13 06:58:53 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(to_find) == 0)
		return ((char*)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (to_find[j] == str[i + j] && (i + j) < len)
		{
			if (!to_find[j + 1])
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
