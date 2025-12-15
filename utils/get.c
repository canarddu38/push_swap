/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:35:34 by sservant          #+#    #+#             */
/*   Updated: 2025/12/10 15:52:51 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(t_stack *s)
{
	return (s->arr[get_max_index(s)]);
}

int	get_max_index(t_stack *s)
{
	int		max_idx;
	int		i;

	max_idx = -1;
	i = 0;
	while (i <= s->stack_top_idx)
	{
		if (max_idx == -1 || s->arr[i] > s->arr[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

void	parse_stack_rank(t_stack *a, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i <= size)
	{
		count = 0;
		j = 0;
		while (j <= size)
		{
			if (a->arr[j] < a->arr[i])
				count++;
			j++;
		}
		a->rank[i] = count;
		i++;
	}
}
