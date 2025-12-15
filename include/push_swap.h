/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:32:32 by sservant          #+#    #+#             */
/*   Updated: 2025/12/08 17:57:41 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# define STACK_BLOCK_SIZE 4096
# define ERR_EMPTY		1
# define MODE_NORMAL 0
# define MODE_SIMPLE 1
# define MODE_MEDIUM 2
# define MODE_COMPLEX 3
# define MODE_ADAPTIVE 4

# define MAX_VISUAL_SIZE 30

# ifndef IS_VISUAL
#  define IS_VISUAL 0
# endif

typedef struct s_stack
{
	long	stack_top_idx;
	int		*arr;
	int		*rank;
	int		capacity;
}	t_stack;

typedef struct s_bench
{
	int	ops;
	int	disorder;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	mode;
	int	strat;
}	t_bench;

int		simple_push_swap(t_stack *a, t_bench *bench);
void	medium_push_swap(t_stack *a, t_bench *bench);
void	complex_push_swap(t_stack *a, t_bench *bench);
void	adaptive_push_swap(t_stack *a, t_bench *bench);

void	parse_stack_rank(t_stack *a, int size);
void	visual_bench(t_stack *a, t_stack *b, int scale);
void	create_benchmark(t_bench *bench);
void	init_bench(t_bench *bench);
int		init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		push(int i, t_stack *stack);
int		pop(t_stack *stack, int *output);
int		is_empty(t_stack *stack);
int		top(t_stack	*stack, int *output);
int		get_max_index(t_stack *s);
int		get_max_value(t_stack *s);

int		swap_a(t_stack *a, t_bench *bench);
int		swap_b(t_stack *b, t_bench *bench);
int		swap_s(t_stack *a, t_stack *b, t_bench *bench);
int		push_a(t_stack *a, t_stack *b, t_bench *bench);
int		push_b(t_stack *a, t_stack *b, t_bench *bench);
int		rotate_a(t_stack *a, t_bench *bench);
int		rotate_b(t_stack *b, t_bench *bench);
int		rotate_r(t_stack *a, t_stack *b, t_bench *bench);
int		rotate_r_a(t_stack *a, t_bench *bench);
int		rotate_r_b(t_stack *b, t_bench *bench);
int		rotate_r_r(t_stack *a, t_stack *b, t_bench *bench);
int		push_stack(t_stack *dest, t_stack *source);

int		parse_stack_input(char **args, int count, t_stack *s);
int		parse_op(t_stack *a, t_stack *b, char op[4]);

#endif