/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:25 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/18 22:27:27 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_print_tab(char **tab, char *name)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s [%d] = %s\n", name, i, tab[i]);
		i++;
	}
	printf("\n");
}
