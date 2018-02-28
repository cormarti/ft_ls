/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:21:45 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/26 22:38:06 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2, int tofree)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	join =  ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	if (tofree == 3)
	{
		free(s1);
		free(s2);
	}
	else if (s1 && tofree == 1)
		free(s1);
	else if (s2 && tofree == 2)
		free(s2);
	return (join);
}
