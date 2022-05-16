/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:20:31 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 13:49:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

int	ft_printstr(char *ap)
{
	int	i;
	int	nb;

	if (ap == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	nb = ft_strlen(ap);
	while (i < nb)
	{
		write (1, &ap[i], 1);
		i++;
	}
	return (nb);
}

int	ft_printchar(char ap, char type)
{
	if (type == 'c')
	{
		write (1, &ap, 1);
	}
	else if (type == '%')
		write (1, "%%", 1);
	return (1);
}

int	ft_printnbr(long long int n)
{
	long long int	i;
	int				neg;

	ft_putnbr_fd(n, 1);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	else
		neg = 0;
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + neg);
}

int	ft_trie(va_list ap, char type)
{
	int	ret;

	ret = 1;
	if (type == 's')
		ret = ft_printstr(va_arg(ap, char *));
	else if (type == 'c')
		ret = ft_printchar(va_arg(ap, int), type);
	else if (type == 'd' || type == 'i')
		ret = ft_printnbr(va_arg(ap, int));
	else if (type == 'u')
		ret = ft_printnbr((long long int)va_arg(ap, unsigned int));
	else if (type == 'x')
		ret = ft_convertbase_x(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		ret = ft_convertbase_x(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (type == 'p')
		ret = ft_convertbase_p(va_arg(ap, unsigned long long int),
				"0123456789abcdef");
	else if (type == '%')
		write (1, "%%", 1);
	else
		return (0);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ret++;
			write (1, format, 1);
			format++;
		}
		else if (format[1] != 'c' && format[1] != 's' && format[1] != 'p'
			&& format[1] != 'x' && format[1] != 'X' && format[1] != '%'
			&& format[1] != 'd' && format[1] != 'i' && format[1] != 'u')
			format++;
		else
		{
			ret += ft_trie(ap, (char)format[1]);
			format += 2;
		}
	}
	va_end(ap);
	return (ret);
}
