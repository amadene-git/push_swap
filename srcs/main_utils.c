/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:49:13 by admadene          #+#    #+#             */
/*   Updated: 2021/06/17 14:49:33 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_three(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*elem;

	elem = *stack_a;
	if (((*stack_a)->prev->nb > (*stack_a)->nb \
				&& !((*stack_a)->nb < (*stack_a)->next->nb \
					&& (*stack_a)->next->nb < (*stack_a)->prev->nb)) \
			|| ((*stack_a)->nb > (*stack_a)->next->nb \
				&& (*stack_a)->next->nb > (*stack_a)->prev->nb))
		exec_instruct("sa", stack_a, stack_b, (char **)stack_a);
	elem = *stack_a;
	if (elem->nb > elem->next->nb && elem->next->nb < elem->prev->nb \
			&& elem->prev->nb < elem->nb)
		exec_instruct("ra", stack_a, stack_b, (char **)stack_a);
	if (elem->nb < elem->next->nb && elem->next->nb > elem->prev->nb \
			&& elem->prev->nb < elem->nb)
		exec_instruct("rra", stack_a, stack_b, (char **)stack_a);
	return (1);
}

void	ps_five_utils(t_dlst **stack_a, t_dlst *elem)
{
	while (elem->chr > 0)
	{
		exec_instruct("ra", stack_a, NULL, (char **)stack_a);
		elem->chr--;
	}
	while (elem->chr < 0)
	{
		exec_instruct("rra", stack_a, NULL, (char **)stack_a);
		elem->chr++;
	}
}

int	ps_five(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*elem;

	while (dlst_size(stack_a) > 3)
		exec_instruct("pb", stack_a, stack_b, (char **)stack_a);
	ps_three(stack_a, stack_b);
	while (*stack_b)
	{
		elem = dlst_chr(stack_a, chr_next(stack_a, (*stack_b)->nb));
		if (!elem)
			return (0);
		ps_five_utils(stack_a, elem);
		exec_instruct("pa", stack_a, stack_b, (char **)stack_a);
	}
	elem = dlst_chr(stack_a, chr_first(stack_a));
	if (!elem)
		return (0);
	ps_five_utils(stack_a, elem);
	return (1);
}

int	dcb_utils(t_dlst **elem1, t_dlst **elem2, int *chr1, int *chr2)
{
	(*chr1)++;
	(*chr2)--;
	if (*elem1 == *elem2)
		return (0);
	*elem1 = (*elem1)->next;
	*elem2 = (*elem2)->prev;
	return (1);
}

t_dlst	*dcb_init(t_dlst **b, t_dlst **elem2, int *chr1, int *chr2)
{
	*elem2 = (*b)->prev;
	*chr1 = 0;
	*chr2 = -1;
	return (*b);
}
