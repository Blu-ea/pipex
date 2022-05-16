/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:06:51 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long int	i;
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	i = -1;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while ((size_t)++i < len)
		{
			d[i] = s[i];
		}
	}
	else
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}
