/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:05:40 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 15:06:21 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b_to_a_push(t_stack *a, t_stack *b, int r, t_value *value)
{
	int	i;

	i = 0;
	while (i < r)
	{	
		if (b->top->value <= value->pivot_small)
		{
			ft_process_r(b, "rb");
			value->rb++;
		}
		else
		{
			ft_process_p(a, b, "pa");
			value->pa++;
			if (a->top->value <= value->pivot_big)
			{
				ft_process_r(a, "ra");
				value->ra++;
			}
		}
		i++;
	}
}
