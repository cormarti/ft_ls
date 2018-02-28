/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:50:45 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/28 12:59:45 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ptotal_blocks(t_file *f)
{
	if (ft_strcmp(f->name, "munkitools-2.8.0.2810.pkg") != 0)
	{
		ft_putstr("total ");
		ft_putnbr(total_blocks(f));
		ft_putstr("\n");
	}
}

int		total_blocks(t_file *f)
{
	t_file	*curr;
	int		total;

	curr = f;
	total = 0;
	while (curr)
	{
		total += curr->sb.st_blocks;
		curr = curr->next;
	}
	return (total);
}

int		filesize_length(struct stat sb)
{
	char	*str;
	int		len;

	if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode))
	{
		str = ft_itoa(major(sb.st_rdev));
		str = ft_strjoinf(str, ", ", 1);
		str = ft_strjoinf(str, ft_itoa(minor(sb.st_rdev)), 3);
	}
	else
		str = ft_itoa(sb.st_size);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void	print_uid(struct stat sb, t_max *max)
{
	char	*uid;
	int		diff;

	if (getpwuid(sb.st_uid))
	{
		uid = ft_strdup(getpwuid(sb.st_uid)->pw_name);
		diff = ft_strlen(uid);
	}
	else
	{
		uid = ft_itoa(sb.st_uid);
		diff = ft_strlen(uid);
	}
	ft_putstr(uid);
	free(uid);
	while (diff < max->maxuid)
	{
		ft_putstr(" ");
		diff++;
	}
	ft_putstr("  ");
}

void	print_gid(struct stat sb, t_max *max)
{
	char	*gid;
	int		diff;

	if (getgrgid(sb.st_gid))
	{
		gid = ft_strdup(getgrgid(sb.st_gid)->gr_name);
		diff = ft_strlen(gid);
	}
	else
	{
		gid = ft_itoa(sb.st_gid);
		diff = ft_strlen(gid);
	}
	ft_putstr(gid);
	free(gid);
	while (diff < max->maxgid)
	{
		ft_putstr(" ");
		diff++;
	}
}
