/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:49:03 by vpetrosy          #+#    #+#             */
/*   Updated: 2022/03/19 00:54:34 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = -1;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (++i < n)
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
	return (0);
}
