/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:55:16 by julcleme          #+#    #+#             */
/*   Updated: 2025/12/10 22:47:32 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap_bonus.h"
#include "ft_printf.h"

void	generate_line(char *line, int n)
{
	int	i;

	i = 0;
	while (i <= n && i < MAX_VISUAL_SIZE)
		line[i++] = '=';
	line[i] = '\0';
}

static void	print_stack_line(t_stack *s, int row, int scale, int is_a)
{
	char	line[MAX_VISUAL_SIZE];
	char	c;

	if (row < 0)
	{
		if (is_a)
			ft_printf("                 ");
		return ;
	}
	c = ' ';
	if (s->arr[row] < 0)
		c = '-';
	generate_line(line, abs(s->arr[row]) / scale);
	ft_printf("%c%.7i %s", c, abs(s->arr[row]), line);
}

void	visual_bench(t_stack *a, t_stack *b, int scale)
{
	int	row_a;
	int	row_b;
	int	screen_line;

	row_a = (a->stack_top_idx % MAX_VISUAL_SIZE) + 1;
	row_b = (b->stack_top_idx % MAX_VISUAL_SIZE) + 1;
	ft_printf("\033[2J");
	screen_line = 1;
	while ((--row_a >= 0 || --row_b >= 0) && scale > 0)
	{
		ft_printf("\033[%d;1H", screen_line);
		print_stack_line(a, row_a, scale, 1);
		ft_printf("\033[%d;50H", screen_line);
		print_stack_line(b, row_b, scale, 0);
		screen_line++;
	}
}

/*
usleep(100000);
*/
