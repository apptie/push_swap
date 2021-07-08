/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_b_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:58:14 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 15:00:06 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_ra(t_stack *a, int r, int minus, t_value *value)
{
	int		i;
	t_node	*node;

	i = 0;
	node = a->top;
	while (i < r - minus)
	{
		if (node->value <= value->pivot_big)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	ft_push_sapb(t_stack *a, t_stack *b, t_value *value)
{
	if (a->top->value > value->pivot_big)
	{
		if (a->top->next->value <= value->pivot_big)
		{
			ft_process_s(a, "sa");
			ft_process_p(a, b, "pb");
			value->pb++;
			value->ra_sub = value->ra + 1;
			return (1);
		}
	}
	return (0);
}

void	ft_a_to_b_push_sub(t_stack *a, t_stack *b, t_value *value)
{
	if (a->top->value > value->pivot_big)
	{
		ft_process_r(a, "ra");
		value->ra++;
	}
	else
	{
		ft_process_p(a, b, "pb");
		value->pb++;
		if (b->top->value > value->pivot_small)
		{
			ft_process_r(b, "rb");
			value->rb++;
		}
	}
}

void	ft_a_to_b_push(t_stack *a, t_stack *b, int r, t_value *value)
{
	int	i;

	i = 0;
	value->ra_sub = 0;
	while (i < r)
	{
		if (i + 1 == r)
		{
			if (ft_push_sapb(a, b, value) == 1)
				return ;
		}
		if (ft_check_ra(a, r, i, value))
		{
			value->ra_sub = value->ra + (r - i);
			return ;
		}
		ft_a_to_b_push_sub(a, b, value);
		i++;
	}
}
