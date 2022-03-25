#include <stdlib.h>
#include "example.h"

#define VALUE 24

struct example {
    int a;
    int b;
};

e_t* e_create() {
	e_t* e = malloc(sizeof(e_t));

	if (e) {
		e->a = 15;
		e->b = 20;
	}

	return e;
}
int e_get_a(e_t* e) {
	return e->a;
}
int e_get_b(e_t* e) {
	return e->b;
}
void e_delete(e_t* e) {
	free(e);
}
