/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:42:07 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 13:44:59 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	return (sign * result);
}
