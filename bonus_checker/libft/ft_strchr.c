/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:28:07 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 11:08:59 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = c;
	while (*s != to_find)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}
