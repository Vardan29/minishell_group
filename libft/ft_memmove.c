/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:46:59 by vpetrosy          #+#    #+#             */
/*   Updated: 2022/03/13 03:23:46 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (!dst || !src || dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (src < dst)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			--len;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
