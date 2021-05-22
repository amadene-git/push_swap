#include "push_swap.h"
#include <fcntl.h>





int main(const int ac, const char **av)
{
    // char    *line;
    // int i = 1;
    // line = NULL;
    // (void)ac;
    // (void)av;
    // int fd = open(av[1], O_RDONLY);
    // if (fd == -1)
    //     return (-1);
    t_dlst **begin = create_stack(ac - 1, av + 1);
    int size;
    int *tab = dlst_to_tab(begin, *begin, &size, 0);
    printf("dlst_size = %d\n", size);
    for (int i = 0; i < size; i++)
        printf("%d - %d\n",i,  tab[i]);
    printf("QUICK_SORT\n");
    quick_sort(tab, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d - %d\n",i,  tab[i]);
    int nb = chr_first(begin);
    printf("first = %d\n", nb);
    return (0);
}