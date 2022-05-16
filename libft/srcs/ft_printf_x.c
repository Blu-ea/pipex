/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:04:15 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_convertbase_x(unsigned int nb, char *base)
{
	char	*nb_in_hex;
	int		size_nb;

	size_nb = ft_calcsize_x(nb);
	nb_in_hex = malloc(sizeof(char) * (size_nb + 1));
	if (!nb_in_hex)
		return (0);
	nb_in_hex[size_nb] = 0;
	ft_fill_str_x(nb_in_hex, nb, base, size_nb - 1);
	ft_printstr(nb_in_hex);
	free(nb_in_hex);
	return (size_nb);
}

int	ft_calcsize_x(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_fill_str_x(char *nb_hex, unsigned int nb_int, char *base, int i)
{
	while (nb_int > 15)
	{
		nb_hex[i] = base[nb_int % 16];
		nb_int = nb_int / 16;
		i--;
	}
	nb_hex[i] = base[nb_int % 16];
}
