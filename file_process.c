/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:26:50 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/18 17:46:18 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		files_process(DIR *dir, char *path, t_file *f)
{
	int		i;
	char	*newpath;

	i = 0;
	if (!(f->dt = readdir(dir)))
		exit(0);
	while (!(optab[2].verif) && f->dt->d_name[0] == '.')
		if (!(f->dt = readdir(dir)))
			exit(0);
	f->name = ft_strdup(f->dt->d_name);
	f->path = ft_strdup(path);
	path = ft_strjoin(path, "/");
//	f->type = ft_strdup(f->dt->d_type);
	newpath = ft_strjoin(path, f->name);
	stat(newpath, &(f->sb));
	free(newpath);
	while (file_push_back(f, dir, f->path) != 0)
	{
		/*if (optab[2].verif || f->dt->d_name[0] != '.')
		  {
		  ft_putstr(f->dt->d_name);
		  ft_putstr("\n");
		  }*/
	}
	if (optab[1].verif == 1)
		f = recursively_add_lists(f);
	plist_all(f);
	return (1);
}
