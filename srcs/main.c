/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <admadene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:52:31 by admadene          #+#    #+#             */
/*   Updated: 2021/05/21 21:53:51 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_three(t_dlst **stack_a)
{
	t_dlst	*elem;

	elem = *stack_a;
	//1 < 3 > 2 > sa ra
	//2 > 1 < 3 > sa
	//3 > 2 > 1 < sa rra

	if ((elem->prev->nb > elem->nb && !(elem->nb < elem->next->nb && elem->next->nb < elem->prev->nb)) || (elem->nb > elem->next->nb && elem->next->nb > elem->prev->nb))
	{
		exec_instruct("sa", stack_a, NULL);
		write(1, "sa\n", 3);
	}
	//3 > 1 < 2 < ra
	//2 < 3 > 1 < rra
	if (elem->nb > elem->next->nb && elem->next->nb < elem->prev->nb && elem->prev->nb < elem->nb)// 3 1 2
	{
		exec_instruct("ra", stack_a, NULL);
		write(1, "ra\n", 3);
	}
	if (elem->nb < elem->next->nb && elem->next->nb > elem->prev->nb && elem->prev->nb < elem->nb)// 2 3 1
	{
		exec_instruct("rra", stack_a, NULL);
		write(1, "rra\n", 4);
	}
	return (1);
}

t_dlst	*dlst_prev_chr(_dlst **begin, int nb)
{
	t_dlst	*ret;
	t_dlst	*elem;

	elem = *begin->next;
	ret = *begin;
	while (elem != *begin)
	{
		
		elem = elem->next;
	}
}

int		ps_five(t_dlst **stack_a, t_dlst **stack_b)
{
	int	nb;
	int *tmp;

	exec_instruct("pb", stack_a, stack_b);
	write(1, "pb\npb\n", 6);
	if (dlst_size(stack_a) == 4)
	{
		exec_instruct("pb", stack_a, stack_b);
		write(1, "pb\npb\n", 6);
	}

}

int main(const int ac, const char **av)
{
	t_dlst	**stack_a;
	t_dlst	**stack_b;

	if (ac < 2)
		return (0);
	if (!init_stack(&stack_a, &stack_b, ac - 1, av + 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ac <= 3)
	{ 
		if((*stack_a)->nb > (*stack_a)->next->nb)
		{
			exec_instruct("sa", stack_a, NULL);
			write(1, "sa\n", 3);
		}
		dlst_free(stack_a, *stack_a);
		dlst_free(stack_b, *stack_b);
		return (0);
	}
	if (ac == 4)
		ps_three(stack_a);
	else if (ac <= 5)
		ps_five(stack_a, stack_b);
	dlst_free(stack_a, *stack_a);
	dlst_free(stack_b, *stack_b);

	return (0);
}
