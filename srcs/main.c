/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:55 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/21 09:26:54 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipe	data;

	if (argc != 5)
		ft_error("Usage : ./pipex <infile> <cmd1> <cmd2> <outfile>");
	parsing(argc, argv, env, &data);
	pipe(data.pipe);
	chek_pipe(data);
	ft_first_proc(&data, env, argv[1]);
	ft_second_proc(&data, env, argv[4]);
	ft_leave(data);
}

void	ft_error(char *str)
{
	perror(str);
	exit(0);
}

void	ft_first_proc(t_pipe *data, char **env, char *infile)
{
	int		fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Open failed");
	data->pid = fork();
	if (data->pid != 0)
	{
		close (data->pipe[0]);
		dup2(data->pipe[1], STDOUT_FILENO);
		dup2(fd, STDIN_FILENO);
		execve (data->path[0], data->cmd[0], env);
		ft_error("Error: Execve 1 failed");
	}
	// waitpid(data->pid, NULL, 0);
	close(fd);
}

void	ft_second_proc(t_pipe *data, char **env, char *outfile)
{
	int		fd;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
		ft_error("Error: Open failed");
	data->pid = fork();
	if (data->pid != 0)
	{	
		close(data->pipe[1]);
		dup2(data->pipe[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		ft_error("test\n");
		execve (data->path[0], data->cmd[0], env);
		ft_error("Error: Execve 2 failed");
	}
	waitpid(data->pid, NULL, 0);
	close(fd);
}

void	ft_leave(t_pipe data)
{
	close(data.pipe[0]);
	close(data.pipe[1]);
	free(data.path[0]);
	free(data.path[1]);
	free(data.cmd[0][0]);
	free(data.cmd[0][1]);
	free(data.cmd[1][0]);
	free(data.cmd[1][1]);
	exit(0);
}