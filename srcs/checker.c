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

int	v_check(t_dlst **stack_a, t_dlst **stack_b, char *line, int *i)
{
	*i = get_next_line(STDIN_FILENO, &line);
	if (*i && !exec_instruct(line, stack_a, stack_b, NULL))
	{
		if (stack_a)
			dlst_free(stack_a, *stack_a);
		if (stack_b)
			dlst_free(stack_b, *stack_b);
		free(line);
		return (0);
	}
	if (*i)
	{
		stack_print(stack_a, stack_b, line);
	}
	free(line);
	return (1);
}

int	verbose_checker(t_dlst **stack_a, t_dlst **stack_b, int ac, char **av)
{
	char	*line;
	int		i;

	if (!init_stack(&stack_a, &stack_b, ac - 2, av + 2))
		return (-1);
	stack_print(stack_a, stack_b, NULL);
	i = 1;
	line = NULL;
	while (i)
		if (!v_check(stack_a, stack_b, line, &i))
			return (-1);
	i = is_sorted(stack_a, stack_b);
	if (stack_a)
		dlst_free(stack_a, *stack_a);
	if (stack_b)
		dlst_free(stack_b, *stack_b);
	if (i)
	{
		printf("Sorted !\n");
		return (1);
	}
	else
		return (0);
}

void	cheh(t_dlst **stack_a, t_dlst **stack_b, int *i)
{	
	*i = is_sorted(stack_a, stack_b);
	if (stack_a)
		dlst_free(stack_a, *stack_a);
	if (stack_b)
		dlst_free(stack_b, *stack_b);
}

int	checker(t_dlst **stack_a, t_dlst **stack_b, int ac, char **av)
{
	char	*line;
	int		i;

	if (!init_stack(&stack_a, &stack_b, ac - 1, av + 1))
		return (-1);
	i = 1;
	while (i)
	{
		i = get_next_line(STDIN_FILENO, &line);
		if (i && !exec_instruct(line, stack_a, stack_b, NULL))
		{
			if (stack_a)
				dlst_free(stack_a, *stack_a);
			if (stack_b)
				dlst_free(stack_b, *stack_b);
			free(line);
			return (-1);
		}
		free(line);
	}
	cheh(stack_a, stack_b, &i);
	if (i)
		return (1);
	else
		return (0);
}

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
