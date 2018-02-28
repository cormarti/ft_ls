/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 22:49:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 13:38:47 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	node_free(t_file *node, int code)
{
	free(node);
	node = NULL;
	return (code);
}

int			file_push_back(t_file *f, DIR *dir, char *path)
{
	t_file	*curr;
	t_file	*node;
	char	*realpath;

	curr = f;
	node = new_file();
	if (!(node->dt = readdir(dir)))
		return (node_free(node, 0));
	if (!(optab[2].verif) && node->dt->d_name[0] == '.')
		return (node_free(node, 1));
	node->name = ft_strdup(node->dt->d_name);
	node->path = ft_strdup(path);
	realpath = ft_strjoin(node->path, "/");
	realpath = ft_strjoinf(realpath, node->name, 1);
	lstat(realpath, &(node->sb));
	free(realpath);
	while (curr->next && ft_strcmp(curr->next->name, node->name) < 0)
		curr = curr->next;
	node->next = curr->next;
	curr->next = node;
	return (1);
}

void		free_file(t_file *f)
{
	t_file	*tmp;

	while (f)
	{
		tmp = f;
		if (tmp->name)
			free(tmp->name);
		if (tmp->path)
			free(tmp->path);
		if (tmp->child)
			free_file(tmp->child);
		f = f->next;
		free(tmp);
	}
}
