/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <vpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:40:08 by vpetrosy          #+#    #+#             */
/*   Updated: 2023/01/27 22:24:40 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	sign = 1;
	if (ft_issign(str[i]))
		if (str[i++] == '-')
			sign *= -1;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		if (result)
			result = result * 10 + (str[i] - 48);
		else
			result += str[i] - 48;
		++i;
	}
	return (result * sign);
}
