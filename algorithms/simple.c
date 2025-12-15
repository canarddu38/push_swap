/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:49:47 by sservant          #+#    #+#             */
/*   Updated: 2025/12/10 11:22:56 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_push_swap(t_stack *a, t_bench *bench)
{
	int	i;
	int	j;
	int	n;

	n = a->stack_top_idx;
	i = 0;
	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			if (j < n - i && a->arr[n] > a->arr[n - 1])
				swap_a(a, bench);
			rotate_a(a, bench);
			j++;
		}
		i++;
	}
	return (0);
}
