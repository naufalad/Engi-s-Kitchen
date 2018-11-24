/* ********** Definisi TYPE Graph dengan representasi Adjacency Matrix ********** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"

/* Ukuran maksimum node */
#define NodeMax 200

typedef int indeks; /* indeks baris, kolom */
typedef struct { 
	int Adj[NodeMax+1][NodeMax+1];
    int Node; /* banyaknya node yg terdefinisi */
} Graph;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeGraph (int N, Graph * G); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran N x N di "ujung kiri" memori */

/* *** Selektor *** */
#define Node(M) (M).Node
#define Adj(M,i,j) (M).Adj[(i)][(j)]

int SearchEdge (Graph G, int A, int B);
/* Mengecek jenis koneksi antara A dan B */

int SearchEdge2 (Graph G, int A, int C);
/* Mencari node yang terhubung dengan A dengan koneksi C */


void CreateEdge (Graph* G, int A, int B, int C);
/* Membuat node A dan B terhubung dengan kode C */



#endif
