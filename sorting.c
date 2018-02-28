/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:42:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/27 15:06:20 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**reverse(char **args)
{
	char		*tmp;
	int			i;
	int			max;

	i = 0;
	max = 0;
	while (args[max])
		max++;
	max--;
	while (args[i] && max > i)
	{
		tmp = ft_strdup(args[i]);
		free(args[i]);
		args[i] = ft_strdup(args[max]);
		free(args[max]);
		args[max] = ft_strdup(tmp);
		free(tmp);
		max--;
		i++;
	}
	return (args);
}

char		**lexico_sort(char **args, int isvalid)
{
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (args == NULL || args[i] == NULL)
		return (args);
	while (args[i])
	{
		j = i;
		while (args[j] && j > 0 && ft_strcmp(args[j], args[j - 1]) < 0)
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
	return (optab[3].verif && isvalid ? reverse(args) : args);
}

t_file		*modtime_struct_sort(t_file *f)
{
	t_file		*curr;
	t_file		*next;
	t_file		*prev;
	t_file		*test;

	test = f;
	while (test)
	{
		curr = f;
		next = curr->next;
		prev = NULL;
		while (next)
		{
			if (curr->sb.st_mtime < next->sb.st_mtime)
			{
				if (curr == f)
					f = next;
				else
					prev->next = next;
				curr->next = next->next;
				next->next = curr;
				prev = next;
				next = curr->next;
			}
			else
			{
				prev = curr;
				curr = curr->next;
				next = curr->next;
			}
		}
		test = test->next;
	}
	return (f);
}

t_file		*reverse_sort(t_file *f)
{
	t_file		*curr;
	t_file		*next;
	t_file		*prev;

	curr = f;
	next = NULL;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	f = prev;
	return (f);
}

char		**modtime_sort(char **args, int isvalid)
{
	char		*tmp;
	int			cpt[2];
	struct stat	sb[2];

	cpt[0] = 0;
	cpt[1] = 0;
	if (args == NULL)
		return (NULL);
	while (args[cpt[0]])
	{
		cpt[1] = cpt[0];
		lstat(args[cpt[0]], &sb[0]);
		lstat(args[cpt[0] - 1], &sb[1]);
		while (cpt[1] > 0 && sb[0].st_mtime > sb[1].st_mtime)
		{
			tmp = ft_strdup(args[cpt[1]]);
			free(args[cpt[1]]);
			args[cpt[1]] = ft_strdup(args[cpt[1] - 1]);
			free(args[cpt[1] - 1]);
			args[cpt[1]-- - 1] = ft_strdup(tmp);
			free(tmp);
		}
		cpt[0]++;
	}
	return (optab[3].verif && isvalid ? reverse(args) : args);
}
