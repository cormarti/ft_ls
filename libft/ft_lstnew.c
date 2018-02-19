/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 07:51:06 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/14 12:16:49 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*mcontent;
	size_t	mcontent_size;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		mcontent = ft_memalloc(content_size);
		mcontent_size = content_size;
		ft_memcpy(mcontent, content, content_size);
		list->content = mcontent;
		list->content_size = mcontent_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
