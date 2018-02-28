/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:55:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 15:01:13 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static DIR	*fresh_opendir(char *path)
{
	DIR		*dir;

	dir = NULL;
	dir = opendir(path);
	return (dir);
}

static int	insert_childs(t_file *curr, char *path, DIR *dir)
{
	while (!(optab[2].verif) && curr->child->dt->d_name[0] == '.')
		if (!(curr->child->dt = readdir(dir)))
		{
			closedir(dir);
			return (0);
		}
	curr->child->name = ft_strdup(curr->child->dt->d_name);
	curr->child->path = ft_strdup(path);
	path = ft_strjoin(path, "/");
	path = ft_strjoinf(path, curr->child->name, 1);
	lstat(path, &(curr->child->sb));
	while (file_push_back(curr->child, dir, curr->child->path) != 0)
		(void)0;
	closedir(dir);
	recursively_add_lists(curr->child);
	free(path);
	return (1);
}

void		recursively_add_lists(t_file *f)
{
	t_file	*curr;
	char	*path;
	DIR		*dir;

	curr = f;
	while (curr)
	{
		if (S_ISDIR(curr->sb.st_mode) && ft_strcmp(curr->name, ".") != 0
			&& (optab[2].verif || curr->dt->d_name[0] != '.')
			&& ft_strcmp(curr->name, "..") != 0)
		{
			path = ft_strjoin(curr->path, "/");
			path = ft_strjoinf(path, curr->name, 1);
			curr->child = new_file();
			if ((dir = fresh_opendir(path)))
			{
				if ((curr->child->dt = readdir(dir)))
					insert_childs(curr, path, dir);
			}
			else
				set_error(curr->child, curr->name);
			free(path);
		}
		curr = curr->next;
	}
}
