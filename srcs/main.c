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

long int	ft_atoli(const char *str)
{
	int	neg = 1;
	long long int nb = 0;

	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb += (*str - '0') * neg;
		nb *= 10;
		str++;
	}
	if (*str && *str != ' ')
		return (0);
	nb /= 10;
	return (nb);
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
	if (!i || i > 9 || *str)
		return (0);
	return (1);
}

t_dlst		**create_stack(int ac, char **av)
{
	t_dlst		**begin;
	long int	tmp;
	int			*nb;
	int			i;

	char	*tab = (char*)calloc(1, 4294967300);

	begin = (t_dlst**)malloc(sizeof(t_dlst*));
	*begin = NULL;
	
	i = 1;
	while (i < ac)
	{
		tmp = ft_atoli(av[i]);
        if (tmp < INT_MIN || tmp > INT_MAX || !check_arg(av[i]))
        {
            ft_putstr("Error\n");
            return (NULL);
        }
		tmp += 2147483648;
		if (tab[tmp])
		{
			ft_putstr("Error\n");
            return (NULL);
		}
		else
		{
			tab[tmp] = 1;
			tmp -= 2147483648;
		}
		nb = (int*)malloc(sizeof(int));
		*nb = (int)tmp;
		if (!dlst_push_bottom(begin, dlst_create_elem(nb)))
			return (NULL);
		i++;	
	}
    free(tab);
	return (begin);
}

int     exec_instruct(char *str, t_dlst **stack_a, t_dlst **stack_b)
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
    else
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    t_dlst **stack_a = create_stack(ac, av);
    t_dlst **stack_b = (t_dlst**)malloc(sizeof(t_dlst*));
    char *line;
    int i;

    i = 1;
    *stack_b = NULL;
    if (!stack_a || !*stack_a)
        return (1);
    while (i)
    {
        get_next_line(1, &line);
        i = exec_instruct(line, stack_a, stack_b);
        if (!i)
            printf("Error\n");
        stack_print(stack_a, stack_b);
    }

    return (0);
}