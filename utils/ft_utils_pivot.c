/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:29:22 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/08 15:59:09 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_pivot(t_stack *stack, int size, t_value *value)
{
	int		*sort;
	int		i;
	t_node	*node;

	sort = malloc(sizeof(int) * stack->size + 1);
	if (!sort)
		ft_print_error();
	node = stack->top;
	i = 0;
	while (i < size)
	{
		sort[i++] = node->value;
		node = node->next;
	}
	ft_sort_array(sort, size);
	value->pivot_middle = sort[(i / 2)];
	value->pivot_big = sort[(i / 2)];
	value->pivot_small = sort[(i / 2) / 2];
	free(sort);
}
