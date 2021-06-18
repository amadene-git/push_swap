/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:52:06 by admadene          #+#    #+#             */
/*   Updated: 2021/06/17 14:52:21 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psh_utils(int **tab, t_dlst **stack_a, int *size, int *a)
{
	*tab = dlst_to_tab(stack_a, *stack_a, size, 0);
	quick_sort(*tab, 0, *size - 1);
	*a = 0;
}

void	psh_utils_2(t_dlst **stack_a, t_dlst **stack_b, t_dlst *elem)
{
	rotate_stack_a(stack_a, elem);
	prepare_stack_b(stack_a, stack_b);
	exec_instruct("pb", stack_a, stack_b, (char **)stack_a);
}

int	psh_utils_3(t_dlst **stack_a, t_dlst **stack_b, t_dlst **elem, int *tab)
{
	*elem = dlst_chr(stack_b, chr_last(stack_b));
	if (!*elem)
		return (0);
	rotate_stack_b(stack_b, *elem);
	while (*stack_b)
		exec_instruct("pa", stack_a, stack_b, (char **)stack_a);
	free(tab);
	return (1);
}

int	ps_hundred(t_dlst **stack_a, t_dlst **stack_b, int chunk)
{
	int		*tab;
	int		size;
	int		i;
	int		a;
	t_dlst	*elem;

	psh_utils(&tab, stack_a, &size, &a);
	while (++a <= chunk)
	{
		i = -1;
		while ((++i < size / chunk && (a - 1) * (size / chunk) + i \
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
			psh_utils_2(stack_a, stack_b, elem);
		}
	}
	return (psh_utils_3(stack_a, stack_b, &elem, tab));
}
