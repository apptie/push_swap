/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:52:00 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 19:34:48 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_rr(t_stack *target)
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
}

void	ft_process_rrr(t_stack *a, t_stack *b)
{
	ft_process_rr(a);
	ft_process_rr(b);
}
