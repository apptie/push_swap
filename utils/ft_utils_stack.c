/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:37:22 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 00:01:01 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stack_pop(t_stack *target)
{
	t_node	*top;
	t_node	*top_next;

	if (target->size == 0)
		return (0);
	top = target->top;
	top_next = top->next;
	if (top_next)
		top_next->prev = 0;
	target->top = top_next;
	top->next = 0;
	top->prev = 0;
	target->size--;
	if (target->size == 1)
		target->bottom = target->top;
	return (top);
}

void	ft_stack_push(t_stack *target, t_node *node)
{
	t_node	*top;

	node->prev = 0;
	node->next = 0;
	target->size++;
	top = target->top;
	if (!top)
	{
		target->top = node;
		target->bottom = node;
		return ;
	}
	node->next = top;
	top->prev = node;
	target->top = node;
}
