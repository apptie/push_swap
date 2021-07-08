/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_three_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:53 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 22:54:31 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size_three_b(t_stack *target, int min_index, int max_index)
{
	if (min_index == 0)
	{
		if (max_index == 2)
		{
			ft_process_s(target, "sb");
			ft_process_rr(target, "rrb");
		}
		else if (max_index == 1)
			ft_process_r(target, "rb");
	}
	else if (min_index == 1)
	{
		ft_process_rr(target, "rrb");
		if (max_index == 0)
			ft_process_s(target, "sb");
	}
	else if (min_index == 2)
	{
		if (max_index == 1)
			ft_process_s(target, "sb");
	}
}

void	ft_range_three_b(t_stack *target, t_stack *stack,
		int min_index, int max_index)
{
	if (min_index == 0)
	{
		ft_process_s(target, "sb");
		ft_process_p(stack, target, "pa");
		ft_process_s(target, "sb");
		ft_process_p(stack, target, "pb");
		if (max_index == 2)
			ft_process_s(target, "sb");
	}
	else if (min_index == 1)
	{
		ft_process_p(stack, target, "pa");
		ft_process_s(target, "sb");
		ft_process_p(stack, target, "pb");
		if (max_index == 2)
			ft_process_s(target, "sb");
	}
	else if (min_index == 2)
	{
		if (max_index == 1)
			ft_process_s(target, "sb");
	}
}
