/*  Nama/NIM        : Bimo Adityarahman Wiraputra/13517004
    Nama file       : queue.c
    Tanggal         : 1 Oktober 2018
    Deskripsi       : Implementasi queue.h
*/

#include "queue.h"
#include <stdlib.h>


boolean IsEmpty (Queue Q) {
    return Head(Q) == Nil && Tail(Q) == Nil;
}

boolean IsFull (Queue Q) {
    return (Head(Q) == 1 && Tail(Q) == MaxEl(Q)) || (Head(Q) > 1 && Tail(Q) == Head(Q)-1);
}

int NBElmt (Queue Q) {
    return (Tail(Q)-Head(Q)+MaxEl(Q)+1)%MaxEl(Q);
}


void CreateEmpty (Queue * Q, int Max) {
    (*Q).T = (infotype*) malloc((Max+1)*sizeof(infotype));
    if ((*Q).T == NULL) MaxEl(*Q) = 0;
    else MaxEl(*Q) = Max;
    Head(*Q) = Tail(*Q) = Nil;
}

void DeAlokasi (Queue * Q) {
    if ((*Q).T != NULL) free((*Q).T);
    Head(*Q) = Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
}

void Add (Queue * Q, infotype X) {
    if (IsEmpty(*Q)) {
        Head(*Q) = Tail(*Q) = 1;
    } else {
        ++Tail(*Q);
        if (Tail(*Q) > MaxEl(*Q)) Tail(*Q) = 1;
    }
    InfoTail(*Q) = X;
}

void Del (Queue * Q, infotype * X) {
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Tail(*Q) = Nil;
    } else {
        ++Head(*Q);
        if (Head(*Q) > MaxEl(*Q)) Head(*Q) = 1;
    }
}