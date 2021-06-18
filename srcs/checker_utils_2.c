/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:06:03 by admadene          #+#    #+#             */
/*   Updated: 2021/06/17 14:06:32 by admadene         ###   ########.fr       */
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
