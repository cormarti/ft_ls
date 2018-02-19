/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:38:20 by cormarti          #+#    #+#             */
/*   Updated: 2017/11/14 16:33:16 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	new = f(lst);
	head = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(lst)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
