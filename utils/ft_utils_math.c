/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:27:17 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 14:29:09 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_array(int *sort, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (sort[j] > sort[j + 1])
			{
				temp = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_minmax(t_stack *stack, int *min, int *max, int r)
{
	int		i;
	t_node	*node;

	node = stack->top;
	if (!node)
		return ;
	*min = node->value;
	*max = node->value;
	i = 0;
	while (node && i < r)
	{
		if (*min > node->value)
			*min = node->value;
		if (*max < node->value)
			*max = node->value;
		node = node->next;
		i++;
	}
}
