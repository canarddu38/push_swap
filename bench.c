/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:28:50 by sservant          #+#    #+#             */
/*   Updated: 2025/12/10 16:38:58 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	create_benchmark(t_bench *bench)
{
	char	mode[5][100];
	char	strat[5][100];

	ft_strlcpy(mode[0], "Simple", ft_strlen("Simple") + 1);
	ft_strlcpy(mode[1], "Medium", ft_strlen("Medium") + 1);
	ft_strlcpy(mode[2], "Complex", ft_strlen("Complex") + 1);
	ft_strlcpy(mode[3], "Adaptive", ft_strlen("Adaptive") + 1);
	ft_strlcpy(strat[0], "O(n2)", ft_strlen("O(n2)") + 1);
	ft_strlcpy(strat[1], "O(n√n)", ft_strlen("O(n√n)") + 1);
	ft_strlcpy(strat[2], "O(n log n)", ft_strlen("O(n log n)") + 1);
	ft_printf("\n========================= [ BENCHMARK ] \
========================\n");
	ft_printf("| Disorder : %d%%    | Strategy : %-9s / %-18s|\n", \
bench->disorder, mode[bench->mode - 1], strat[bench->strat - 1]);
	ft_printf("| Total Ops: %-50d|\n", bench->ops);
	ft_printf("-----------------------------------------------------\
-----------\n");
	ft_printf("| SWAP     : sa=%-4d sb=%-4d ss=%-31d|\n", \
bench->sa, bench->sb, bench->ss);
	ft_printf("| PUSH     : pa=%-4d pb=%-39d|\n", \
bench->pa, bench->pb);
	ft_printf("| ROTATE   : ra=%-4d rb=%-4d rr=%-23d        \
|\n", bench->ra, bench->rb, bench->rr);
	ft_printf("| R-ROTATE : rra=%-4d rrb=%-4d rrr=%-28d|\n", \
bench->rra, bench->rrb, bench->rrr);
	ft_printf("==============================================\
==================\n\n");
}
