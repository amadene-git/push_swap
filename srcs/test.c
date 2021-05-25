#include "push_swap.h"
#include <fcntl.h>



int main()
{
    for (int i = 0; i < 500; i++)
        printf("%d ", (i % 2) ? i : 500 - i);
    for (int i = 0; i > -500; i--)
        printf("%d ", (i % 2) ? i : -500 + i);
    return (0);
}