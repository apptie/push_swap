/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:14:48 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 22:54:54 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_min_index(t_node *node, int min, int *min_index)
{
	while (min != node->value)
	{
		*min_index += 1;
		node = node->next;
	}
}

void	ft_get_max_index(t_node *node, int max, int *max_index)
{
	while (max != node->value)
	{
		*max_index += 1;
		node = node->next;
	}
}

void	ft_range_three(t_stack *target, t_stack *stack,
		int min_index, int max_index)
{
	int	min;
	int	max;

	min = 0;
	max = 0;
	ft_check_minmax(target, &min, &max, 3);
	ft_get_min_index(target->top, min, &min_index);
	ft_get_max_index(target->top, max, &max_index);
	if (target->self == 'a')
	{
		if (target->size == 3)
			ft_size_three_a(target, min_index, max_index);
		else
			ft_range_three_a(target, stack, min_index, max_index);
	}
	else
	{
		if (target->size == 3)
			ft_size_three_b(target, min_index, max_index);
		else
			ft_range_three_b(target, stack, min_index, max_index);
	}
}
