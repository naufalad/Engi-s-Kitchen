/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : queue.c
 * Topik     : ADT Queue
 * Tanggal   : 29 September 2018   
 * Deskripsi : Membuat implementasi dari queue.h 
*/

#include "boolean.h"
#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
	return ((Head(Q)==Nil)|| (Tail(Q)==Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
	if(Head(Q)!=1) return (Tail(Q)==Head(Q)-1);
	else return(Tail(Q)==MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q){
	if(IsEmpty(Q)) return 0;
	else {
		if(Head(Q)>Tail(Q)) return(Tail(Q)+(MaxEl(Q)-Head(Q))+1);
		else return(Tail(Q)-Head(Q)+1);
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
	(*Q).T = (infotype *) malloc((Max+1)*sizeof(infotype));
	if((*Q).T!=NULL){
		MaxEl(*Q)=Max;
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	} else {
		MaxEl(*Q)=0;
	}
}
	
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	MaxEl(*Q)=0;
	free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
	if(Tail(*Q)!=MaxEl(*Q)){
		if(Head(*Q)==0) Head(*Q)++;
		Tail(*Q)++;
	} else{
		Tail(*Q)=1;
	}
	InfoTail(*Q)=X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X){
	*X = InfoHead(*Q);
	InfoHead(*Q)=0;
	if(Head(*Q)==Tail(*Q)){
		Head(*Q)=0;
		Tail(*Q)=0;
	} else{
		if(Head(*Q)!=MaxEl(*Q)){
			Head(*Q)++;
		} else{
			Head(*Q)=1;
		}
	}
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
