/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:52:26 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 19:35:16 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_s(t_stack *target)
{
	t_node	*first;
	t_node	*second;

	if (target->size < 2)
		return ;
	first = ft_stack_pop(target);
	second = ft_stack_pop(target);
	ft_stack_push(target, first);
	ft_stack_push(target, second);
}

void	ft_process_ss(t_stack *a, t_stack *b)
{
	ft_process_s(a);
	ft_process_s(b);
}
