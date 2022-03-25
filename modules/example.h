#ifndef EXAMPLE_H
#define EXAMPLE_H

struct example;
typedef struct example e_t;

e_t* e_create();
int e_get_a(e_t* e);
int e_get_b(e_t* e);
void e_delete(e_t* e);

#endif // EXAMPLE_H
