/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:50:34 by admadene          #+#    #+#             */
/*   Updated: 2021/06/17 14:50:56 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*dlst_chr_btwn(t_dlst **b, int first, int last)
{
	t_dlst	*elem1;
	t_dlst	*elem2;
	int		chr1;
	int		chr2;

	if (*b && *b == (*b)->next && (*b)->nb >= first && (*b)->nb <= last)
		return (*b);
	elem1 = dcb_init(b, &elem2, &chr1, &chr2);
	while (elem1->prev != elem2->next)
	{
		if (elem1->nb >= first && elem1->nb <= last)
		{
			elem1->chr = chr1;
			return (elem1);
		}
		else if (elem2->nb >= first && elem2->nb <= last)
		{
			elem2->chr = chr2;
			return (elem2);
		}
		else if (!dcb_utils(&elem1, &elem2, &chr1, &chr2))
			return (NULL);
	}
	return (NULL);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write (1, &c, 1);
}

int	prepare_stack_b(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*elem;

	if (!*stack_b)
		return (1);
	elem = dlst_chr(stack_b, chr_prev(stack_b, (*stack_a)->nb));
	if (!elem)
	{
		return (0);
	}
	while (elem->chr > 0)
	{
		exec_instruct("rb", stack_a, stack_b, (char **)stack_a);
		elem->chr--;
	}
	while (elem->chr < 0)
	{
		exec_instruct("rrb", stack_a, stack_b, (char **)stack_a);
		elem->chr++;
	}
	return (1);
}

void	rotate_stack_a(t_dlst **stack_a, t_dlst *elem)
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

void	rotate_stack_b(t_dlst **stack_b, t_dlst *elem)
{
	while (elem->chr > 0)
	{
		exec_instruct("rb", NULL, stack_b, (char **)stack_b);
		elem->chr--;
	}
	while (elem->chr < 0)
	{
		exec_instruct("rrb", NULL, stack_b, (char **)stack_b);
		elem->chr++;
	}
}
