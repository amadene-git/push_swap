/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:46:02 by admadene          #+#    #+#             */
/*   Updated: 2021/06/14 15:48:52 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(const int ac, const char **av)
{
	t_dlst	**stack_a;
	t_dlst	**stack_b;
	int		ret;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 2 && !ft_strcmp(av[1], "-v"))
		ret = verbose_checker(stack_a, stack_b, (int)ac, (char **)av);
	else
		ret = checker(stack_a, stack_b, (int)ac, (char **)av);
	if (ret == 1)
		ft_putstr("OK\n");
	else if (ret == 0)
		ft_putstr("KO\n");
	else if (ret == -1)
		write(2, "Error\n", 6);
	return (0);
}
