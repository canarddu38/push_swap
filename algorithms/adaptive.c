/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:07:27 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/09 23:07:27 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_push_swap(t_stack *a, t_bench *bench)
{
	if (bench->disorder < 20)
	{
		bench->strat = MODE_SIMPLE;
		simple_push_swap(a, bench);
	}
	else if (bench->disorder < 50)
	{
		bench->strat = MODE_MEDIUM;
		medium_push_swap(a, bench);
	}
	else
	{
		bench->strat = MODE_COMPLEX;
		complex_push_swap(a, bench);
	}
}
