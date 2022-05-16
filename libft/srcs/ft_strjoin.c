/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:57:32 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:55:04 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	s_ret = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_ret)
		return (NULL);
	while (s1[++i])
	{
		s_ret[j] = s1 [i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		s_ret[j] = s2[i];
		j++;
	}
	s_ret[j] = '\0';
	return (s_ret);
}
