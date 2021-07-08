/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:36:39 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 14:37:10 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort_a(t_stack *a, int r)
{
	int		i;
	t_node	*node;

	i = 0;
	node = a->top;
	while (i < r - 1)
	{
		if (node->value > node->next->value)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}

int	ft_check_sort_b(t_stack *b, int r)
{
	int		i;
	t_node	*node;

	i = 0;
	node = b->top;
	while (i < r - 1)
	{
		if (node->value < node->next->value)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}
