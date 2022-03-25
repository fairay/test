#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Trying to alloc many int's\n");

    int inp = 1;
    int *a = NULL;
    while (inp != 0) {
        printf("Input alloc int amount: ");

        int code = scanf("%d", &inp);
        printf("Alloc %d int's ", inp);
        if (code != 1) {
            printf("Wrong input!\n");
            break;
        } else if (inp < 0) {
            printf("Wrong input!\n");
            break;
        }

        a = (int*)malloc(sizeof(int) * 1e9);
    }


    // int *a = (int*)malloc(sizeof(int) * 100);
    // if (a == NULL) {
    //     printf("Alloc failed!\n");
    // } else {
    //     free(a);
    //     printf("Exit\n");
    // }

    return 0;
}
