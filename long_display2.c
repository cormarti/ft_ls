/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:45:01 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/19 00:48:04 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	psize(off_t size, int maxsize)
{
	int		diff;
	char	*name;

	name = ft_itoa(size);
	diff = ft_strlen(name);
	free(name);
	ft_putstr("  ");
	while (diff != maxsize)
	{
		ft_putstr(" ");
		diff++;
	}
	ft_putnbr(size);
}

void	pdate(time_t mtime)
{
	struct tm	*tinfo;
	int 		diff;

	tinfo = localtime(&mtime);
	ft_putstr(" ");
	ft_putstr(montab[tinfo->tm_mon].name);
	ft_putstr(" ");
	if (tinfo->tm_mday < 10)
		ft_putstr(" ");
	ft_putnbr(tinfo->tm_mday);
	ft_putstr(" ");
	if (mtime < ((unsigned long)time(NULL) + 15552000)
		&& mtime > ((unsigned long)time(NULL) - 15552000))
	{
		if (tinfo->tm_hour < 10)
			ft_putstr("0");
		ft_putnbr(tinfo->tm_hour);
		ft_putstr(":");
		if (tinfo->tm_min < 10)
			ft_putstr("0");
		ft_putnbr(tinfo->tm_min);
	}
	else
	{
		ft_putstr(" ");
		ft_putnbr(1900 + tinfo->tm_year);
	}
}

void	maxlengths_dir(t_file *f, t_max *max)
{
	t_file			*curr;
	char			*name;
	int				local_max[4];

	curr = f;
	while (curr)
	{
		name = ft_itoa(curr->sb.st_size);
		local_max[0] = ft_strlen(name);
		free(name);
		name = ft_itoa(curr->sb.st_nlink);
		local_max[2] = ft_strlen(name);
		free(name);
		local_max[3] = ft_strlen(getpwuid(curr->sb.st_uid)->pw_name);
		local_max[1] = ft_strlen(getgrgid(curr->sb.st_gid)->gr_name);
		if (local_max[0] > max->maxsize)
			max->maxsize = local_max[0];
		if (local_max[2] > max->maxlink)
			max->maxlink = local_max[2];
		if (local_max[3] > max->maxuid)
			max->maxuid = local_max[3];
		if (local_max[1] > max->maxgid)
			max->maxgid = local_max[1];
		curr = curr->next;
	}
	ft_putstr("total ");
	ft_putnbr(f->sb.st_blocks);
	ft_putstr("\n");
}

