#include <stdlib.h>
#include <stdio.h>

#define NEW_SIZE    1e10

typedef int* arr_t;
struct arr {
    arr_t ptr;
    int size;
};

typedef arr_t* matrix_t;

int alloc_arr(arr_t* arr, int size) {
    // 
}

void free_arr(arr_t* arr) {
    // 
}

int alloc_matrix(matrix_t* mat, int size) {
    //
}



int main(void) {
    int* arr = NULL;
    int size = 10;
    alloc_arr(&arr, size);
    free(arr);

    printf("Trying to alloc 100 int's\n");
    int *a = malloc(sizeof(int) * 100);

    printf("Trying to realloc 1000 int's\n");
    int *b = realloc(a, sizeof(int) * NEW_SIZE);
    if (b != NULL) {
        a = b;
        b = NULL;
    }

    free(a);
    printf("Exit\n");
    return 0;
}
