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
