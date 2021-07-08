/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:07:42 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 15:13:17 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_range_five_a_sub(t_stack *a, int ra)
{
	if (a->size != 3)
	{
		while (ra--)
			ft_process_rr(a, "rra");
	}
}

void	ft_range_five_a(t_stack *a, t_stack *b, t_value value)
{
	int	pb;
	int	ra;

	pb = 0;
	ra = 0;
	while (1)
	{
		if (a->top->value < value.pivot_middle)
		{
			ft_process_p(a, b, "pb");
			pb++;
		}
		else
		{
			ft_process_r(a, "ra");
			ra++;
		}
		if (pb == 2)
			break ;
	}
	ft_range_five_a_sub(a, ra);
	ft_range_three(a, b, 0, 0);
	ft_range_two(b, b->top);
}

void	ft_range_five_b_sub(t_stack *b, int rb)
{
	if (b->size != 2)
	{
		while (rb--)
			ft_process_rr(b, "rrb");
	}
}

void	ft_range_five_b(t_stack *a, t_stack *b, int r, t_value value)
{
	int	pa;
	int	rb;

	pa = 0;
	rb = 0;
	while (r--)
	{
		if (b->top->value >= value.pivot_middle)
		{
			ft_process_p(a, b, "pa");
			pa++;
		}
		else
		{
			ft_process_r(b, "rb");
			rb++;
		}
		if (pa == 3)
			break ;
	}
	ft_range_five_b_sub(b, rb);
	ft_range_three(a, b, 0, 0);
	ft_range_two(b, b->top);
}

void	ft_range_five(t_stack *target, t_stack *stack, int r, t_value value)
{
	if (target->self == 'a')
	{
		ft_range_five_a(target, stack, value);
		ft_process_p(target, stack, "pa");
		ft_process_p(target, stack, "pa");
	}
	else
	{
		ft_range_five_b(stack, target, r, value);
		ft_process_p(stack, target, "pa");
		ft_process_p(stack, target, "pa");
	}
}
