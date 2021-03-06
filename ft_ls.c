/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:26:09 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/26 22:43:38 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "extab.h"

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	parse_opt(argc, argv);
	path_is_valid(argc, argv);
	pfiles(extract_nodir(argc, argv));
	dir_process(extract_dir(argc, argv));
	return (0);
}
