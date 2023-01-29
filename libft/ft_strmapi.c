/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:59:49 by vpetrosy          #+#    #+#             */
/*   Updated: 2022/03/18 22:00:18 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;
	size_t	len;

	len = ft_strlen(s);
	p = (char *)ft_calloc(len + 1, sizeof (char));
	i = -1;
	while (s[++i])
		p[i] = f(i, s[i]);
	return (p);
}
