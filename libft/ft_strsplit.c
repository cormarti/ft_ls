/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:53:27 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/13 05:16:50 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cwords(char const *s, char c)
{
	int		i;
	int		words;
	int		active;

	i = 0;
	words = 0;
	active = 0;
	while (s[i])
	{
		if (s[i] != c && active == 0)
		{
			active = 1;
			words++;
		}
		else if (s[i] == c)
			active = 0;
		i++;
	}
	return (words);
}

static char		*ft_strnext(char const *s, char c, int *index)
{
	int		i;
	char	*str;
	int		len;

	while (s[*index] == c)
		*index += 1;
	i = *index;
	len = 0;
	while (s[i] && s[i++] != c)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[*index] && s[*index] != c)
	{
		str[i++] = s[*index];
		*index += 1;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		index;

	if (!s || !(arr = (char**)malloc(sizeof(char*) * (ft_cwords(s, c) + 1))))
		return (NULL);
	i = -1;
	index = 0;
	while (++i < ft_cwords(s, c))
		arr[i] = ft_strnext(s, c, &index);
	arr[i] = NULL;
	return (arr);
}
