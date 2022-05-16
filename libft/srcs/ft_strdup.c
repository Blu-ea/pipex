/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 02:34:42 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i])
		i++;
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (i--)
		ret[i] = src[i];
	ret[0] = src[0];
	return (ret);
}
