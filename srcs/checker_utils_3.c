/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utlis_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:08:27 by admadene          #+#    #+#             */
/*   Updated: 2021/06/17 14:08:40 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*csu(const char *str)
{
	long int	tmp;
	int			*nb;

	tmp = ft_atoli(str);
	if (tmp < INT_MIN || tmp > INT_MAX || !check_arg(str))
	{
		return (NULL);
	}
	nb = (int *)malloc(sizeof(int));
	*nb = (int)tmp;
	return (nb);
}

t_dlst	**create_stack(const int ac, const char **av)
{
	t_dlst		**begin;
	int			*nb;
	int			i;

	begin = (t_dlst **)malloc(sizeof(t_dlst *));
	*begin = NULL;
	i = -1;
	while (++i < ac)
	{
		nb = csu(av[i]);
		if (!nb || !check_lst(begin, nb) || \
				!dlst_push_bottom(begin, dlst_create_elem(nb)))
		{
			dlst_free(begin, *begin);
			if (nb)
				free(nb);
			return (NULL);
		}
	}
	if (!*begin)
	{
		free(begin);
		exit(1);
	}
	return (begin);
}

int	ex_instr(char *str, t_dlst **stack_a, t_dlst **stack_b)
{
	if (!ft_strcmp(str, "rrr"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}	
	else if (!ft_strcmp(str, "rra"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(str, "rrb"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(str, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		return (0);
	return (1);
}

int	exec_instruct(char *str, t_dlst **stack_a, t_dlst **stack_b, char **ret)
{
	if (!ft_strcmp(str, "sa"))
		swap_stack(stack_a);
	else if (!ft_strcmp(str, "sb"))
		swap_stack(stack_b);
	else if (!ft_strcmp(str, "ss"))
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	else if (!ft_strcmp(str, "pa"))
		push_stack(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb"))
		push_stack(stack_a, stack_b);
	else if (!ft_strcmp(str, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(str, "rb"))
		rotate(stack_b);
	else if (!ex_instr(str, stack_a, stack_b))
		return (0);
	if (ret)
		ft_putendl((char *)str);
	return (1);
}

int	is_sorted(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*elem;

	if (*stack_b || !*stack_a)
		return (0);
	elem = *stack_a;
	while (elem->next != *stack_a)
	{
		if (*(int *)elem->data > *(int *)elem->next->data)
			return (0);
		elem = elem->next;
	}
	return (1);
}
