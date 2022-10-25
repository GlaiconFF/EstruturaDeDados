#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LL_dupla.h"
#include "LL_dupla.c"

int main()
{
    List *l = List_create();

    List_add_first(l, 1);
    List_add_first(l, 3);
    List_add_first(l, 5);

    List_print(l);
    rev_print_LL(l);

    return 0;
}



