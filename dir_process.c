/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:09:00 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/21 07:39:29 by cormarti         ###   ########.fr       */
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
		return (0);;
	if (!paths[i])
	{
		free(paths);
		return (0);
	}
	while (paths[i])
	{
		f = new_file();
		f->path = ft_strdup(paths[i]);
		dir = opendir(paths[i]);
		if (files_process(dir, paths[i], f) == 0)
			perror("error ");
		closedir(dir);
		free(paths[i]);
		f = NULL;
		i++;
	}
	free(paths);
	ft_putstr("\n---- end ----\n");
	return (1);
}
