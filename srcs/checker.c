#include "push_swap.h"

static	char	*ft_strrev(char *str)
{
	char	rev[ft_strlen(str)];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		rev[i] = str[i];
	i--;
	while (i + 1)
		str[j++] = rev[i--];
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		signe;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	if ((signe = 1) && n < 0)
	{
		signe = 0;
		n *= -1;
	}
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (!signe)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

int main(const int ac, const char **av)
{
    t_dlst  **stack_a;
    t_dlst  **stack_b;
    int     ret;

    stack_a = NULL;
    stack_b = NULL;
    if (ac > 2 && !strcmp(av[1], "-v"))
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