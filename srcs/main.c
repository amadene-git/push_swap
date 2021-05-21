#include "../includes/push_swap.h"

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

void    stack_print(t_dlst **stack_a, t_dlst **stack_b, char *line)
{
    t_dlst  *a;
    t_dlst  *b;

    a = *stack_a;
    b = *stack_b;
    printf("**** STACK **** -> %s\n", line);
    if (a)
    {
        printf("%d", *(int*)(a->data));
        a = a->next;
    }
    if (b)
    {
        printf("\t%d", *(int*)(b->data));
        b = b->next;
    }
    printf("\n");
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

int			check_arg(const char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	str += i;
	if (!i || i > 10 || *str)
		return (0);
	return (1);
}

int     check_lst(t_dlst **begin, int *nb)
{
    t_dlst  *elem;

    if (!*begin)
        return (1);
    elem = *begin;
    while (elem->next != *begin)
    {
        if (*(int*)elem->data == *nb)
            return (0);
        elem = elem->next;
    }
    if (*(int*)elem->data == *nb)
        return (0);
    return (1);
}

t_dlst		**create_stack(const int ac, const char **av)
{
	t_dlst		**begin;
	long int	tmp;
	int			*nb;
	int			i;

	begin = (t_dlst**)malloc(sizeof(t_dlst*));
	*begin = NULL;	
	i = 0;
	while (i < ac)
	{
		tmp = ft_atoli(av[i]);
        if (tmp < INT_MIN || tmp > INT_MAX || !check_arg(av[i]))
        {
            dlst_free(begin, *begin);
            return (NULL);
        }
        nb = (int*)malloc(sizeof(int));
		*nb = (int)tmp;
		if (!check_lst(begin, nb) || !dlst_push_bottom(begin, dlst_create_elem(nb)))
        {
            dlst_free(begin, *begin);
            free(nb);
			return (NULL);
        }
        i++;	
	}
    if (!*begin)
    {
        free(begin);
        begin = NULL;
        exit(1);
    }
    return (begin);
}

int     exec_instruct(const char *str, t_dlst **stack_a, t_dlst **stack_b)
{
    if (!ft_strcmp(str, "sa"))
        swap_stack(stack_a);
    else if (!ft_strcmp(str, "sb"))
        swap_stack(stack_b);
    else if (!ft_strcmp(str, "ss"))
    {
        swap_stack(stack_a);
        swap_stack(stack_b);
    }
    else if (!ft_strcmp(str, "pa"))
        push_stack(stack_b, stack_a);
    else if (!ft_strcmp(str, "pb"))
        push_stack(stack_a, stack_b);
    else if (!ft_strcmp(str, "ra"))
        rotate(stack_a);
    else if (!ft_strcmp(str, "rb"))
        rotate(stack_b);
    else if (!ft_strcmp(str, "rr"))
    {
        rotate(stack_a);
        rotate(stack_b);
    }
    else if (!ft_strcmp(str, "rra"))
        reverse_rotate(stack_a);
    else if (!ft_strcmp(str, "rrb"))
        reverse_rotate(stack_b);
    else if (!ft_strcmp(str, "rrr"))
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
    }
    else if (*str)
        return (0);
    return (1);
}

int     is_sorted(t_dlst **stack_a, t_dlst **stack_b)
{
    t_dlst  *elem;

    if (*stack_b || !*stack_a)
        return (0);
    elem = *stack_a;
    while (elem->next != *stack_a)
    {
        if (*(int*)elem->data > *(int*)elem->next->data)
            return (0);
        elem = elem->next;
    }
    return (1);
}

int init_stack(t_dlst ***stack_a, t_dlst ***stack_b, const int ac, const char **av)
{
    *stack_a = create_stack(ac, av);
    if (!*stack_a || !**stack_a)
        return (0);
    *stack_b = (t_dlst**)malloc(sizeof(t_dlst*));
    **stack_b = NULL;
    return (1);
}

int     verbose_checker(t_dlst **stack_a, t_dlst **stack_b, const int ac, const char **av)
{
    int     nb;
    char    *line;

    if (!init_stack(&stack_a, &stack_b, ac - 2, av + 2))
        return (0);
    stack_print(stack_a, stack_b, NULL);
    nb = 0;
    while (!is_sorted(stack_a, stack_b))
    {
        if (!get_next_line(STDIN_FILENO, &line))
        {
            if (is_sorted(stack_a, stack_b))
            {
                if (stack_a)
                    dlst_free(stack_a, *stack_a);
                if (stack_b)
                    dlst_free(stack_b, *stack_b);
                free(line);
                return (1);
            }
            if (stack_a)
                dlst_free(stack_a, *stack_a);
            if (stack_b)
                dlst_free(stack_b, *stack_b);
            free(line);
            return (0);
        }
        if (!exec_instruct(line, stack_a, stack_b))
        {
            if (stack_a)
                dlst_free(stack_a, *stack_a);
            if (stack_b)
                dlst_free(stack_b, *stack_b);
            free(line);
            return (-1);
        }
        stack_print(stack_a, stack_b, line);
        free(line);
        nb++;
    }
    if (stack_a)
        dlst_free(stack_a, *stack_a);
    if (stack_b)
        dlst_free(stack_b, *stack_b);
    printf("Sorted with %d instructions !\n", nb);
    return (1);
}

int     checker(t_dlst **stack_a, t_dlst **stack_b, const int ac, const char **av)
{
    char    *line;
    int     i;

    line = NULL;
    if (!init_stack(&stack_a, &stack_b, ac - 1, av + 1))
        return (-1);
    i = 1;
    while (!is_sorted(stack_a, stack_b))
    {
        if (!get_next_line(STDIN_FILENO, &line))
        {
            if (is_sorted(stack_a, stack_b))
            {
                if (stack_a)
                    dlst_free(stack_a, *stack_a);
                if (stack_b)
                    dlst_free(stack_b, *stack_b);
                free(line);
                return (1);
            }
            if (stack_a)
                dlst_free(stack_a, *stack_a);
            if (stack_b)
                dlst_free(stack_b, *stack_b);
            free(line);
            return (0);
        }
        if (!exec_instruct(line, stack_a, stack_b))
        {
            if (stack_a)
                dlst_free(stack_a, *stack_a);
            if (stack_b)
                dlst_free(stack_b, *stack_b);
            free(line);
            return (-1);
        }
        free(line);
    }
    if (stack_a)
        dlst_free(stack_a, *stack_a);
    if (stack_b)
        dlst_free(stack_b, *stack_b);
    return (1);
}

int main(const int ac, const char **av)
{
    t_dlst  **stack_a;
    t_dlst  **stack_b;
    int     ret;

    stack_a = NULL;
    stack_b = NULL;
    if (!strcmp(av[1], "-v"))
        ret = verbose_checker(stack_a, stack_b, ac, av);
    else
        ret = checker(stack_a, stack_b, ac, av);
    if (ret == 1)
        ft_putstr("OK\n");
    else if (ret == 0)
        ft_putstr("KO\n");
    else if (ret == -1)
        ft_putstr("Error\n");
    return (0);
}