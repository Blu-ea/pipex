/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:08:44 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ret_nl(char *ln, int i)
{
	if (i == -1)
	{
		free (ln);
		return (NULL);
	}
	return (ln);
}

char	*ft_strjoin_gnl(char *line, char *temp)
{
	char	*s_ret;
	int		i;
	int		j;

	if (!line)
		return (ft_strdup(temp));
	i = -1;
	j = 0;
	s_ret = malloc (sizeof(char) * (ft_strlen(line) + ft_strlen(temp) + 1));
	if (!s_ret)
		return (NULL);
	while (line[++i])
	{
		s_ret[j] = line [i];
		j++;
	}
	i = -1;
	while (temp[++i])
	{
		s_ret[j] = temp[i];
		j++;
	}
	s_ret[j] = '\0';
	free(line);
	return (s_ret);
}
