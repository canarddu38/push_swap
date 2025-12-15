/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:51:03 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/10 15:52:31 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(t_stack	*stack, int *output)
{
	if (stack->stack_top_idx >= 0)
		*output = stack->arr[stack->stack_top_idx];
	else
		return (1);
	return (0);
}

int	push_stack(t_stack *dest, t_stack *source)
{
	int	top;

	top = 0;
	if (pop(source, &top) == ERR_EMPTY)
		return (0);
	return (push(top, dest));
}
