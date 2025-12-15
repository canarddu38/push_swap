/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:56:13 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/08 18:07:12 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *stack)
{
	stack->stack_top_idx = -1;
	stack->capacity = STACK_BLOCK_SIZE;
	stack->arr = ft_calloc(sizeof(int), STACK_BLOCK_SIZE);
	stack->rank = ft_calloc(sizeof(int), STACK_BLOCK_SIZE);
	if (!stack->arr || !stack->rank)
		return (0);
	return (1);
}

void	free_stack(t_stack *stack)
{
	if (stack->arr)
		free(stack->arr);
	if (stack->rank)
		free(stack->rank);
	stack->arr = NULL;
	stack->rank = NULL;
	stack->capacity = 0;
	stack->stack_top_idx = -1;
}

void	init_bench(t_bench *bench)
{
	bench->ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->mode = 0;
	bench->strat = 0;
	bench->disorder = 0;
}

int	is_empty(t_stack *stack)
{
	return (stack->stack_top_idx < 0);
}

int	pop(t_stack *stack, int *output)
{
	if (stack->stack_top_idx < 0)
		return (1);
	*output = stack->arr[stack->stack_top_idx--];
	return (0);
}
