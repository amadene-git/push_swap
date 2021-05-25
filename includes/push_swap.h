/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:10:06 by admadene          #+#    #+#             */
/*   Updated: 2021/05/21 17:44:08 by admadene         ###   ########.fr       */
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
    int             nb;
    int             chr;
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
void        dlst_free(t_dlst **begin, t_dlst *elem);
t_dlst      *dlst_chr(t_dlst **begin, int nb);
t_dlst      **tab_to_dlst(int *tab, int size);
int         *dlst_to_tab(t_dlst **begin, t_dlst *elem, int *size, int lvl);

//push swap
int         swap_stack(t_dlst **stack);
int         push_stack(t_dlst **src, t_dlst **dest);
int         rotate(t_dlst **stack);
int         reverse_rotate(t_dlst **stack);

//checker
void        quick_sort(int *tab, int begin, int end);
void        stack_print(t_dlst **stack_a, t_dlst **stack_b, char *line);
int         check_arg(const char *str);
int         check_lst(t_dlst **begin, int *nb);
t_dlst      **create_stack(const int ac, const char **av);
int         exec_instruct(const char *str, t_dlst **stack_a, t_dlst **stack_b);
int         is_sorted(t_dlst **stack_a, t_dlst **stack_b);
int         init_stack(t_dlst ***stack_a, t_dlst ***stack_b, const int ac, const char **av);
int         verbose_checker(t_dlst **stack_a, t_dlst **stack_b, const int ac, const char **av);
int         checker(t_dlst **stack_a, t_dlst **stack_b, const int ac, const char **av);

//push_swap_utils
int		chr_prev(t_dlst **begin, int nb);
int		chr_next(t_dlst **begin, int nb);
int		chr_first(t_dlst **begin);
int		chr_last(t_dlst **begin);


t_dlst	*dlst_chr_btwn(t_dlst **begin, int first, int last);



#endif
