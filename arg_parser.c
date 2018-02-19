/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 06:23:28 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/13 13:48:43 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		valid_opt(char letter)
{
	int		i;

	i = 0;
	while (optab[i].name)
	{
		if (optab[i].name == letter)
		{
			optab[i].verif = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

static void		set_opts(char *arg)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (!(valid_opt(arg[i])))
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(arg[i]);
			ft_putstr("\n");
			ft_putstr("usage: ls [-Ralrt] [file ...]\n");
			exit(0);
		}
		i++;
	}
}

int				parse_opt(int nb_arg, char **args)
{
	int		i;

	i = 1;
	if (nb_arg <= 1)
		return (1);
	while (i < nb_arg)
	{
		if (args && args[i][0] != '-')
			return (1);
		set_opts(args[i]);
		i++;
	}
	return (1);
}
