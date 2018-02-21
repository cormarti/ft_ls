/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:42:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/21 11:36:19 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**lexico_sort(char **args)
{
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (args == NULL || args[i] == NULL)
	{
		//free(args);
		return (args);
	}
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
	return (args);
}

t_file	*lexico_struct_sort(t_file *f)
{
	t_file	*curr;
	t_file	*next;
	t_file	*prev;
	t_file	*test;

	test = f;
	while (test)
	{
		curr = f;
		next = curr->next;
		prev = NULL;
		while (next)
		{
			if (ft_strcmp(curr->name, next->name) > 0)
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

t_file	*modtime_struct_sort(t_file *f)
{
	t_file	*curr;
	t_file	*next;
	t_file	*prev;
	t_file	*test;
	struct stat	sb1;
	struct stat	sb2;

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

t_file	*reverse_sort(t_file *f)
{
	t_file	*prev;
	t_file	*next;

	prev = NULL;
	while (f)
	{
		next = f->next;
		f->next = prev;
		prev = f;
		f = next;
	}
	return (prev);
}

char	**modtime_sort(char **args)
{
	char		*tmp;
	int			i;
	int			j;
	struct stat	sb1;
	struct stat	sb2;

	i = 0;
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
