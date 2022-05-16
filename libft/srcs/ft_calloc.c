/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 01:22:20 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long int	i;
	char				*str_ret;

	i = 0;
	str_ret = malloc (count * size);
	if (!str_ret)
		return (NULL);
	while (i < count * size)
	{
		str_ret[i] = 0;
		i++;
	}
	return (str_ret);
}
