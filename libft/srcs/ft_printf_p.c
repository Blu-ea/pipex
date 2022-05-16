/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:00:49 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:48:34 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_convertbase_p(unsigned long long int nb, char *base)
{
	char	*nb_in_hex;
	int		size_nb;

	write(1, "0x", 2);
	size_nb = ft_calcsize_p(nb);
	nb_in_hex = malloc(sizeof(char) * (size_nb + 1));
	if (!nb_in_hex)
		return (0);
	nb_in_hex[size_nb] = 0;
	ft_fill_str_p(nb_in_hex, nb, base, size_nb - 1);
	ft_printstr(nb_in_hex);
	free(nb_in_hex);
	return (size_nb + 2);
}

int	ft_calcsize_p(unsigned long long int nb)
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

void	ft_fill_str_p(char *nb_hex, unsigned long long int nb_int,
			char *base, int i)
{
	while (nb_int > 15)
	{
		nb_hex[i] = base[nb_int % 16];
		nb_int = nb_int / 16;
		i--;
	}
	nb_hex[i] = base[nb_int % 16];
}
