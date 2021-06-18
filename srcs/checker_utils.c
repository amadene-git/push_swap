/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:38:15 by admadene          #+#    #+#             */
/*   Updated: 2021/06/14 15:49:35 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_dlst ***stack_a, t_dlst ***stack_b, int ac, char **av)
{
	*stack_a = create_stack((const int )ac, (const char **)av);
	if (!*stack_a || !**stack_a)
		return (0);
	*stack_b = (t_dlst **)malloc(sizeof(t_dlst *));
	**stack_b = NULL;
	return (1);
}
