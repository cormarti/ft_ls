/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 22:49:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/18 18:49:46 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			file_push_back(t_file *f, DIR *dir, char *path)
{
	t_file	*curr;
	t_file	*node;

	curr = f;
	while (curr->next)
		curr = curr->next;
	node = new_file();
	if (!(node->dt = readdir(dir)))
	{
		free(node);
		return (0);
	}
	if (!(optab[2].verif) && node->dt->d_name[0] == '.')
	{
		free(node);
		return (1);
	}
	node->name = ft_strdup(node->dt->d_name);
	//node->type = ft_strdup(node->dt->d_type);
	node->path = ft_strdup(path);
	path = ft_strjoin(path, "/");
	lstat(ft_strjoin(path, node->dt->d_name), &(node->sb));
	//ft_putstr(node->dt->d_name);
	//ft_putstr("\n");
	curr->next = node;
	return (1);
}

static DIR		*fresh_opendir(char *path)
{
	DIR		*dir;

	dir = NULL;
	dir = opendir(path);
	return (dir);
}

t_file		*recursively_add_lists(t_file *f)
{
	t_file	*curr;
	char	*path;
	DIR		*dir;

	dir = NULL;
	curr = f;
	while (curr)
	{
			
		if (S_ISDIR(curr->sb.st_mode)
			&& (optab[2].verif || curr->dt->d_name[0] != '.')
			&& ft_strcmp(curr->dt->d_name, ".") != 0
			&& ft_strcmp(curr->dt->d_name, "..") != 0)
		{
			path = ft_strjoin(curr->path, "/");
			path = ft_strjoin(path, curr->dt->d_name);
			dir = fresh_opendir(path);
			curr->child = NULL;
			curr->child = new_file();
			if (!(curr->child->dt = readdir(dir)))
				exit(0);
			while (!(optab[2].verif) && curr->child->dt->d_name[0] == '.')
				if (!(curr->child->dt = readdir(dir)))
					exit(0);
			curr->child->name = ft_strdup(curr->child->dt->d_name);
			curr->child->path = ft_strdup(path);
			path = ft_strjoin(path, "/");
			//curr->child->type = ft_strdup(curr->child->dt->d_type);
			lstat(ft_strjoin(path, curr->child->name), &(curr->child->sb));
			while (file_push_back(curr->child, dir, curr->child->path) != 0)
			{
			}
			(void)closedir(dir);
			recursively_add_lists(curr->child);
		}
		curr = curr->next;
	}
	return (f);	
}
