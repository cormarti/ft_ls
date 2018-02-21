/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 22:49:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/21 08:26:17 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			file_push_back(t_file *f, DIR *dir, char *path)
{
	t_file	*curr;
	t_file	*node;
	char	*newpath;

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
	path = ft_strjoin(node->path, "/");
	newpath = ft_strjoin(path, node->dt->d_name);
	lstat(newpath, &(node->sb));
	free(path);
	free(newpath);
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

void			recursively_add_lists(t_file *f)
{
	t_file	*curr;
	char	*path;
	char	*newpath;
	DIR		*dir;

	dir = NULL;
	curr = f;
	while (curr)
	{
			
		if (S_ISDIR(curr->sb.st_mode)
			&& (optab[2].verif || curr->dt->d_name[0] != '.')
			&& ft_strcmp(curr->name, ".") != 0
			&& ft_strcmp(curr->name, "..") != 0)
		{

			newpath = ft_strjoin(curr->path, "/");
			path = ft_strjoin(newpath, curr->name);
			free(newpath);
			if ((dir = fresh_opendir(path)))
			{
					
			curr->child = NULL;
			curr->child = new_file();
			if (!(curr->child->dt = readdir(dir)))
			{
				free(path);
				perror(path);
				exit(0);
			}
			while (!(optab[2].verif) && curr->child->dt->d_name[0] == '.')
				if (!(curr->child->dt = readdir(dir)))
				{
					free(path);
					perror(path);
					exit(0);
				}
			curr->child->name = ft_strdup(curr->child->dt->d_name);
			curr->child->path = ft_strdup(path);
			free(path);
			path = ft_strjoin(curr->child->path, "/");
			//curr->child->type = ft_strdup(curr->child->dt->d_type);
			newpath = ft_strjoin(path, curr->child->name);
			lstat(newpath, &(curr->child->sb));
			free(newpath);
			while (file_push_back(curr->child, dir, curr->child->path) != 0)
			{
			}
			(void)closedir(dir);
			recursively_add_lists(curr->child);
			}
			free(path);
		}
		curr = curr->next;
	}
}

void		free_file(t_file *f)
{
	t_file	*tmp;

	while (f)
	{
		tmp = f;
		f = f->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->path)
			free(tmp->path);
		if (tmp->child)
			free_file(tmp->child);
		free(tmp);
	}
	f = NULL;
}
