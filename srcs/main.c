/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <admadene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:52:31 by admadene          #+#    #+#             */
/*   Updated: 2021/06/14 16:28:38 by admadene         ###   ########.fr       */
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

t_dlst	*dlst_chr_btwn(t_dlst **b, int first, int last)
{
	t_dlst	*elem1;
	t_dlst	*elem2;
	int		chr1;
	int		chr2;

	if (*b && *b == (*b)->next && (*b)->nb >= first && (*b)->nb <= last)
		return (*b);
	elem1 = *b;
	elem2 = (*b)->prev;
	chr1 = 0;
	chr2 = -1;
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

int	ps_hundred(t_dlst **stack_a, t_dlst **stack_b, int chunk)
{
	int		*tab;
	int		size;
	int		i;
	int		a;
	t_dlst	*elem;

	tab = dlst_to_tab(stack_a, *stack_a, &size, 0);
	quick_sort(tab, 0, size - 1);
	i = 0;
	a = 1;
	while (a <= chunk)
	{
		i = 0;
		while ((i < size / chunk && (a - 1) * (size / chunk) + i \
					< size && *stack_a) || (a == chunk && i < size / chunk + size % chunk))
		{
			if (a == chunk)
				elem = dlst_chr_btwn(stack_a, tab[(size / chunk) *a \
						- (size / chunk)], tab[size - 1]);
			else
				elem = dlst_chr_btwn(stack_a, tab[(size / chunk) *a \
						- (size / chunk)], tab[((size / chunk) * a) - 1]);
			if (!elem)
				return (0);
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
			prepare_stack_b(stack_a, stack_b);
			exec_instruct("pb", stack_a, stack_b, (char **)stack_a);
			i++;
		}
		a++;
	}
	elem = dlst_chr(stack_b, chr_last(stack_b));
	if (!elem)
		return (0);
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
	while (*stack_b)
		exec_instruct("pa", stack_a, stack_b, (char **)stack_a);
	return (1);
}

int	main(int ac, char **av)
{
	t_dlst	**stack_a;
	t_dlst	**stack_b;

	if (ac < 2)
		return (0);
	if (ac > 501 || !init_stack(&stack_a, &stack_b, ac - 1, av + 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(stack_a, stack_b))
		return (0);
	if (ac <= 3)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			exec_instruct("sa", stack_a, NULL, (char **)stack_a);
	}
	else if (ac <= 11)
		ps_five(stack_a, stack_b);
	else if (ac <= 200)
		ps_hundred(stack_a, stack_b, 5);
	else if (ac <= 501)
		ps_hundred(stack_a, stack_b, 11);
	dlst_free(stack_a, *stack_a);
	dlst_free(stack_b, *stack_b);
	return (0);
}
