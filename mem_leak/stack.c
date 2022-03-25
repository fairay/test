#include <stdlib.h>
#include <stdio.h>

typedef int* arr_t;
typedef struct arr {
    arr_t ptr;
    int size;
} stack_t;

int create(stack_t* st, int size) {
    // ...
}

void delete(stack_t* st) {
    // ..
}

void push(stack_t* st, int new_el) {
    // ..
}

int pop(stack_t* st, int* code_err) {
    // ..
}
   

int main() {
    stack_t st;
    int code = create(&st, 10);
    if (code < 0) { // check create
        // return;
    }

    while (/* condition */) {
        // print menu
        // read action
        switch (action) {
            //
        }
    }
    
    delete(&st);
}
