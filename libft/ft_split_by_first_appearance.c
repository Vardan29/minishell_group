/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_first_appearance.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <vpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:51:03 by vpetrosy          #+#    #+#             */
/*   Updated: 2023/01/21 20:56:39 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_by_first_appearance(char *str, char delimiter,
			char **left, char **right)
{
	int	i;
	int	length;

	i = -1;
	length = ft_strlen(str);
	while (++i < length)
	{
		if (str[i] == delimiter)
		{
			str[i] = '\0';
			*left = str;
			*right = str + i + 1;
			return ;
		}
	}
	*left = str;
	*right = NULL;
}
