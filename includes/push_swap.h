/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:10:06 by admadene          #+#    #+#             */
/*   Updated: 2021/04/23 09:11:26 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct  s_dlst
{
    struct s_dlst   *prev;
    struct s_dlst   *next;
    void            *data;
}               t_dlst;

//utils
void        ft_swap(int *a, int *b);
void        ft_putstr(char *str);
char        *ft_strdup(char const *str);
size_t      ft_strlen(char const *str);
int         ft_strcmp(const char *s1, const char *s2);
long int	ft_atoli(const char *str);
int         get_next_line(int fd, char **line);


//dlst utils
t_dlst      *dlst_create_elem(void *data);
t_dlst      **dlst_push_bottom(t_dlst **begin, t_dlst *elem);
t_dlst      **dlst_push_top(t_dlst **begin, t_dlst *elem);
int         dlst_size(t_dlst **begin);
void        dlst_print(t_dlst **begin);


//push swap
int         swap_stack(t_dlst **stack);
int         push_stack(t_dlst **src, t_dlst **dest);
int         rotate(t_dlst **stack);
int         reverse_rotate(t_dlst **stack);


//main




#endif
