/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <admadene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:49:29 by admadene          #+#    #+#             */
/*   Updated: 2021/06/09 15:21:09 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chr_next(t_dlst **begin, int nb)
{
	int	*tab;
	int	size;
	int	i;

	tab = dlst_to_tab(begin, *begin, &size, 0);
	quick_sort(tab, 0, size - 1);
	i = 0;
	while (i < size && tab[i] <= nb)
		i++;
	if (i < size)
		i = tab[i];
	else
		i = tab[0];
	free(tab);
	return (i);
}

int	chr_prev(t_dlst **begin, int nb)
{
	int	*tab;
	int	size;
	int	i;

	tab = dlst_to_tab(begin, *begin, &size, 0);
	quick_sort(tab, 0, size - 1);
	i = 0;
	while (i < size && tab[i] < nb)
		i++;
	if (i)
		i = tab[i - 1];
	else
		i = tab[size - 1];
	free(tab);
	return (i);
}

int	chr_first(t_dlst **begin)
{
	t_dlst	*elem;
	int		nb;

	nb = (*begin)->nb;
	elem = (*begin)->next;
	while (elem != *begin)
	{
		if (nb > elem->nb)
			nb = elem->nb;
		elem = elem->next;
	}
	return (nb);
}

int	chr_last(t_dlst **begin)
{
	t_dlst	*elem;
	int		nb;

	nb = (*begin)->nb;
	elem = (*begin)->next;
	while (elem != *begin)
	{
		if (nb < elem->nb)
			nb = elem->nb;
		elem = elem->next;
	}
	return (nb);
}
