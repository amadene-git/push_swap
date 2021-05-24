/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:18:13 by admadene          #+#    #+#             */
/*   Updated: 2021/04/23 09:27:41 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst  *dlst_create_elem(void *data)
{
    t_dlst *elem;

    elem = (t_dlst*)malloc(sizeof(t_dlst));
    if (!elem)
        return (NULL);
    elem->data = data;
    elem->nb = *(int*)data;
    elem->chr = 0;
    elem->prev = NULL;
    elem->next = NULL;
    return (elem);
}

t_dlst    **dlst_push_bottom(t_dlst **begin, t_dlst *elem)
{
    if (!elem || !begin)
        return (NULL);
    if (!*begin)
    {
        *begin = elem;
        elem->next = elem;
        elem->prev = elem;
        return (begin);
    }
    elem->prev = (*begin)->prev;
    (*begin)->prev->next = elem;
    (*begin)->prev = elem;
    elem->next = *begin;    
    return (begin);
}

t_dlst	**dlst_push_top(t_dlst **begin, t_dlst *elem)
{
	if (!elem || !begin)
		return (NULL);
	if (!*begin)
	{
		elem->prev = elem;
		elem->next = elem;
		*begin = elem;
		return (begin);
	}
	elem->prev = (*begin)->prev;
	elem->next = *begin;
	(*begin)->prev->next = elem;
	(*begin)->prev = elem;
	*begin = elem;
	return (begin);
}

int     dlst_size(t_dlst **begin)
{
    t_dlst  *elem;
    int     i;

    if (!begin)
        return (-1);
    if (!*begin)
        return (0);
    i = 0;
    elem = *begin;
    while (elem->next != *begin)
    {
        elem = elem->next;
        i++;
    }
    return (i + 1);
}

void    dlst_print(t_dlst **begin)
{
    t_dlst *elem;
    int     i;

    i = -1;
    elem = *begin;
    while (elem && elem->next != *begin)
    {
        printf("%d - %d->%p - %p\n", ++i, *(int*)elem->data, elem->data, elem);
        elem = elem->next;
    }
    if (elem)
        printf("%d - %d->%p - %p\n", ++i, *(int*)elem->data, elem->data, elem);
}

void        dlst_free(t_dlst **begin, t_dlst *elem)
{
    if (!begin)
        return;
    if (!elem)
    {
        free(begin);
        return;
    }
    if (elem->next != *begin)
        dlst_free(begin, elem->next);
    else
        free(begin);
    if (elem->data)
        free(elem->data);
    free(elem);
}

t_dlst  *dlst_chr(t_dlst **begin, int nb)
{
    t_dlst  *elem;
    int     chr;

    elem = *begin;
    chr = 0;
    while (elem->next != *begin)
    {
        if (elem->nb == nb)
        {
            if (chr > dlst_size(begin) / 2)
                elem->chr = chr - dlst_size(begin);
            else
                elem->chr = chr;
            return (elem);
        }
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


t_dlst  **tab_to_dlst(int *tab, int size)
{
    int     i;
    t_dlst  **begin;

    begin = (t_dlst**)malloc(sizeof(t_dlst*));
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

int     *dlst_to_tab(t_dlst **begin, t_dlst *elem, int *size, int lvl)
{
    int *tab;

    if (!begin || !*begin)
        return (NULL);
    if (elem->next != *begin)
        tab = dlst_to_tab(begin, elem->next, size, lvl + 1);
    else
    {
        tab = (int*)malloc(sizeof(int) * (lvl + 1));
        *size = lvl + 1;
    }
    tab[lvl] = elem->nb;
    return (tab);
}
