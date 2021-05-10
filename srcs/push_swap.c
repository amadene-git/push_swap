/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:32:45 by admadene          #+#    #+#             */
/*   Updated: 2021/04/23 09:42:31 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     swap_stack(t_dlst **stack)
{
	void	*data;

	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	data = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = data;
	return (1);
}

int     push_stack(t_dlst **src, t_dlst **dest)
{
	t_dlst  *elem;

	if (!src || !dest || !*src)
		return (0);
	elem = *src;
	if (elem == elem->next)
		*src = NULL;
	else
		(*src) = (*src)->next;
	elem->next->prev = elem->prev;
	elem->prev->next = elem->next;
	dest = dlst_push_top(dest, elem);
	return (1);
}

int     rotate(t_dlst **stack)
{
	if (!stack || !*stack)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

int     reverse_rotate(t_dlst **stack)
{
	if (!stack || !*stack)
		return (0);
	*stack = (*stack)->prev;
	return (1);
}
