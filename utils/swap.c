/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:25:18 by sservant          #+#    #+#             */
/*   Updated: 2025/12/10 15:53:11 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s)
{
	int	tmp;

	if (s->stack_top_idx < 0)
		return (0);
	tmp = s->arr[s->stack_top_idx];
	s->arr[s->stack_top_idx] = s->arr[s->stack_top_idx - 1];
	s->arr[s->stack_top_idx - 1] = tmp;
	return (1);
}

int	swap_a(t_stack *a, t_bench *bench)
{
	if (bench)
		write(1, "sa\n", 3);
	if (swap(a))
	{
		if (bench)
		{
			bench->sa++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	swap_b(t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "sb\n", 3);
	if (swap(b))
	{
		if (bench)
		{
			bench->sb++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	swap_s(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "ss\n", 3);
	if (swap(a) && swap(b))
	{
		if (bench)
		{
			bench->ss++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}
