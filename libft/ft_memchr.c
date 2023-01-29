/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:27:20 by vpetrosy          #+#    #+#             */
/*   Updated: 2022/03/13 05:27:21 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	if (n == 0 || s == 0)
		return (0);
	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{	
		if (s2[i] == (unsigned char)c)
			return ((void *)s2 + i);
		++i;
	}
	return (0);
}
