/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/21 09:23:12 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipe
{
	int		pipe[2];
	int		pid;
	char	**cmd[3];
	char	*path[3];
}					t_pipe;

//////////// main.c ////////////

// int		main(int argc, char **argv);
void	ft_error(char *str);
void	ft_first_proc(t_pipe *data, char **env, char *infile);
void	ft_second_proc(t_pipe *data, char **env, char *outfile);
void	ft_leave(t_pipe data);

/////////// parsing.c //////////

void	parsing(int argc, char **argv, char **env, t_pipe *data);
char	*find_path(char *cmd, char *env);
void	chek_pipe(t_pipe data);

/////////// debug.c ////////////

void	ft_print_tab(char **tab, char *name);

#endif