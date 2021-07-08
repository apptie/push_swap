/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:52:00 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 00:01:46 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_rr(t_stack *target, char *flag)
{
	t_node	*top;
	t_node	*bottom;

	if (target->size < 2)
		return ;
	top = target->top;
	bottom = target->bottom;
	bottom->prev->next = 0;
	target->bottom = bottom->prev;
	bottom->prev = 0;
	bottom->next = top;
	top->prev = bottom;
	target->top = bottom;
	if (ft_strcmp(flag, "rrr") != 0)
	{
		write(1, flag, 3);
		write(1, "\n", 1);
	}
}

void	ft_process_rrr(t_stack *a, t_stack *b)
{
	ft_process_rr(a, "rrr");
	ft_process_rr(b, "rrr");
	write(1, "rrr\n", 4);
}
