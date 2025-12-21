#include <stdio.h>
#include <stdlib.h>
#include "yans_book_defs.h"

typedef ElemType* Triplet;

Status CreateTriplet(Triplet* triplet_ptr, ElemType v1, ElemType v2, ElemType v3)
{
    *triplet_ptr = (ElemType*)malloc(3 * sizeof(ElemType));
    if (*triplet_ptr == NULL)
        return OVERFLOW;
    (*triplet_ptr)[0] = v1;
    (*triplet_ptr)[1] = v2;
    (*triplet_ptr)[2] = v3;
    return OK;
}

Status DestroyTriplet(Triplet* triplet_ptr)
{
    free(*triplet_ptr);
    *triplet_ptr = NULL;
    return OK;
}

Status Get(Triplet triplet, int i, ElemType* e)
{
    if (i < 1 || i > 3)
        return ERROR;
    *e = triplet[i];
    return OK;
}

Status Put(Triplet triplet, int i, ElemType e)
{
    if (i < 1 || i > 3)
        return ERROR;
    triplet[i] = e;
    return OK;
}

Status IsAscending(Triplet triplet)
{
    if (triplet[0] < triplet[1] && triplet[1] < triplet[2])
        return TRUE;
    return FALSE;
}

Status IsDescending(Triplet triplet)
{
    if (triplet[0] > triplet[1] && triplet[1] > triplet[2])
        return TRUE;
    return FALSE;
}

Status Max(Triplet triplet, ElemType* max)
{
    *max = triplet[0] > triplet[1]
               ? (triplet[0] > triplet[2] ? triplet[0] : triplet[2])
               : (triplet[1] > triplet[2] ? triplet[1] : triplet[2]);
    return OK;
}

Status Min(Triplet triplet, ElemType* min)
{
    *min = triplet[0] < triplet[1]
               ? (triplet[0] < triplet[2] ? triplet[0] : triplet[2])
               : (triplet[1] < triplet[2] ? triplet[1] : triplet[2]);
    return OK;
}

int main(int argc, char* argv[])
{
    Triplet triplet;
    CreateTriplet(&triplet, 1, 2, 3);
    ElemType max, min;
    Max(triplet, &max);
    Min(triplet, &min);
    printf("max = %d, min = %d\n", max, min);
}
