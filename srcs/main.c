/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:55 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/16 15:02:43 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	t_pipe	data;
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	pipe(data.fd);
	printf("fd[0] = %d\nfd[1] = %d\n", data.fd[0], data.fd[1]);
	printf ("fd = %d\n", fd);
	close(fd);
}
