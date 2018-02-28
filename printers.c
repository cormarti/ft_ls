/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:56:26 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 14:51:18 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ppath(t_file *f, char *path, char *name, int ischild)
{
	if (f)
	{
		ft_putstr(path);
		if (ischild)
		{
			ft_putstr("/");
			ft_putstr(name);
		}
		ft_putstr(":\n");
	}
}

void	plist(t_file *f, char *path, char *name, int ischild)
{
	t_file	*curr;
	t_max	*max;

	curr = f;
	ppath(curr, path, name, ischild);
	if (!(curr->error))
	{
		if (optab[0].verif && curr && curr->path)
		{
			max = new_max();
			maxlengths_dir(f, max, 1);
		}
		while (curr)
		{
			if (curr->path)
				pfile_details(curr, max);
			curr = curr->next;
		}
		if (optab[0].verif && f && f->path)
			free(max);
	}
	else
		print_error(curr);
}

t_file	*plist_all(t_file *f, char *path, char *name, int ischild)
{
	t_file	*curr;

	if (f == NULL)
		return (0);
	if (optab[4].verif)
		f = modtime_struct_sort(f);
	if (optab[3].verif)
		f = reverse_sort(f);
	curr = f;
	if (ischild)
		ft_putstr("\n");
	plist(curr, path, name, ischild);
	while (curr)
	{
		if (curr->child)
			curr->child = plist_all(curr->child, curr->path, curr->name, 1);
		curr = curr->next;
	}
	return (f);
}

int		pfiles(char **files)
{
	t_file		*f;
	t_max		*max;

	if (!(files) || !(files[0]))
	{
		free(files);
		return (0);
	}
	f = new_file();
	lstat(files[0], &(f->sb));
	f->name = ft_strdup(files[0]);
	finfo(f, files);
	max = new_max();
	if (optab[0].verif && f && f->name)
		maxlengths_dir(f, max, 0);
	spfile_details(f, files, max);
	free_file(f);
	free(files);
	return (1);
}
