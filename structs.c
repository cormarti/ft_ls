/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:16:14 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/18 23:38:47 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_file(void)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		exit(0);
	file->next = NULL;
	file->child = NULL;
	file->name = NULL;
	file->type = NULL;
	file->path = NULL;
	file->dt = NULL;
	return (file);
}

t_max	*new_max(void)
{
	t_max	*max;

	if (!(max = (t_max*)malloc(sizeof(t_max))))
		exit(0);
	max->maxsize = 0;
	max->maxlink = 0;
	max->maxuid = 0;
	max->maxgid = 0;
	return (max);
}

void	finfo(t_file *f, char **files)
{
	t_file	*curr;
	t_file	*node;
	int		i;

	i = 1;
	curr = f;
	while (files[i])
	{
		while (curr->next)
			curr = curr->next;
		node = new_file();
		lstat(files[i], &(node->sb));
		curr->next = node;
		i++;
	}
}
