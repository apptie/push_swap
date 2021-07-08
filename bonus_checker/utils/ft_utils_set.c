/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:32:24 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 12:02:41 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_ptr(t_node **before, t_node *now, t_stack *stack)
{
	if (!*before)
	{
		*before = now;
		stack->top = *before;
	}
	else
	{
		(*before)->next = now;
		now->prev = *before;
		*before = (*before)->next;
	}
}

void	ft_set_node_valid(char *argv, t_stack *stack)
{
	int	i;
	int	flag;

	flag = 0;
	if (ft_strlen(argv) == 0)
	{
		ft_free_stack(stack);
		ft_print_error();
	}
	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
	{
		ft_free_stack(stack);
		ft_print_error();
	}
}

void	ft_set_node(char *argv, t_node **before, t_stack *stack)
{
	int		i;
	char	**argv_split;
	t_node	*node;

	ft_set_node_valid(argv, stack);
	argv_split = ft_split(argv, ' ');
	if (!argv_split)
		ft_print_error();
	i = 0;
	while (argv_split[i])
	{
		node = ft_init_node();
		if (!node)
			ft_print_error();
		if (!ft_check_argv(argv_split[i]))
			ft_print_error();
		node->value = ft_atoi(argv_split[i]);
		ft_set_ptr(before, node, stack);
		stack->size++;
		free(argv_split[i]);
		i++;
	}
	free(argv_split);
}

void	ft_set_stack(t_stack *stack, int argc, char *argv[])
{
	int		i;
	t_node	*before;

	i = 0;
	before = 0;
	while (++i < argc)
		ft_set_node(argv[i], &before, stack);
	if (!before->next)
		stack->bottom = before;
}
