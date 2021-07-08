/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:40:22 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/03 19:11:57 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, size + 1);
	ft_strlcat(result, s2, size + 1);
	free(s1);
	return (result);
}
