/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:51:22 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/15 00:04:30 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(t_format f, va_list args)
{
	if (!f.type)
		return (-1);
	if (f.type == '%')
	{
		ft_putchar_fd('%', 2);
		return (1);
	}
	else if (f.type == 'c')
		return (ft_putchar_count((char)va_arg(args, int), f));
	else if (f.type == 's')
		return (ft_putstr_count(va_arg(args, char *), f));
	else if (f.type == 'd' || f.type == 'i')
		return (ft_putnbr_count((int)va_arg(args, int), f, 0, 0));
	else if (f.type == 'u')
		return (ft_uint_putnbr_count((unsigned int)va_arg(args, int), f, 0, 0));
	else if (f.type == 'p')
		return (ft_putptr_count((void *)va_arg(args, void *), f));
	else if (f.type == 'x' || f.type == 'X')
		return (ft_puthex_count((uint32_t)va_arg(args, uint32_t), f, 0, 0));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (((char *)format)[i])
	{
		if (((char *)format)[i] == '%')
		{
			i++;
			j = print_format(parse_format((char *)format, &i), args);
			if (j < 0)
				return (-1);
			len += j - 1;
		}
		else
			ft_putchar_fd(((char *)format)[i++], 2);
		len++;
	}
	va_end(args);
	return (len);
}
