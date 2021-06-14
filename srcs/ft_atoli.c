/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:31:45 by admadene          #+#    #+#             */
/*   Updated: 2021/06/09 14:31:53 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoli(const char *str)
{
	int				neg;
	long long int	nb;

	neg = 1;
	nb = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb += (*str - '0') * neg;
		nb *= 10;
		str++;
	}
	if (*str && *str != ' ')
		return (0);
	nb /= 10;
	return (nb);
}
