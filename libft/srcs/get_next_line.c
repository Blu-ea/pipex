/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:31:06 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:47:42 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	char static	stat[OPEN_MAX][BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	int			i;

	line = 0;
	i = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (*stat[fd])
	{
		line = ft_strdup(stat[fd]);
		*stat[fd] = 0;
	}
	while (chek_nl(line) == -1 && i == BUFFER_SIZE)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i <= 0)
			return (ret_nl(line, i));
		temp[i] = '\0';
		line = ft_strjoin_gnl(line, temp);
	}
	if (chek_nl(line) != -1)
		set_nl(line, (char *)stat[fd]);
	return (line);
}

int	chek_nl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	set_nl(char *line, char *stat)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(&line[chek_nl(line) + 1]);
	line[chek_nl(line) + 1] = '\0';
	while (temp[i])
	{
		stat[i] = temp[i];
		i++;
	}
	stat[i] = 0;
	free (temp);
}
