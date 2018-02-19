/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:16:40 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/18 23:35:18 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**extract_nodir(int nb_arg, char **args)
{
	int				i;
	int				j;
	char			**nodir;
	struct stat		sb;

	i = 1;
	j = 0;
	if (!(args) || !(nodir = malloc(sizeof(char*) * nb_arg + 1)))
		return (NULL);
	nodir[nb_arg] = NULL;
	while (args[i] && args[i][0] == '-')
		i++;
	while (args[i])
	{
		if (lstat(args[i], &sb) == 0 && (!(S_ISDIR(sb.st_mode))))
		{
			nodir[j] = ft_strdup(args[i]);
			j++;
		}
		i++;
	}
	if (j == 0)
		return (NULL);
	nodir[j] = NULL;
	return (lexico_sort(nodir));
}


char	**extract_dir(int nb_arg, char **args)
{
	int				i;
	int				j;
	char			**dir;
	struct stat		sb;

	i = 1;
	j = 0;
	if (!(args) || !(dir = malloc(sizeof(char*) * nb_arg + 1)))
		return (NULL);
	dir[nb_arg] = NULL;
	while (args[i] && args[i][0] == '-')
		i++;
	while (args[i])
	{
		if (lstat(args[i], &sb) == 0 && S_ISDIR(sb.st_mode)
			&& (args[i][0] != '.' || optab[2].verif) 
			&& ft_strcmp(args[i], ".") != 0	&& ft_strcmp(args[i], "..") != 0)
		{
			dir[j] = ft_strdup(args[i]);
			j++;
		}
		i++;
	}
	if (j == 0)
		dir[j] = ft_strdup(".");
	dir[j] = NULL;
	return (lexico_sort(dir));
}
