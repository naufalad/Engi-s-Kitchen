/* File: bacaResep.c */

#include "bintree.h"
#include "mesinkar.h"

int main()
    {
    /* KAMUS */
	int i;
	BinTree P;
	/* ALGORITMA */
	i = 1;
	START("resep.txt");
	BuildTree(&P,&i);
	printf("\nResep :\n");
	PrintTree(P,4);
    }
