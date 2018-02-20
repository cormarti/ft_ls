/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:42:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/18 23:36:21 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**lexico_sort(char **args)
{
	char		*tmp;
	int			i;
	int			j;

	i = 1;
	j = 0;
	tmp = NULL;
	if (args == NULL)
	{
		free(args);
		return (NULL);
	}
	while (args[i])
	{
		j = i;
		while (j > 0 && ft_strcmp(args[j], args[j - 1]) < 0)
		{
			tmp = ft_strdup(args[j]);
			free(args[j]);
			args[j] = ft_strdup(args[j - 1]);
			free(args[j - 1]);
			args[j - 1] = ft_strdup(tmp);
			free(tmp);
			j--;
		}
		i++;
	}
	return (args);
}

char	**modtime_sort(char **args)
{
	char		*tmp;
	int			i;
	int			j;
	struct stat	sb1;
	struct stat	sb2;

	i = 1;
	j = 0;
	tmp = NULL;
	if (args == NULL)
		return (NULL);
	while (args[i])
	{
		j = i;
		lstat(args[i], &sb1);
		lstat(args[i - 1], &sb2);
		while (j > 0 && sb1.st_mtime > sb2.st_mtime)
		{
			tmp = ft_strdup(args[j]);
			args[j] = ft_strdup(args[j - 1]);
			args[j - 1] = ft_strdup(tmp);
			free(tmp);
			j--;
		}
		i++;
	}
	return (args);
}
