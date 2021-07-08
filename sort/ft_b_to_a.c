/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:03:32 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 15:06:36 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_range_b(int r, t_stack *a, t_stack *b, t_value value)
{
	int	i;

	i = 0;
	if (r <= 3)
	{
		ft_under_three(b, a, r);
		while (i < r)
		{
			ft_process_p(a, b, "pa");
			i++;
		}
		return (0);
	}
	else if (r == 5)
	{
		ft_range_five(b, a, r, value);
		return (0);
	}
	else
		return (1);
}

void	ft_b_to_a_rotate_a(t_stack *a, t_stack *b, t_value value)
{
	int	ra;
	int	rb;

	ra = value.ra;
	rb = value.rb;
	while (rb--)
	{
		ft_process_rrr(a, b);
		ra--;
	}
	while (ra--)
		ft_process_rr(a, "rra");
}

void	ft_b_to_a_rotate_b(t_stack *a, t_stack *b, t_value value)
{
	int	ra;
	int	rb;

	ra = value.ra;
	rb = value.rb;
	while (ra--)
	{
		ft_process_rrr(a, b);
		rb--;
	}
	while (rb--)
		ft_process_rr(b, "rrb");
}

int	ft_b_to_a_sub(t_stack *a, t_stack *b, int r)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (ft_check_sort_b(b, r))
	{
		flag = 1;
		while (i < r)
		{
			ft_process_p(a, b, "pa");
			i++;
		}
	}
	return (flag);
}

void	ft_b_to_a(t_stack *a, t_stack *b, int r, int *is_b_to_a)
{
	t_value	value;

	if (ft_b_to_a_sub(a, b, r) == 1)
		return ;
	(*is_b_to_a)++;
	value = ft_init_value();
	ft_check_pivot(b, r, &value);
	if (!ft_check_range_b(r, a, b, value))
		return ;
	ft_b_to_a_push(a, b, r, &value);
	ft_a_to_b(a, b, value.pa - value.ra, is_b_to_a);
	if (value.ra > value.rb)
		ft_b_to_a_rotate_a(a, b, value);
	else
		ft_b_to_a_rotate_b(a, b, value);
	ft_a_to_b(a, b, value.ra, is_b_to_a);
	ft_b_to_a(a, b, value.rb, is_b_to_a);
}
