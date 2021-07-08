/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:24:46 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 19:40:47 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_node(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		ft_print_error();
	node->value = 0;
	node->next = 0;
	node->prev = 0;
	return (node);
}

t_stack	*ft_init_stack(char c)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_print_error();
	stack->size = 0;
	stack->top = 0;
	stack->bottom = 0;
	stack->self = c;
	return (stack);
}
