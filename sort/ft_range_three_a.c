/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_three_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:17:42 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 22:52:09 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size_three_a(t_stack *target, int min_index, int max_index)
{
	if (min_index == 0)
	{
		if (max_index == 1)
		{
			ft_process_rr(target, "rra");
			ft_process_s(target, "sa");
		}
	}
	else if (min_index == 1)
	{
		if (max_index == 2)
			ft_process_s(target, "sa");
		else if (max_index == 0)
			ft_process_r(target, "ra");
	}
	else if (min_index == 2)
	{
		if (max_index == 0)
			ft_process_s(target, "sa");
		ft_process_rr(target, "rra");
	}
}

void	ft_three_a_two(t_stack *target, t_stack *stack, int max_index)
{
	if (max_index == 0)
		ft_process_s(target, "sa");
	ft_process_p(target, stack, "pb");
	ft_process_s(target, "sa");
	ft_process_p(target, stack, "pa");
	ft_process_s(target, "sa");
}

void	ft_range_three_a(t_stack *target, t_stack *stack,
		int min_index, int max_index)
{
	if (min_index == 0)
	{
		if (max_index == 1)
		{
			ft_process_p(target, stack, "pb");
			ft_process_s(target, "sa");
			ft_process_p(target, stack, "pa");
		}
	}
	else if (min_index == 1)
	{
		ft_process_s(target, "sa");
		if (max_index == 0)
		{
			ft_process_p(target, stack, "pb");
			ft_process_s(target, "sa");
			ft_process_p(target, stack, "pa");
		}
	}
	else if (min_index == 2)
		ft_three_a_two(target, stack, max_index);
}
