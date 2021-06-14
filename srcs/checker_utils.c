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

void	quick_sort(int *tab, int begin, int end)
{
	int	i;
	int	j;
	int	pivot;

	i = begin;
	j = end;
	pivot = begin;
	while (i < j)
	{
		while (tab[i] <= tab[pivot] && i < end)
			i++;
		while (tab[j] > tab[pivot] && j)
			j--;
		if (i < j)
			ft_swap(&tab[i], &tab[j]);
	}
	if (begin < end)
	{
		ft_swap(&tab[pivot], &tab[j]);
		quick_sort(tab, begin, j - 1);
		quick_sort(tab, j + 1, end);
	}
}

void	spu(t_dlst **stack_a, t_dlst **stack_b, t_dlst *a, t_dlst *b)
{
	while (!((!a || a == *stack_a) && (!b || b == *stack_b)))
	{
		if (a && a != *stack_a)
		{
			printf("%d", *(int *)(a->data));
			a = a->next;
		}
		if (b && b != *stack_b)
		{
			printf("\t%d", *(int *)(b->data));
			b = b->next;
		}
		printf("\n");
	}
	printf("_\t_\n");
	printf("a\tb\n\n");
}

void	stack_print(t_dlst **stack_a, t_dlst **stack_b, char *line)
{
	t_dlst	*a;
	t_dlst	*b;

	a = *stack_a;
	b = *stack_b;
	printf("**** STACK ****");
	if (line)
		printf(" -> %s", line);
	printf("\n");
	if (a)
	{
		printf("%d", *(int *)(a->data));
		a = a->next;
	}
	if (b)
	{
		printf("\t%d", *(int *)(b->data));
		b = b->next;
	}
	printf("\n");
	spu(stack_a, stack_b, a, b);
}

int	check_arg(const char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	str += i;
	if (!i || i > 10 || *str)
		return (0);
	return (1);
}

int	check_lst(t_dlst **begin, int *nb)
{
	t_dlst	*elem;

	if (!*begin)
		return (1);
	elem = *begin;
	while (elem->next != *begin)
	{
		if (*(int *)elem->data == *nb)
			return (0);
		elem = elem->next;
	}
	if (*(int *)elem->data == *nb)
		return (0);
	return (1);
}

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

int	init_stack(t_dlst ***stack_a, t_dlst ***stack_b, int ac, char **av)
{
	*stack_a = create_stack((const int )ac, (const char **)av);
	if (!*stack_a || !**stack_a)
		return (0);
	*stack_b = (t_dlst **)malloc(sizeof(t_dlst *));
	**stack_b = NULL;
	return (1);
}

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
