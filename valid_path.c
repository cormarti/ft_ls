/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:50:07 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 14:14:01 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		punvalid_path(char **args)
{
	int			i;

	i = 0;
	while (args[i])
	{
		ft_putstr("ft_ls: ");
		perror(args[i]);
		free(args[i]);
		i++;
	}
	free(args);
}

void			path_is_valid(int nb_arg, char **args)
{
	struct stat	sb;
	int			i;
	int			j;
	char		**unvalid_path;

	i = 1;
	j = 0;
	if (!(unvalid_path = malloc(sizeof(char*) * (nb_arg + 1))))
		exit(0);
	unvalid_path[nb_arg] = NULL;
	while (args[i] && args[i][0] == '-' && args[i][1])
		i++;
	while (args[i])
	{
		if (lstat(args[i], &sb) != 0)
		{
			unvalid_path[j] = ft_strdup(args[i]);
			j++;
		}
		i++;
	}
	unvalid_path[j] = NULL;
	punvalid_path(lexico_sort(unvalid_path, 0));
}
