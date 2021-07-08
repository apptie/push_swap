/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:54:11 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 16:37:51 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_range(int r, t_stack *a, t_stack *b, t_value value)
{
	if (r <= 3)
	{
		ft_under_three(a, b, r);
		return (0);
	}
	else if (r == 5)
	{
		ft_range_five(a, b, r, value);
		return (0);
	}
	else
		return (1);
}

void	ft_a_to_b_rotate_a(t_stack *a, t_stack *b,
		int *is_b_to_a, t_value value)
{
	int	ra;
	int	rb;

	ra = value.ra;
	rb = value.rb;
	if (*is_b_to_a > 0)
	{
		while (rb--)
		{
			ft_process_rrr(a, b);
			ra--;
		}
		while (ra--)
			ft_process_rr(a, "rra");
	}
	else
	{
		while (rb--)
			ft_process_rr(b, "rrb");
	}
}

void	ft_a_to_b_rotate_b(t_stack *a, t_stack *b,
		int *is_b_to_a, t_value value)
{
	int	ra;
	int	rb;

	ra = value.ra;
	rb = value.rb;
	if (*is_b_to_a > 0)
	{
		while (ra--)
		{
			ft_process_rrr(a, b);
			rb--;
		}
		while (rb--)
			ft_process_rr(b, "rrb");
	}
	else
	{
		while (rb--)
			ft_process_rr(b, "rrb");
	}
}

void	ft_a_to_b(t_stack *a, t_stack *b, int r, int *is_b_to_a)
{
	t_value	value;

	if (ft_check_sort_a(a, r))
		return ;
	value = ft_init_value();
	ft_check_pivot(a, r, &value);
	if (!ft_check_range(r, a, b, value))
		return ;
	ft_a_to_b_push(a, b, r, &value);
	if (value.ra > value.rb)
		ft_a_to_b_rotate_a(a, b, is_b_to_a, value);
	else
		ft_a_to_b_rotate_b(a, b, is_b_to_a, value);
	if (value.ra_sub)
		ft_a_to_b(a, b, value.ra_sub, is_b_to_a);
	else
		ft_a_to_b(a, b, value.ra, is_b_to_a);
	ft_b_to_a(a, b, value.rb, is_b_to_a);
	ft_b_to_a(a, b, value.pb - value.rb, is_b_to_a);
}
