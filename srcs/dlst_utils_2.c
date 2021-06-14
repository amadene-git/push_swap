/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:35:56 by admadene          #+#    #+#             */
/*   Updated: 2021/06/09 15:37:00 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*dlst_chr_utils(t_dlst **begin, t_dlst *elem, int chr)
{
	if (chr > dlst_size(begin) / 2)
		elem->chr = chr - dlst_size(begin);
	else
		elem->chr = chr;
	return (elem);
}

t_dlst	*dlst_chr(t_dlst **begin, int nb)
{
	t_dlst	*elem;
	int		chr;

	if (!begin || !*begin)
		return (NULL);
	elem = *begin;
	chr = 0;
	while (elem->next != *begin)
	{
		if (elem->nb == nb)
			return (dlst_chr_utils(begin, elem, chr));
		chr++;
		elem = elem->next;
	}
	if (elem->nb == nb)
	{
		if (elem != *begin)
			elem->chr = -1;
		return (elem);
	}
	return (NULL);
}

t_dlst	**tab_to_dlst(int *tab, int size)
{
	int		i;
	t_dlst	**begin;

	begin = (t_dlst **)malloc(sizeof(t_dlst *));
	if (!begin)
		return (NULL);
	*begin = NULL;
	i = 0;
	while (i < size)
	{
		if (!dlst_push_bottom(begin, dlst_create_elem(&tab[i])))
			return (NULL);
		i++;
	}
	return (begin);
}

int	*dlst_to_tab(t_dlst **begin, t_dlst *elem, int *size, int lvl)
{
	int	*tab;

	if (!begin || !*begin)
		return (NULL);
	if (elem->next != *begin)
		tab = dlst_to_tab(begin, elem->next, size, lvl + 1);
	else
	{
		tab = (int *)malloc(sizeof(int) * (lvl + 1));
		*size = lvl + 1;
	}
	tab[lvl] = elem->nb;
	return (tab);
}
