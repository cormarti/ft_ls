/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 06:22:00 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/11 06:34:44 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(new, (int)'\0', size + 1);
	return (new);
}
