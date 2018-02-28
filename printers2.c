/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:44:04 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 14:49:34 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	pfile_details(t_file *f, t_max *max)
{
	if (optab[0].verif)
		long_display(f, max);
	else
		ft_putstr(f->name);
	ft_putstr("\n");
}

void	spfile_details(t_file *f, char **files, t_max *max)
{
	t_file	*curr;
	int		i;

	i = 0;
	curr = f;
	while (curr)
	{
		if (optab[0].verif)
			long_display(curr, max);
		else
			ft_putstr(files[i]);
		free(files[i]);
		i++;
		ft_putstr("\n");
		if (!(curr->next) && optab[0].verif && curr->name)
			free(max);
		curr = curr->next;
	}
}
