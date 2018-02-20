/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 09:14:36 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/18 21:54:38 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		pfile_type(mode_t mode)
{
	if (mode & S_IFREG)
		ft_putstr("-");
	else if (mode & S_IFDIR)
		ft_putstr("d");
	else if (mode & S_IFBLK)
		ft_putstr("b");
	else if (mode & S_IFCHR)
		ft_putstr("c");
	else if (mode & S_IFIFO)
		ft_putstr("p");
	else if (mode & S_IFLNK)
		ft_putstr("l");
	else if (mode & S_IFSOCK)
		ft_putstr("s");
	else
		ft_putstr("?");
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
		ft_putstr("T");
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

void		powners(struct stat sb, t_max *max)
{
	int		diff;
	char	len;
	char	*owner;

	ft_putstr(getpwuid(sb.st_uid)->pw_name);
	owner = ft_strdup(getpwuid(sb.st_uid)->pw_name);
	diff = ft_strlen(owner);
	free(owner);
	while (diff < max->maxuid)
	{
		ft_putstr(" ");
		diff++;
	}
	ft_putstr("  ");
	owner = ft_strdup(getgrgid(sb.st_gid)->gr_name);
	diff = ft_strlen(owner);
	free(owner);
	ft_putstr(getgrgid(sb.st_gid)->gr_name);
	while (diff < max->maxgid)
	{
		ft_putstr(" ");
		diff++;
	}
}

void			long_display(t_file *f, t_max *max)
{
	pfile_type(f->sb.st_mode);
	prights(f->sb.st_mode);
	plinks(f->sb.st_nlink, max->maxlink);
	powners(f->sb, max);
	psize(f->sb.st_size, max->maxsize);
	pdate(f->sb.st_mtime);
	ft_putstr(" ");
}
