/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:50:49 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 00:01:38 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_r(t_stack *target, char *flag)
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
	if (ft_strcmp(flag, "rr") != 0)
	{
		write(1, flag, 2);
		write(1, "\n", 1);
	}
}

void	ft_process_r_all(t_stack *a, t_stack *b)
{
	ft_process_r(a, "rr");
	ft_process_r(b, "rr");
	write(1, "rr\n", 3);
}
