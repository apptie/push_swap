/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:50:49 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 19:34:40 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_r(t_stack *target)
{
	t_node	*top;
	t_node	*bottom;

	if (target->size < 2)
		return ;
	top = target->top;
	bottom = target->bottom;
	if (top->next)
		top->next->prev = 0;
	target->top = top->next;
	top->next = 0;
	top->prev = bottom;
	bottom->next = top;
	target->bottom = top;
}

void	ft_process_r_all(t_stack *a, t_stack *b)
{
	ft_process_r(a);
	ft_process_r(b);
}
