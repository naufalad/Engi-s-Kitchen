#include <stdio.h>
#include "boolean.h"


#ifndef MATRIKS_H
#define MATRIKS_H


#define BrsMin 1
#define BrsMax 200
#define KolMin 1
#define KolMax 200
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]


typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

static MATRIKS M;
static int ArrS[9];
static	FILE *states;
static	FILE *jawaban;
static int i,j, p, q, k;
static char pilihan;
static	MATRIKS kunci;
static int States;
static	int Jawaban;
static	int sum, jumlah;
static	boolean menang;
static char lanjut;

void convert(int x, int *p, int *q);
//I.S : inputan user(angka)
//F.S. : diconvert menjadi baris dan kolom pada matriks

void tampil();
//I.S. : board terdefinisi
//F.S. : menampilkan matriks, kalo 1 itu player 2 itu comp

void Isi(MATRIKS *M, int i, int *sum);
//prosedur yang digunakan untuk membaca inputan player dari keyboard

void TampilStates();
//I.S. : game berakhir, tersedia array of states yang telah dilewati
//F.S. : Menampilkan states tsb serta State menang jika comp. menang

#endif
