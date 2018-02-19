/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:50:07 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/17 08:29:35 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		punvalid_path(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		ft_putstr("ft_ls: ");
		perror(args[i]);
		i++;
	}
}

void			path_is_valid(int nb_arg, char **args)
{
	struct stat	sb;
	int			i;
	int			j;
	char		*unvalid_path[nb_arg];

	i = 1;
	j = 0;
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
	punvalid_path(lexico_sort(unvalid_path));
}
