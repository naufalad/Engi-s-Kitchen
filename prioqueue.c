/*  NIM/Nama  : 13517025/Ricky Yuliawan
    Nama file : prioqueue.c
    Topik     : Modul; Implementasi ADT dalam bahasa C
    Tanggal   : Kamis, 27 September 2018
    Deskripsi : Modul ADT Queue                                      */

/* File : prioqueue.c */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* MoDelQueue Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return Head(Q)==Nil && Tail(Q)==Nil;
    }
boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElm */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return NBElmtQueue(Q)==MaxElm(Q);
    }
int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsEmptyQueue(Q))
        {
		return 0;
        }
    else
        {
		if (Head(Q) > Tail(Q))
            {
			return (MaxElm(Q) - (Head(Q)-Tail(Q) - 1));
            }
        else
            {
			return (Tail(Q) - Head(Q) + 1);
            }
        }
    }

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElm=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
	(*Q).TI=malloc((Max+1)*sizeof(int));
	if ((*Q).TI == NULL)
        {
		MaxElm(*Q) = 0;
        }
	else
        {
		MaxElm(*Q) = Max;
        }
	Head(*Q) = 0;
	Tail(*Q) = 0;
    }

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElm(Q) diset 0 */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    free((*Q).TI);
	MaxElm(*Q)=0;
    }

/* *** Primitif Add/DelQueueete *** */
void AddQueue (Queue * Q, infotypeQueue X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
    {
    /* KAMUS LOKAL */
    int i;
    int prev;
    boolean cek;
    infotypeQueue Temp;
    /* ALGORITMA */
    if (IsEmptyQueue(*Q))
        {
        Head(*Q)=1;
        }
    Tail(*Q) = (Tail(*Q) % MaxElm(*Q)) + 1;
    ElmtQueue(*Q,Tail(*Q))=X;
    i = Tail(*Q);
    prev = Tail(*Q);
    cek = true;
    while (cek && i!=Head(*Q))
        {
        if (prev - 1 == 0)
            {
            prev=MaxElm(*Q);
            }
        else
            {
            prev--;
            }
        if (prio(Elmt(*Q,prev))<prio(Elmt(*Q,i)))
            {
            Temp=ElmtQueue(*Q,i);
            ElmtQueue(*Q,i)=ElmtQueue(*Q,prev);
            ElmtQueue(*Q,prev)=Temp;
            }
        else
            {
            cek = false;
            }
        i = prev;
        }
    }
void DelQueue (Queue * Q, infotypeQueue * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *X=InfoHead(*Q);
	if (NBElmtQueue(*Q)==1)
        {
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
        }
    else
        {
		if (Head(*Q)==MaxElm(*Q))
            {
			Head(*Q)=1;
            }
        else
            {
			Head(*Q)++;
            }
        }
    }
/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
    {
    /* KAMUS LOKAL */
    infotypeQueue X;
    /* ALGORITMA */
    while (!IsEmptyQueue(Q))
        {
        printf("%d %d\n", Prio(InfoHead(Q)), Info(InfoHead(Q)));
        DelQueue(&Q,&X);
        }
    printf("#\n");
    }
