/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:25:56 by sservant          #+#    #+#             */
/*   Updated: 2025/12/10 21:05:38 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(int i, t_stack *stack)
{
	int	*new_arr;
	int	*new_rank;

	stack->stack_top_idx++;
	if (stack->stack_top_idx >= stack->capacity)
	{
		stack->capacity += STACK_BLOCK_SIZE;
		new_arr = ft_calloc(sizeof(int), stack->capacity);
		new_rank = ft_calloc(sizeof(int), stack->capacity);
		if (!new_arr || !new_rank)
			return (0);
		ft_memcpy(new_arr, stack->arr, (stack->stack_top_idx) * sizeof(int));
		ft_memcpy(new_rank, stack->rank, (stack->stack_top_idx) * sizeof(int));
		free(stack->arr);
		free(stack->rank);
		stack->arr = new_arr;
		stack->rank = new_rank;
	}
	stack->arr[stack->stack_top_idx] = i;
	return (1);
}

int	push_a(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "pa\n", 3);
	if (push_stack(a, b))
	{
		if (bench)
		{
			bench->pa++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}

int	push_b(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		write(1, "pb\n", 3);
	if (push_stack(b, a))
	{
		if (bench)
		{
			bench->pb++;
			bench->ops++;
		}
		return (1);
	}
	return (0);
}
