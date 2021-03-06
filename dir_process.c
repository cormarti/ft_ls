/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:09:00 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 13:25:56 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		dir_process(char **paths)
{
	DIR		*dir;
	t_file	*f;
	int		i;

	i = 0;
	if (!paths)
		return (0);
	while (paths[i])
	{
		f = new_file();
		if (!(dir = opendir(paths[i])))
			error_handler(f, paths[i]);
		else
		{
			ft_putstr("\n");
			files_process(dir, paths[i], f);
			closedir(dir);
		}
		free(paths[i]);
		i++;
		f = NULL;
	}
	free(paths);
	return (1);
}

void	error_handler(t_file *f, char *path)
{
	set_error(f, path);
	ppath(f, path, path, 0);
	print_error(f);
	free_file(f);
}
