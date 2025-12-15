/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_putnbr_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sservant <sservant@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:22:19 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/09 13:23:17 by sservant         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_len_uint(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_uint_putnbr_count(unsigned int nb, t_format f, int pad_len, int prec_len)
{
	int		num_len;
	int		printed;
	char	pad_char;

	pad_char = ' ';
	printed = 0;
	num_len = number_len_uint(nb);
	if (f.precision > num_len)
		prec_len = f.precision - num_len;
	if (f.width != WIDTH_UNRESTRICTED)
		pad_len = f.width - (max(num_len, f.precision) * \
!(f.precision == 0 && nb == 0));
	if (f.flags[FLAG_ZERO] && !f.flags[FLAG_MINUS] && f.precision < 0)
		pad_char = '0';
	if (nb < 0)
		ft_putchar_fd('-', 2);
	printed += ft_put_padding_rep(pad_len * \
(f.flags[FLAG_MINUS] == 0), pad_char);
	printed += ft_put_precision_rep(prec_len);
	if (!(f.precision == 0 && nb == 0))
	{
		if (nb == 0)
			ft_putchar_fd('0', 2);
		printed += display_uint(nb);
	}
	printed += ft_put_padding_rep(pad_len * (f.flags[FLAG_MINUS] != 0), ' ');
	return (printed + ((nb == 0) * (f.precision != 0)));
}
