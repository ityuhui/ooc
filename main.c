#include <stdio.h>
#include <stdlib.h>

#define MAX_SLOT_NUMBER 10

typedef struct base_t {
    struct base_vtbl_t *vptr;
} base;

typedef struct base_vtbl_t {
    void (*fun_1) (base *);
} base_vtbl;

typedef struct derived_vtbl_t {
    void (*fun_1) (base *);
} derived_vtbl;

void base_init(base * p)
{
    char fname[] = "base_init";
    printf("%s\n", fname);
}

void base_virtual_fun_1(base * p)
{
    char fname[] = "base_virtual_fun_1";
    printf("%s\n", fname);
}

typedef struct derived_t {
    base supper;
} derived;

void derived_init()
{
    char fname[] = "derived_init";
    printf("%s\n", fname);
}

void derived_virtual_fun_1(derived * p)
{
    char fname[] = "derived_virtual_fun_1";
    printf("%s\n", fname);
}

int main()
{
    base_vtbl bvtbl;
    bvtbl.fun_1 = base_virtual_fun_1;

    derived_vtbl dvtbl;
    dvtbl.fun_1 = derived_virtual_fun_1;

    base *pb = (base *) calloc(1, sizeof(base));
    pb->vptr = &bvtbl;

    base *pd = (base *) calloc(1, sizeof(derived));
    pd->vptr = &dvtbl;

    pb->vptr->fun_1(pb);

    pd->vptr->fun_1(pd);

    return 0;
}
