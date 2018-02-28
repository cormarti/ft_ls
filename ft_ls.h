/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:53:52 by cormarti          #+#    #+#             */
/*   Updated: 2018/02/28 12:22:54 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"
# include <time.h>
# include <stdio.h>

typedef	struct s_file	t_file;
typedef struct s_dir	t_dir;
typedef struct s_max	t_max;

struct	s_file
{
	struct dirent		*dt;
	struct stat			sb;
	char				*name;
	int					error;
	char				*path;
	t_file				*child;
	t_file				*next;
};

struct	s_max
{
	int					maxsize;
	int					maxlink;
	int					maxuid;
	int					maxgid;
};

struct	s_dir
{
	t_file				*file;
	t_dir				*next;
};

struct	s_mon
{
	char				*name;
};

struct	s_opt
{
	char				name;
	int					verif;
};

extern struct s_mon		montab[];
extern struct s_opt		optab[];

int		parse_opt(int nb_arg, char **args);
void	path_is_valid(int nb_arg, char **args);
char	**lexico_sort(char **args, int isvalid);
char	**modtime_sort(char **args, int isvalid);
char	**extract_nodir(int nb_arg, char **args);
char	**extract_dir(int nb_arg, char **args);
int		pfiles(char **files);
int		dir_process(char **paths);
int		files_process(DIR *dir, char *path, t_file *f);
void	plist(t_file *f, char *path, char *name, int ischild);
int		file_push_back(t_file *f, DIR *dir, char *path);
void	recursively_add_lists(t_file *f);
t_file	*plist_all(t_file *f, char *path, char *name, int ischild);
t_file	*new_file(void);
t_max	*new_max(void);
void	long_display(t_file *f, t_max *max);
void	psize(struct stat sb, int maxlen);
void	maxlengths_dir(t_file *f, t_max *max, int isdir);
void	pdate(time_t mtime);
int		pfile_type(mode_t mode);
void	prights(mode_t mode);
void	plinks(nlink_t nlink, int maxlink);
void	powners(struct stat sb, t_max *max);
void	finfo(t_file *f, char **args);
void	free_file(t_file *f);
t_file	*lexico_struct_sort(t_file *f);
t_file	*reverse_sort(t_file *f);
t_file	*modtime_struct_sort(t_file *f);
void	set_error(t_file *f, char *name);
void	print_error(t_file *f);
char	*extract_deep_dir(char *path);
void	ppath(t_file *f, char *path, char *name, int ischild);
void	plink_path(t_file *f, int target);
void	free_node(t_file *f);
int		owner_maxlength(t_file *f, int owner);
void	print_uid(struct stat sb, t_max *max);
void	print_gid(struct stat sb, t_max *max);
int		total_blocks(t_file *f);
void	error_handler(t_file *f, char *path);
void	ptotal_blocks(t_file *f);
void	pfile_details(t_file *f, t_max *max);
void	spfile_details(t_file *f, char **files, t_max *max);
int		filesize_length(struct stat sb);

#endif
