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

int		ps_three(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*elem;

	elem = *stack_a;
	//1 < 3 > 2 > sa ra
	//2 > 1 < 3 > sa
	//3 > 2 > 1 < sa rra

	if (((*stack_a)->prev->nb > (*stack_a)->nb && !((*stack_a)->nb < (*stack_a)->next->nb && (*stack_a)->next->nb < (*stack_a)->prev->nb)) || ((*stack_a)->nb > (*stack_a)->next->nb && (*stack_a)->next->nb > (*stack_a)->prev->nb))
		exec_instruct("sa", stack_a, stack_b);
	elem = *stack_a; 
	//3 > 1 < 2 < ra
	//2 < 3 > 1 < rra
	if (elem->nb > elem->next->nb && elem->next->nb < elem->prev->nb && elem->prev->nb < elem->nb)// 3 1 2
		exec_instruct("ra", stack_a, stack_b);
	if (elem->nb < elem->next->nb && elem->next->nb > elem->prev->nb && elem->prev->nb < elem->nb)// 2 3 1
		exec_instruct("rra", stack_a, stack_b);
	return (1);
}


int		ps_five(t_dlst **stack_a, t_dlst **stack_b)
{
	t_dlst	*elem;

	while (dlst_size(stack_a) > 3)
		exec_instruct("pb", stack_a, stack_b);
	ps_three(stack_a, stack_b);
	while (*stack_b)
	{
		elem = dlst_chr(stack_a, chr_next(stack_a, (*stack_b)->nb));
		if (!elem)
			return (0);
		while (elem->chr > 0)
		{
			exec_instruct("ra", stack_a, NULL);
			elem->chr--;
		}
		while (elem->chr < 0)
		{
			exec_instruct("rra", stack_a, NULL);
			elem->chr++;

		}
		exec_instruct("pa", stack_a, stack_b);
	}
	elem = dlst_chr(stack_a, chr_first(stack_a));
	if (!elem)
		return (0);
	while (elem->chr > 0)
	{
		exec_instruct("ra", stack_a, NULL);
		elem->chr--;
	}
	while (elem->chr < 0)
	{
		exec_instruct("rra", stack_a, NULL);
		elem->chr++;
	}
	return (1);
}


t_dlst	*dlst_chr_btwn(t_dlst **begin, int first, int last)
{
	t_dlst	*elem1;
	t_dlst	*elem2;
	int		chr1;
	int		chr2;

	if (*begin && *begin == (*begin)->next && (*begin)->nb >= first && (*begin)->nb <= last)
		return (*begin);
	elem1 = *begin;
	elem2 = (*begin)->prev;
	chr1 = 0;
	chr2 = -1;
	while (elem1 != elem2 && elem1->prev != elem2->next)
	{
		if (elem1->nb >= first && elem1->nb <= last)
		{
			elem1->chr = chr1;
			return (elem1);
		}
		if (elem2->nb >= first && elem2->nb <= last)
		{
			elem2->chr = chr2;
			return (elem2);
		}
		chr1++;
		chr2--;
		elem1 = elem1->next;
		elem2 = elem2->prev;
	}
	return (NULL);

}

void	ft_putnbr(int nbr)
{
	char c;
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
		//printf("nope\n");
		return (0);
	}
	// ft_putstr("stack_a =");
	// ft_putnbr((*stack_a)->nb);
	// ft_putstr("nb =");
	// ft_putnbr(elem->nb);
	// ft_putstr("chr =");
	// ft_putnbr(elem->chr);
	// write (1, "\n", 1);
	while (elem->chr > 0)
	{
		exec_instruct("rb", stack_a, stack_b);
		elem->chr--;
	}
	while (elem->chr < 0)
	{
		exec_instruct("rrb", stack_a, stack_b);
		elem->chr++;
	}
	return (1);
}

int	ps_hundred(t_dlst **stack_a, t_dlst **stack_b, int chunk)
{
	int	*tab;
	int	size;
	int	i;
	int	a;
	t_dlst	*elem;

	tab = dlst_to_tab(stack_a, *stack_a, &size, 0);
	quick_sort(tab, 0, size - 1);
	i = 0;
	a = 1;
	while (a <= chunk)
	{
		i = 0;
		while (i < size / chunk && (a - 1) * (size / chunk) + i < size && *stack_a)
		{
			elem = dlst_chr_btwn(stack_a, tab[(size / chunk) * a - (size / chunk)], tab[((size / chunk) * a) - 1]);
			if (!elem)
				return (0);
			while (elem->chr > 0)
			{
				exec_instruct("ra", stack_a, NULL);
				elem->chr--;
			}
			while (elem->chr < 0)
			{
				exec_instruct("rra", stack_a, NULL);
				elem->chr++;

			}
			prepare_stack_b(stack_a, stack_b);
			exec_instruct("pb", stack_a, stack_b);
			i++;
		}
		a++;
	}
	elem = dlst_chr(stack_b, chr_last(stack_b));
	if (!elem)
		return (0);
	while (elem->chr > 0)
	{
		exec_instruct("rb", stack_a, stack_b);
		elem->chr--;
	}
	while (elem->chr < 0)
	{
		exec_instruct("rrb", stack_a, stack_b);
		elem->chr++;
	}
	while (*stack_b)
		exec_instruct("pa", stack_a, stack_b);
	return (1);
}

static	char	*ft_strrev(char *str)
{
	char	rev[ft_strlen(str)];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		rev[i] = str[i];
	i--;
	while (i + 1)
		str[j++] = rev[i--];
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		signe;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	if ((signe = 1) && n < 0)
	{
		signe = 0;
		n *= -1;
	}
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (!signe)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

// 0 99 2 97 4 95 6 93 8 91 10 89 12 87 14 85 16 83 18 81 20 79 22 77 24 75 26 73 28 71 30 69 32 67 34 65 36 63 38 61 40 59 42 57 44 55 46 53 48 51 50 49 52 47 54 45 56 43 58 41 60 39 62 37 64 35 66 33 68 31 70 29 72 27 74 25 76 23 78 21 80 19 82 17 84 15 86 13 88 11 90 9 92 7 94 5 96 3 98 1
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
	if (is_sorted(stack_a, stack_b))
		return (0);
	if (ac <= 3)
	{ 
		if((*stack_a)->nb > (*stack_a)->next->nb)
			exec_instruct("sa", stack_a, NULL);
		// dlst_free(stack_a, *stack_a);
		// dlst_free(stack_b, *stack_b);
		// return (0);
	}
	else if (ac <= 11)
	 	ps_five(stack_a, stack_b);
	else
		ps_hundred(stack_a, stack_b, dlst_size(stack_a) / 20);
	dlst_free(stack_a, *stack_a);
	dlst_free(stack_b, *stack_b);

	return (0);
}
