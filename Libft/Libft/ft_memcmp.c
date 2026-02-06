/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:26:15 by vokotera          #+#    #+#             */
/*   Updated: 2025/11/12 09:47:43 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	if (n == 0)
		return (0);
	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (i < n - 1 && src1[i] == src2[i])
			i++;
	}
	return (src1[i] - src2[i]);
}
