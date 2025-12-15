/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:32:46 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/11 10:50:41 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maximum_bits(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 2;
		i++;
	}
	return (i);
}

void	complex_push_swap(t_stack *a, t_bench *bench)
{
	int		max_bits;
	int		indexes[2];
	int		size;
	t_stack	b;

	size = a->stack_top_idx + 1;
	max_bits = maximum_bits(size - 1);
	indexes[0] = -1;
	init_stack(&b);
	while (++indexes[0] < max_bits)
	{
		parse_stack_rank(a, a->stack_top_idx);
		indexes[1] = -1;
		while (++indexes[1] < size)
		{
			if (~(a->rank[a->stack_top_idx] >> indexes[0]) & 1)
				push_b(a, &b, bench);
			else
				rotate_a(a, bench);
		}
		while (!is_empty(&b))
			push_a(a, &b, bench);
	}
	free_stack(&b);
}
