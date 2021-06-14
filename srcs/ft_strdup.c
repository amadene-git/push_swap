/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:48:26 by admadene          #+#    #+#             */
/*   Updated: 2021/06/09 14:33:08 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(char const *s)
{
	char	*str;
	char	*strcpy;

	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (str == NULL)
		return (NULL);
	strcpy = str;
	while (*s)
		*strcpy++ = *s++;
	*strcpy = '\0';
	return (str);
}
