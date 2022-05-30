/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:56:47 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 07:43:07 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parsing(int argc, char **argv, char **env, t_pipe *data)
{
	if (argc != 5)
	{
		ft_printf("Usage : ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		exit(1);
	}
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	data->cmd[0] = ft_split(argv[2], ' ');
	data->cmd[1] = ft_split(argv[3], ' ');
	data->path[0] = find_path(data->cmd[0][0], *env);
	data->path[1] = find_path(data->cmd[1][0], *env);
	if (!data->path[0] || !data->path[1])
		ft_error("Error: Command not found", data);
	data->path[2] = NULL;
	data->cmd[2] = NULL;
}

char	*find_path(char *cmd, char *env)
{
	char	*sub;
	char	**path;
	int		i;

	i = 0;
	if (env)
	{
		sub = ft_substr(env, 5, ft_strlen(env) - 5);
		path = ft_split(sub, ':');
		free(sub);
		while (path[i])
		{
			sub = ft_strjoin(path[i], "/");
			sub = ft_strjoin_gnl(sub, cmd);
			if (access(sub, F_OK) == 0)
				return (ft_return_pars(&path, &sub));
			free(sub);
			i++;
		}
		ft_free_path(path);
	}
	if (access(cmd, F_OK) == 0)
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	return (NULL);
}

char	*ft_return_pars(char ***path, char **sub)
{
	ft_free_path(*path);
	return (*sub);
}

void	chek_pipe(t_pipe *data)
{
	if (data->path[0] == NULL)
		ft_error("Error: Pipe bug", data);
	if (data->path[1] == NULL)
		ft_error("Error: Pipe bug", data);
}

void	ft_free_path(char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
