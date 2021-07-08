/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:39:01 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 18:38:47 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_argv_length(char *argv)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (argv[0] == '+' || argv[0] == '-')
	{
		i++;
		length--;
	}
	while (argv[i] == '0')
		i++;
	while (argv[i])
	{
		i++;
		length++;
	}
	return (length);
}

int	ft_check_num(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_argv(char *argv)
{
	int	length;
	int	result;

	length = ft_argv_length(argv);
	result = ft_check_num(argv);
	if (!result || length > 11 || length < 0)
		return (0);
	else
		return (1);
}

void	ft_check_stack(t_stack *stack)
{
	int		value;
	t_node	*node;
	t_node	*temp;

	node = stack->top;
	while (node)
	{
		value = node->value;
		temp = node->next;
		while (temp)
		{
			if (value == temp->value)
				ft_print_error();
			temp = temp->next;
		}
		node = node->next;
	}
}
