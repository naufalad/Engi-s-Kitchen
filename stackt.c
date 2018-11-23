/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : stackt.c
 * Topik     : ADT stack
 * Tanggal   : 15 Oktober 2018   
 * Deskripsi : Membuat suatu Abstract Data Type sesuai dengan header stackt.h 
*/
#include "boolean.h"
#include "stackt.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
	Top(*S)=Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
	return(Top(S)==Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack (Stack S){
	return(Top(S)==MaxEl);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack (Stack * S, Kata X){
	Top(*S)++;
	InfoTop(*S)=X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack (Stack * S, Kata* X){
	*X= InfoTop(*S);
	Top(*S)=Top(*S)-1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
