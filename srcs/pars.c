/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:56:47 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/18 23:25:55 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parsing(int argc, char **argv, char **env, t_pipe *data)
{
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	if (!*env)
		ft_error("No PATH found");
	data->cmd[0] = ft_split(argv[2], ' ');
	data->cmd[1] = ft_split(argv[3], ' ');
	ft_print_tab(data->cmd[0], "cmd[0]");
	data->path[0] = find_path(data->cmd[0][0], *env);
	data->path[1] = find_path(data->cmd[1][0], *env);
	if (!data->path[0] || !data->path[1])
		ft_error("Error: Command not found");
}

char	*find_path(char *cmd, char *env)
{
	char	*sub;
	char	*temp;
	char	**path;
	int		i;

	i = 0;
	sub = ft_substr(env, 5, ft_strlen(env) - 5);
	path = ft_split(sub, ':');
	free(sub);
	ft_print_tab(path, "path");
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		temp = ft_strjoin_gnl(temp, cmd);
		if (access(temp, F_OK) == 0)
		{
			free(path);
			return (temp);
		}
		free(temp);
		i++;
	}
	return (NULL);
}
