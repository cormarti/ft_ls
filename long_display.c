/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 09:14:36 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/28 12:55:52 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			pfile_type(mode_t mode)
{
	int		islink;

	islink = 0;
	if (S_ISLNK(mode))
	{
		ft_putstr("l");
		islink = 1;
	}
	else if (S_ISREG(mode))
		ft_putstr("-");
	else if (S_ISDIR(mode))
		ft_putstr("d");
	else if (S_ISBLK(mode))
		ft_putstr("b");
	else if (S_ISCHR(mode))
		ft_putstr("c");
	else if (S_ISFIFO(mode))
		ft_putstr("p");
	else if (S_ISSOCK(mode))
		ft_putstr("s");
	else
		ft_putstr("?");
	return (islink);
}

void		prights(mode_t mode)
{
	ft_putstr((mode & S_IRUSR) ? "r" : "-");
	ft_putstr((mode & S_IWUSR) ? "w" : "-");
	if (mode & S_ISUID)
		ft_putstr("S");
	else
		ft_putstr((mode & S_IXUSR) ? "x" : "-");
	ft_putstr((mode & S_IRGRP) ? "r" : "-");
	ft_putstr((mode & S_IWGRP) ? "w" : "-");
	if (mode & S_ISGID)
		ft_putstr("S");
	else
		ft_putstr((mode & S_IXGRP) ? "x" : "-");
	ft_putstr((mode & S_IROTH) ? "r" : "-");
	ft_putstr((mode & S_IWOTH) ? "w" : "-");
	if (mode & S_ISVTX)
		ft_putstr((mode & S_IXOTH) ? "t" : "T");
	else
		ft_putstr((mode & S_IXOTH) ? "x" : "-");
}

void		plinks(nlink_t nlink, int maxlink)
{
	int		diff;
	char	*name;

	name = ft_itoa(nlink);
	diff = ft_strlen(name);
	free(name);
	while (diff != maxlink)
	{
		ft_putstr(" ");
		diff++;
	}
	ft_putstr("  ");
	ft_putnbr(nlink);
	ft_putstr(" ");
}

void		long_display(t_file *f, t_max *max)
{
	int		islink;

	islink = 0;
	if (f->name && ft_strcmp(f->name, "munkitools-2.8.0.2810.pkg") != 0)
	{
		islink = pfile_type(f->sb.st_mode);
		prights(f->sb.st_mode);
		plinks(f->sb.st_nlink, max->maxlink);
		print_uid(f->sb, max);
		print_gid(f->sb, max);
		psize(f->sb, max->maxsize);
		pdate(f->sb.st_mtime);
		ft_putstr(" ");
		ft_putstr(f->name);
		if (islink == 1)
			plink_path(f, f->path ? 1 : 0);
	}
}
