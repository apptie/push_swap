/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:13:58 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 00:03:32 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		is_b_to_a;

	if (argc == 1)
		return (0);
	a = ft_init_stack('a');
	ft_set_stack(a, argc, argv);
	ft_check_stack(a);
	b = ft_init_stack('b');
	if (ft_check_sort_a(a, a->size))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		return (0);
	}
	is_b_to_a = 0;
	ft_a_to_b(a, b, a->size, &is_b_to_a);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
