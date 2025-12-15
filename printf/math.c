/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sservant <sservant@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:54:55 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/09 12:39:57 by sservant         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	min(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}
