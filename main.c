#include <stdio.h>
#include <stdlib.h>

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    quick_sort(int *tab, int begin, int end)
{
    int i;
    int j;
    int pivot;

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
    ft_swap(&tab[pivot], &tab[j]);
    if (begin < end)
    {
        quick_sort(tab, begin, j - 1);
        quick_sort(tab, j + 1, end);
    }
}

typedef struct  s_dlst
{
    struct s_dlst   *prev;
    struct s_dlst   *next;
    void            *data;
}               t_dlst;

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
    t_dlst  *tmp;

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

t_dlst    **dlst_push_top(t_dlst **begin, t_dlst *elem)
{
    dlst_push_bottom(begin, elem);
    (*begin) = (*begin)->prev;
    return (begin);
}

void    dlst_print(t_dlst **begin)
{
    t_dlst *elem;
    int     i;

    i = -1;
    elem = *begin;
    while (elem && elem->next != *begin)
    {
        printf("%d - %s->%p - %p\n", ++i, (char*)elem->data, elem->data, elem);
        elem = elem->next;
    }
    if (elem)
        printf("%d - %s->%p - %p\n", ++i, (char*)elem->data, elem->data, elem);
}



void    stack_print(t_dlst **stack_a, t_dlst **stack_b)
{
    t_dlst  *a;
    t_dlst  *b;

    a = *stack_a;
    b = *stack_b;
    printf("**** STACK ****\n");
    if (a)
    {
        printf("%d", *(int*)(a->data));
        a = a->next;
    }
    if (b)
    {
        printf("\t%d\n", *(int*)(b->data));
        b = b->next;
    }
    while (!((!a || a == *stack_a) && (!b || b == *stack_b)))
    {
        if (a && a != *stack_a)
        {
            printf("%d", *(int*)(a->data));
            a = a->next;
        }
        if (b && b != *stack_b)
        {
            printf("\t%d", *(int*)(b->data));
            b = b->next;
        }
        printf("\n");
    }
    printf("_\t_\n");
    printf("a\tb\n\n");
}

int     swap_stack(t_dlst **stack)
{
    t_dlst  *elem;

    if (!stack || !*stack || (*stack)->next == *stack)
        return (0);
    elem = (*stack)->next;
    (*stack)->prev->next = elem;
    elem->prev = (*stack)->prev;
    (*stack)->next = (*stack)->next->next;
    (*stack)->next->next->prev = (*stack);
    elem->next = (*stack);
    (*stack)->prev = elem;    
    (*stack) = elem;
    return (1);
}



int     push_stack(t_dlst **src, t_dlst **dest)
{
    t_dlst  *elem;

    if (!src || !dest || !*src)
        return (0);
    elem = *src;
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

t_dlst  **dlst_create_lst(int *tab, int size)
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

int main(int ac, char **av)
{
    int tab[] = {1,45,6,789,1,526,78,123,555,5,696,495,654,789,654,15,46,132};//17
    t_dlst **stack_a = dlst_create_lst(&tab[0], 15);
    t_dlst **stack_b = (t_dlst**)malloc(sizeof(t_dlst*));
    *stack_b = NULL;
    
    
    stack_print(stack_a, stack_b);
    printf("swap a\n");
    swap_stack(stack_a);
    stack_print(stack_a, stack_b);
    printf("swap a\n");
    swap_stack(stack_a);
    stack_print(stack_a, stack_b);
   
    printf("PUSH\n");
    push_stack(stack_a, stack_b);
    stack_print(stack_a, stack_b);
    
    printf("PUSH\n");
    push_stack(stack_a, stack_b);
    stack_print(stack_a, stack_b);

    printf("PUSH\n");
    push_stack(stack_a, stack_b);
    stack_print(stack_a, stack_b);
    
    return (0);
}