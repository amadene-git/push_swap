#include "push_swap.h"

int main(const int ac, const char **av)
{
    t_dlst  **stack_a;
    t_dlst  **stack_b;
    int     ret;

    stack_a = NULL;
    stack_b = NULL;
    if (ac > 1 && !strcmp(av[1], "-v"))
        ret = verbose_checker(stack_a, stack_b, ac, av);
    else
        ret = checker(stack_a, stack_b, ac, av);
    if (ret == 1)
        ft_putstr("OK\n");
    else if (ret == 0)
        ft_putstr("KO\n");
    else if (ret == -1)
        write(2, "Error\n", 6);
    return (0);
}