/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:44:55 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/18 20:09:27 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_str;
	size_t	i;
	size_t	mal_size;

	if (!s)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	mal_size = len;
	if ((size_t)ft_strlen(s) < len)
		mal_size = ft_strlen(s);
	ret_str = malloc (sizeof (char) * mal_size + 1);
	if (!ret_str)
		return (NULL);
	ret_str[mal_size] = '\0';
	while (i < mal_size && s[start])
	{
		ret_str[i] = s[start];
		start++;
		i++;
	}
	return (ret_str);
}
