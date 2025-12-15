/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:36 by sservant          #+#    #+#             */
/*   Updated: 2025/12/10 15:10:51 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack *s)
{
	int	i;
	int	first;

	if (s->stack_top_idx < 0)
		return (0);
	first = s->arr[0];
	i = 0;
	while (i < s->stack_top_idx)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->stack_top_idx] = first;
	return (1);
}

int	rotate_r_a(t_stack *a, t_bench *bench)
{
	if (bench)
		write(1, "rra\n", 4);
	if (reverse_rotate(a))
	{
		if (bench)
		{
			bench->rra++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	rotate_r_b(t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "rrb\n", 4);
	if (reverse_rotate(b))
	{
		if (bench)
		{
			bench->rrb++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	rotate_r_r(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "rrr\n", 4);
	if (reverse_rotate(a) && reverse_rotate(b))
	{
		if (bench)
		{
			bench->rrr++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}
