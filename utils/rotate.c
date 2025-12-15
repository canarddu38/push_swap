/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:26:43 by sservant          #+#    #+#             */
/*   Updated: 2025/12/11 10:29:50 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *s)
{
	int	i;
	int	last;
	int	last_r;

	if (s->stack_top_idx < 1)
		return (0);
	last = s->arr[s->stack_top_idx];
	if (s->rank)
		last_r = s->rank[s->stack_top_idx];
	i = s->stack_top_idx;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		if (s->rank)
			s->rank[i] = s->rank[i - 1];
		i--;
	}
	s->arr[0] = last;
	if (s->rank)
		s->rank[0] = last_r;
	return (1);
}

int	rotate_a(t_stack *a, t_bench *bench)
{
	if (bench)
		write(1, "ra\n", 3);
	if (rotate(a))
	{
		if (bench)
		{
			bench->ra++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	rotate_b(t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "rb\n", 3);
	if (rotate(b))
	{
		if (bench)
		{
			bench->rb++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	rotate_r(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "rr\n", 3);
	if (rotate(a) && rotate(b))
	{
		if (bench)
		{
			bench->rr++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}
