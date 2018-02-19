/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:56:26 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/19 00:48:58 by cormarti         ###   ########.fr       */
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
}

void		plist_all(t_file *f)
{
	t_file	*curr;

	curr = f;
	plist(curr);
	while (curr)
	{
		if (curr->child)
			plist_all(curr->child);
//			printf("1%p\n", curr->child);
		curr = curr->next;
	}
}

int		pfiles(char **files)
{
	t_file		*f;
	t_max		*max;
	int			i;

	i = 0;
	max = new_max();
	f = new_file();
	if (!(files) || files[i] == NULL)
		return (0);
	lstat(files[0], &(f->sb));
	finfo(f, files);
	if (optab[0].verif)
		maxlengths_dir(f, max);
	while (f)
	{
		if (optab[0].verif)
			long_display(f, max);
		ft_putstr(files[i]);
		ft_putstr("\n");
		f = f->next;
	}
	free(f);
	return (1);
}
