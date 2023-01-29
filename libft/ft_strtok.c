/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrosy <vpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:02 by vpetrosy          #+#    #+#             */
/*   Updated: 2023/01/27 22:25:02 by vpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim, char **saveptr)
{
	char	*token;

	if (str == NULL)
		str = *saveptr;
	while (*str != '\0' && ft_strchr(delim, *str) != NULL)
		str++;
	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}
	token = str;
	while (*str != '\0' && ft_strchr(delim, *str) == NULL)
		str++;
	if (*str != '\0')
	{
		*str = '\0';
		str++;
	}
	*saveptr = str;
	return (token);
}
