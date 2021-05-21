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

    if (!begin || !*begin)
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

int     *dlst_to_tab(t_dlst **begin, int size)
{
    (void)begin;
    (void)size;
    return (NULL);


}
