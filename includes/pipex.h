/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/18 23:08:06 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipe
{
	int		fd[2];
	char	**cmd[2];
	char	*path[2];
	pid_t	pid;
}					t_pipe;

//////////// main.c ////////////

// int		main(int argc, char **argv);
void	ft_error(char *str);

/////////// parsing.c //////////

void	parsing(int argc, char **argv, char **env, t_pipe *data);
char	*find_path(char *cmd, char *env);

/////////// debug.c ////////////

void	ft_print_tab(char **tab, char *name);

#endif