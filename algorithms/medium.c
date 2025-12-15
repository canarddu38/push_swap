/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:15:24 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/11 15:39:07 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_based_repilate(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_idx;
	int	size_b;
	int	max_val;

	while (b->stack_top_idx != -1)
	{
		max_idx = get_max_index(b);
		max_val = b->arr[max_idx];
		size_b = b->stack_top_idx + 1;
		if (max_idx >= size_b / 2)
		{
			while (b->arr[b->stack_top_idx] != max_val)
				rotate_b(b, bench);
		}
		else
		{
			while (b->arr[b->stack_top_idx] != max_val)
				rotate_r_b(b, bench);
		}
		push_a(a, b, bench);
	}
}

void	medium_push_swap(t_stack *a, t_bench *bench)
{
	int		top_val;
	int		count;
	int		chunk_size;
	int		top_b;
	t_stack	b;

	init_stack(&b);
	parse_stack_rank(a, a->stack_top_idx);
	count = 0;
	chunk_size = 32;
	while (a->stack_top_idx != -1)
	{
		top_val = a->rank[a->stack_top_idx];
		if (top_val <= count + chunk_size)
		{
			push_b(a, &b, bench);
			top(&b, &top_b);
			if (top_b < ++count)
				rotate_b(&b, bench);
		}
		else
			rotate_a(a, bench);
	}
	chunk_based_repilate(a, &b, bench);
	free_stack(&b);
}
