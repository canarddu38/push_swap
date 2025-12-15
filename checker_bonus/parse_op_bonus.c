/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:20:29 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/10 22:47:30 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	parse_swap(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a')
		return (swap_a(a, 0));
	if (op[1] == 'b')
		return (swap_b(b, 0));
	if (op[1] == 's')
		return (swap_s(a, b, 0));
	return (-1);
}

static int	parse_push(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a')
		return (push_a(a, b, 0));
	if (op[1] == 'b')
		return (push_b(a, b, 0));
	return (-1);
}

static int	parse_rotate(t_stack *a, t_stack *b, char *op)
{
	if (op[1] == 'a')
		return (rotate_a(a, 0));
	if (op[1] == 'b')
		return (rotate_b(b, 0));
	if (op[1] == 'r')
	{
		if (op[2] == 'a')
			return (rotate_r_a(a, 0));
		if (op[2] == 'b')
			return (rotate_r_b(b, 0));
		if (op[2] == 'r')
			return (rotate_r_r(a, b, 0));
		if (op[2] == 0)
			return (rotate_r(a, b, 0));
	}
	return (-1);
}

int	parse_op(t_stack *a, t_stack *b, char op[4])
{
	if (op[0] == 's')
		return (parse_swap(a, b, op));
	if (op[0] == 'p')
		return (parse_push(a, b, op));
	if (op[0] == 'r')
		return (parse_rotate(a, b, op));
	return (-1);
}
