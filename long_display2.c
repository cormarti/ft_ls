/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:45:01 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/28 12:36:34 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	plink_path(t_file *f, int target)
{
	char	buf[255];
	size_t	len;
	char	*path;

	ft_putstr(" -> ");
	if (!target)
		len = readlink(f->name, buf, 255);
	else
	{
		path = ft_strjoin(f->path, "/");
		path = ft_strjoinf(path, f->name, 1);
		len = readlink(path, buf, 255);
		free(path);
	}
	buf[len] = '\0';
	ft_putstr(buf);
}

void	psize(struct stat sb, int maxsize)
{
	int			diff;
	char		*name;

	if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
	{
		name = ft_itoa(major(sb.st_rdev));
		name = ft_strjoinf(name, ", ", 1);
		name = ft_strjoinf(name, ft_itoa(minor(sb.st_rdev)), 3);
	}
	else
		name = ft_itoa(sb.st_size);
	diff = ft_strlen(name);
	ft_putstr("  ");
	while (diff < maxsize)
	{
		ft_putstr(" ");
		diff++;
	}
	ft_putstr(name);
	free(name);
}

void	pdate(time_t mtime)
{
	struct tm	*tinfo;

	tinfo = localtime(&mtime);
	ft_putstr(" ");
	ft_putstr(montab[tinfo->tm_mon].name);
	ft_putstr(" ");
	if (tinfo->tm_mday < 10)
		ft_putstr(" ");
	ft_putnbr(tinfo->tm_mday);
	ft_putstr(" ");
	if (mtime < (time(NULL) + 15552000) && mtime > (time(NULL) - 15552000))
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

int		owner_maxlength(t_file *f, int owner)
{
	char	*tmp;
	int		len;

	if (owner == 0)
	{
		if (getpwuid(f->sb.st_uid))
			len = ft_strlen(getpwuid(f->sb.st_uid)->pw_name);
		else
		{
			tmp = ft_itoa(f->sb.st_uid);
			len = ft_strlen(tmp);
			free(tmp);
		}
		return (len);
	}
	if (getgrgid(f->sb.st_gid))
		len = ft_strlen(getgrgid(f->sb.st_gid)->gr_name);
	else
	{
		tmp = ft_itoa(f->sb.st_gid);
		len = ft_strlen(tmp);
		free(tmp);
	}
	return (len);
}

void	maxlengths_dir(t_file *f, t_max *max, int isdir)
{
	t_file		*curr;
	char		*name;
	int			lmax[4];

	curr = f;
	while (curr)
	{
		lmax[0] = filesize_length(curr->sb);
		name = ft_itoa(curr->sb.st_nlink);
		lmax[2] = ft_strlen(name);
		free(name);
		lmax[3] = owner_maxlength(curr, 0);
		lmax[1] = owner_maxlength(curr, 1);
		lmax[1] = ft_strlen(getgrgid(curr->sb.st_gid)->gr_name);
		max->maxsize = lmax[0] > max->maxsize ? lmax[0] : max->maxsize;
		max->maxlink = lmax[2] > max->maxlink ? lmax[2] : max->maxlink;
		max->maxuid = lmax[3] > max->maxuid ? lmax[3] : max->maxuid;
		max->maxgid = lmax[1] > max->maxgid ? lmax[1] : max->maxgid;
		curr = curr->next;
	}
	if (isdir)
		ptotal_blocks(f);
}
