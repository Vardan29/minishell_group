/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:56:49 by vpetrosy          #+#    #+#             */
/*   Updated: 2022/03/16 05:57:05 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	start_pos;
	size_t	end_pos;

	start_pos = 0;
	while (ft_strchr(set, s1[start_pos]))
		++start_pos;
	end_pos = start_pos + ft_strlen(&s1[start_pos]);
	while (ft_strchr(set, s1[end_pos]) && end_pos != 0)
		--end_pos;
	return (ft_substr(s1, start_pos, end_pos - start_pos + 1));
}
