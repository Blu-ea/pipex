/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/27 09:06:47 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	int		pipe[2];
	int		pid[2];
	char	**cmd[3];
	char	*path[3];
}					t_pipe;

//////////// main.c ////////////

// int		main(int argc, char **argv);
void	ft_error(char *str, t_pipe *data);
void	ft_first_proc(t_pipe *data, char **env, char *infile);
void	ft_second_proc(t_pipe *data, char **env, char *outfile);
void	ft_leave(t_pipe data);

/////////// parsing.c //////////

void	parsing(int argc, char **argv, char **env, t_pipe *data);
char	*find_path(char *cmd, char *env);
void	chek_pipe(t_pipe *data);
void	ft_free_path(char **path);
char	*ft_return_pars(char ***path, char **sub);

/////////// debug.c ////////////

void	ft_print_tab(char **tab, char *name);

#endif
