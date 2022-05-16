/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:56:47 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/16 14:42:21 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parsing(int argc, char **argv)
{
	if (argc != 5)
		ft_error("Error");
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}
