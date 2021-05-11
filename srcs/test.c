#include "../includes/push_swap.h"


int     *av_to_tabint(const char **av, int lvl)
{
    int *tab;

    tab = NULL;
    if (av[lvl])
        tab = av_to_tabint(av, lvl + 1);
    else
    {
        tab = (int*)malloc(sizeof(int) * lvl);
        return (tab);
    }
    tab[lvl] = (int)ft_atoli(av[lvl]);
    return (tab);
}

int main(int ac, char **av)
{
    int *tab = av_to_tabint((const char **)av, 0);
    
    printf("lol\n");

    for(int i = 0; i < ac - 1; i++)
        printf("%d - %d\n", i, tab[i]);
    return (0);
}