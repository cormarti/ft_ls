/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 23:48:13 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 07:06:19 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_error(t_file *f)
{
	if (f->error)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(f->name);
		ft_putstr(": ");
		ft_putstr(strerror(f->error));
		ft_putstr("\n");
	}
}

void		set_error(t_file *f, char *name)
{
	char	*realname;

	realname = extract_deep_dir(name);
	f->error = errno;
	f->name = ft_strdup(realname);
	free(realname);
}
