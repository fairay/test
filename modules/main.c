#include <stdio.h>
#include "example.h"

int main() { 
    e_t *e = e_create();
    if (!e) {
        printf("struct example malloc failed!\n");
        return -1;
    }

    printf("e->a %d\n", e_get_a(e));
    printf("e->b %d\n", e_get_b(e));

    e_delete(e);
    return 0;
}
