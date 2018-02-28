/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:16:40 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 14:20:08 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**extract_nodir(int nb_arg, char **args)
{
	int				i;
	int				j;
	char			**nodir;
	struct stat		sb;

	i = 1;
	j = 0;
	if (!(args) || !(nodir = malloc(sizeof(char*) * (nb_arg + 1))))
		return (NULL);
	nodir[nb_arg] = NULL;
	while (args[i] && args[i][0] == '-')
		i++;
	while (args[i])
	{
		if (lstat(args[i], &sb) == 0 && (!(S_ISDIR(sb.st_mode)))
			&& (!(S_ISLNK(sb.st_mode)) || optab[0].verif))
		{
			nodir[j] = ft_strdup(args[i]);
			j++;
		}
		i++;
	}
	nodir[j] = NULL;
	return (optab[4].verif ? modtime_sort(nodir, 1) : lexico_sort(nodir, 1));
}

char	**extract_dir(int nb_arg, char **args)
{
	int				cpt[3];
	char			**dir;
	struct stat		sb;

	cpt[0] = 1;
	cpt[1] = 0;
	cpt[2] = 0;
	if (!(args) || !(dir = malloc(sizeof(char*) * (nb_arg + 1))))
		return (NULL);
	while (args[cpt[0]] && args[cpt[0]][0] == '-' && args[cpt[0]][1])
	{
		cpt[2]++;
		cpt[0]++;
	}
	while (args[cpt[0]])
	{
		if (lstat(args[cpt[0]], &sb) == 0 && (S_ISDIR(sb.st_mode)
			|| (S_ISLNK(sb.st_mode) && !(optab[0].verif))))
			dir[cpt[1]++] = ft_strdup(args[cpt[0]]);
		cpt[0]++;
	}
	if (cpt[1] == 0 && cpt[0] - 1 == cpt[2])
		dir[cpt[1]++] = ft_strdup(".");
	dir[cpt[1]] = NULL;
	return (optab[4].verif ? modtime_sort(dir, 1) : lexico_sort(dir, 1));
}

char	*extract_deep_dir(char *path)
{
	char	*name;

	while (ft_strchr(path, '/') != NULL)
	{
		path = ft_strchr(path, '/');
		path++;
	}
	name = ft_strdup(path);
	return (name);
}
