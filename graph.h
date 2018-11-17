/* ********** Definisi TYPE Graph dengan representasi Adjacency Matrix ********** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"

/* Ukuran maksimum node */
#define NodeMax 200

typedef int indeks; /* indeks baris, kolom */
typedef boolean ElTypeGraph; 
typedef struct { 
	ElTypeGraph Adj[NodeMax+1][NodeMax+1];
    int Node; /* banyaknya node yg terdefinisi */
} Graph;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeGraph (int N, Graph * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define Node(M) (M).Node
#define Adj(M,i,j) (M).Adj[(i)][(j)]


#endif
