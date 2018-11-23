/*  Nama/NIM        : Bimo Adityarahman Wiraputra/13517004
    Tanggal         : 19 Oktoboer 2018
    Nama file       : listliner.c
    Deskripsi       : Implementasi listlinier.c
*/

#include "listlinier.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

boolean IsEmpty (List L) {
    return First(L) == Nil;
}

void CreateEmpty (List* L) {
    First(*L) = Nil;
}

address Alokasi (infotype X) {
    address P = malloc(sizeof(address));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address* P) {
    free(*P);
}

address Search (List L, infotype X) {
    address P = First(L);
    while (P != Nil && Info(P) != X)
        P = Next(P);
    return P;
}

void InsVFirst (List *L, infotype X) {
    address P = First(*L);
    address Q = Alokasi(X);
    if (Q != Nil) {
        Next(Q) = P;
        First(*L) = Q;
    }
}

void InsVLast (List* L, infotype X) {
    if (IsEmpty(*L)) {
        First(*L) = Alokasi(X);
    } else {
        address P = First(*L);
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = Alokasi(X);
    }
}

void DelVFirst (List* L, infotype* X) {
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Next(P) = Nil;
    Dealokasi(&P); 
}

void DelVLast (List* L, infotype* X) {
    address P = First(*L);
    if (Next(P) == Nil) {
        *X = Info(P);
        First(*L) = Nil;
        Dealokasi(&P);
    } else {
        while (Next(Next(P)) != Nil)
            P = Next(P);
        address Q = Next(P);
        *X = Info(Q);
        Next(P) = Nil;
        Dealokasi(&Q);
    }
}

void InsertFirst (List* L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List* L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P) {
    address Q = First(*L);
    if (Q == Nil) {
        First(*L) = P;
    } else {
        while (Next(Q) != Nil) Q = Next(Q);
        InsertAfter(L,P,Q);
    }
}

void DelFirst (List* L, address* P) {
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP (List* L, infotype X) {
    address P = First(*L);
    if (P == Nil) {}
    else if (Info(P) == X) {
        First(*L) = Next(P);
        Dealokasi(&P);
    } else {
        while (Next(P) != Nil && Info(Next(P)) != X)
            P = Next(P);
        if (Next(P) != Nil) {
            address Q = Next(P);
            Next(P) = Next(Q);
            Dealokasi(&Q);
        }
    }
}

void DelLast (List* L, address* P) {
    *P = First(*L);
    if (Next(*P) == Nil)
        First(*L) = Nil;
    else {
        while (Next(Next(*P)) != Nil)
            *P = Next(*P);
        address Q = *P;
        *P = Next(*P);
        Next(Q) = Nil;
    }
}

void DelAfter (List* L, address* Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

void PrintInfo (List L) {
    printf("[");
    int i = 0;
    address P = First(L);
    while (P != Nil) {
        if (i > 0) printf(",");
        printf("%d",Info(P));
        ++i;
        P = Next(P);
    }
    printf("]");
}

int NbElmt (List L) {
    int ans = 0;
    address P = First(L);
    while (P != Nil) {
        ++ans;
        P = Next(P);
    }
    return ans;
}

infotype Max (List L) {
    int ans = 0;
    address P = First(L);
    while (P != Nil) {
        if (Info(P) > ans) ans = Info(P);
        P = Next(P);
    }
    return ans;
}

void Konkat1 (List* L1, List* L2, List* L3) {
    First(*L3) = First(*L1);
    address P = First(*L3);
    if (P == Nil) {
        First(*L3) = First(*L2);
    } else {
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = First(*L2);
    }
    First(*L1) = First(*L2) = Nil;
}

