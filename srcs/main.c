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

void	main_utils(int ac, t_dlst **stack_a, t_dlst **stack_b)
{
	if (ac <= 11)
		ps_five(stack_a, stack_b);
	else if (ac <= 200)
		ps_hundred(stack_a, stack_b, 5);
	else
		ps_hundred(stack_a, stack_b, 11);
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
	main_utils(ac, stack_a, stack_b);
	dlst_free(stack_a, *stack_a);
	dlst_free(stack_b, *stack_b);
	return (0);
}
