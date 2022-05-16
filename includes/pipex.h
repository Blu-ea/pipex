/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/16 15:00:54 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <unistd.h> // read, write, close, pipe, execve
#include <fcntl.h> // open

typedef struct s_pipe
{
	int				fd[2];
}					t_pipe;

//////////// main.c ////////////

int		main(int argc, char **argv);

/////////// parsing.c //////////

void	parsing(int argc, char **argv);
void	ft_error(char *str);

#endif