/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:13:49 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 15:13:58 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_range_two(t_stack *target, t_node *node)
{
	if (target->self == 'a' && node->value > node->next->value)
	{
		ft_process_s(target, "sa");
		return ;
	}
	if (target->self == 'b' && node->value < node->next->value)
	{
		ft_process_s(target, "sb");
		return ;
	}
}

void	ft_under_three(t_stack *target, t_stack *stack, int r)
{
	t_node	*node;

	node = target->top;
	if (r == 3)
		ft_range_three(target, stack, 0, 0);
	else if (r == 2)
		ft_range_two(target, node);
}
