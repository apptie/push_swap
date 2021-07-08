/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:41:17 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 19:25:29 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_p(t_stack *a, t_stack *b, char *flag)
{
	t_node	*top;

	if (ft_strcmp(flag, "pa") == 0)
	{
		if (b->size == 0)
			return ;
		top = ft_stack_pop(b);
		ft_stack_push(a, top);
	}
	else
	{
		if (a->size == 0)
			return ;
		top = ft_stack_pop(a);
		ft_stack_push(b, top);
	}
}
