/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:26:50 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 13:22:35 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		files_process(DIR *dir, char *path, t_file *f)
{
	int		i;

	i = 0;
	if (!(f->dt = readdir(dir)))
		return (0);
	while (!(optab[2].verif) && f->dt->d_name[0] == '.')
		if (!(f->dt = readdir(dir)))
			return (0);
	f->name = ft_strdup(f->dt->d_name);
	f->path = ft_strdup(path);
	path = ft_strjoin(f->path, "/");
	path = ft_strjoinf(path, f->name, 1);
	lstat(path, &(f->sb));
	free(path);
	while (file_push_back(f, dir, f->path) != 0)
		(void)i;
	if (optab[1].verif == 1)
		recursively_add_lists(f);
	f = plist_all(f, f->path, f->name, 0);
	free_file(f);
	return (1);
}
