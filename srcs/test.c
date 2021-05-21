#include "../includes/push_swap.h"
#include <fcntl.h>

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
    char    *line;
    line = NULL;
    (void)ac;
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    while (get_next_line(fd, &line) != 0)
    {
        printf("line = %s %p\n", line, line);
        free(line);
    }
    free(line);
    get_next_line(fd, &line);
    free(line);
    get_next_line(fd, &line);
    free(line);
    get_next_line(fd, &line);
    free(line);
    get_next_line(fd, &line);
    free(line);
    get_next_line(0, &line);
    free(line);
    close(fd);
    return (0);
}