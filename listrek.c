/*  Nama/NIM        : Bimo Adityarahman Wiraputra/13517004
    Tanggal         : 7 November 2018
    Nama file       : listrek.c
    Deskripsi       : Implementasi listrek.h
*/

#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>

address Alokasi (infotype X) {
    address P = malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address P) {
    free(P);
}

int IsEmpty (List L) {
    if (L == Nil) return 1;
    else return 0;
}

int IsOneElmt (List L) {
    if (L == Nil) return 0;
    else if (Next(L) == Nil) return 1;
    else return 0; 
}

infotype FirstElmt (List L) {
    return Info(L);
}

List Tail (List L) {
    return Next(L);
}

List Konso (infotype e, List L) {
    address P = Alokasi(e);
    if (P == Nil) return L;
    else {
        Next(P) = L;
        return P;
    }
}

List KonsB (List L, infotype e) {
    address P = Alokasi(e);
    if (P == Nil) return L;
    else if (IsEmpty(L)) return P;
    else {
        address Q = L;
        while (Next(Q) != Nil)
            Q = Next(Q);
        Next(Q) = P;
        return L;
    }
}

List Copy (List L) {
    address P = L;
    if (P == Nil) return Nil;
    else {
        address Q = Alokasi(Info(P));
        boolean flag = Q == Nil;
        address R = Q;
        while (!flag && Next(P) != Nil) {
            P = Next(P);
            address S = Alokasi(Info(P));
            flag = S == Nil;
            if (!flag) {
                Next(R) = S;
                R = S;
            }
        }
        if (flag) return Nil;
        else return Q;
    }
}

void MCopy (List Lin, List* Lout) {
    *Lout = Copy(Lin);
}

List Concat (List L1, List L2) {
    List L3 = Copy(L1);
    List L4 = Copy(L2);
    if (L3 == Nil && L1 != Nil) return Nil;
    else if (L4 == Nil && L2 != Nil) return Nil;
    else {
        if (L3 == Nil) return L4;
        address P = L3;
        while (Next(P) != Nil)
            P = Next(P);
        Next(P) = L4;
        return L3;
    }
}

void MConcat (List L1, List L2, List* LHsl) {
    *LHsl = Concat(L1,L2);
}

void PrintList (List L) {
    address P = L;
    while (P != Nil) {
        printf("%d\n",Info(P));
        P = Next(P);
    }
}

int NbElmtList (List L) {
    int ans = 0;
    address P = L;
    while (P != Nil) {
        ++ans;
        P = Next(P);
    }
    return ans;
}

boolean Search (List L, infotype X) {
    int flag = false;
    address P = L;
    while (!flag && P != Nil) {
        flag = Info(P) == X;
        P = Next(P);
    }
    return flag;
}