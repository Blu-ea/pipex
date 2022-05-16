/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:35:25 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long int	ft_start(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

unsigned long int	ft_end(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;

	i = ft_strlen(s1);
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i - 1] && i - 1)
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long int	end;
	unsigned long int	start;
	char				*ret_str;
	unsigned long int	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	else
	{
		ret_str = malloc ((end - start) + 1);
		if (!ret_str)
			return (NULL);
		while (start < end)
		{
			ret_str[i++] = s1[start];
			start++;
		}
		ret_str[i] = '\0';
	}
	return (ret_str);
}
