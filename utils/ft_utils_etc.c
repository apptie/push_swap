/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_etc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:23:15 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 16:03:55 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *target)
{
	t_node	*node;
	t_node	*temp;

	node = target->top;
	while (1)
	{
		if (!node)
			break ;
		temp = node->next;
		free(node);
		node = temp;
	}
	free(target);
}

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_print_stack(t_stack *target)
{
	t_node	*top;

	top = target->top;
	write(1, "\n\n", 2);
	ft_putstr_fd("=========================\n\n", 1);
	while (top)
	{
		ft_putnbr_fd(top->value, 1);
		write(1, "  ", 2);
		top = top->next;
	}
	ft_putstr_fd("\n\n=========================\n", 1);
}
