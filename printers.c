/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:56:26 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/21 11:37:26 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		plist(t_file *f)
{
	t_file	*curr;
	t_max	*max;

	curr = f;
	if (curr)
	{
		ft_putstr("\n");
		ft_putstr(curr->path);
		ft_putstr(":\n");
	}
	if (optab[0].verif)
	{
		max = new_max();
		maxlengths_dir(f, max);
	}
	while (curr)
	{
		if (optab[0].verif)
			long_display(curr, max);
		ft_putstr(curr->name);
		ft_putstr("\n");
		curr = curr->next;
	}
	if (optab[0].verif)
		free(max);
}

int			plist_all(t_file *f)
{
	t_file	*curr;

	if (f == NULL)
		return (0);
	f = lexico_struct_sort(f);
	if (optab[4].verif)
		f = modtime_struct_sort(f);
	if (optab[3].verif)
		f = reverse_sort(f);
	curr = f;
	plist(curr);
	while (curr)
	{
		if (curr->child)
			plist_all(curr->child);
		curr = curr->next;
	}
	return (0);
}

int		pfiles(char **files)
{
	t_file		*f;
	t_file		*curr;
	t_max		*max;
	int			i;

	i = 0;
	if (!(files))
		return (0);
	if (files[i] == NULL)
	{
		free(files);
		return (0);
	}
	max = new_max();
	f = new_file();
	lstat(files[i], &(f->sb));
	finfo(f, files);
	if (optab[0].verif)
		maxlengths_dir(f, max);
	curr = f;
	while (f)
	{
		curr = f;
		f = f->next;
		if (optab[0].verif)
			long_display(curr, max);
		ft_putstr(files[i]);
		free(files[i]);
		ft_putstr("\n");
		free_file(curr);
	}
	free(files);
	free(f);
	free(max);
	return (1);
}
