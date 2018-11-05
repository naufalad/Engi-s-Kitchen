/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : listsirkuler.c
 * Topik     : ADT List Sirkuler
 * Tanggal   : 26 Oktober 2018   
 * Deskripsi : Membuat implementasi dari listsirkuler.h 
*/

#include "boolean.h"
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (List L){
	return(First(L)==Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil; 
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	
	ElmtList *P = (ElmtList*) malloc (sizeof(ElmtList));
	if(P!= Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return(P);
 }
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address P;
	boolean found=false;
	
	P = First(L);
	do{
		if(Info(P)==X) found = true;
		else P = Next(P);
	}while((found==false)&&(P!=First(L)));
	
	if (found==true) {
		return P;
	} else{
		return Nil;
	}
}/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P = Alokasi(X);
	
	if (P != Nil){ //alokasi berhasil
		InsertFirst(L, P);
	}
}
	
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P = Alokasi(X);
	
	if (P != Nil){ //alokasi berhasil
		InsertLast(L, P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
	address P;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	address Pt=First(*L);
	
	if(!IsEmpty(*L)){
		Next(P) = First(*L);
		while(Next(Pt)!=First(*L)){
			Pt=Next(Pt);
		}
		//Pt Elemen terakhir
		Next(Pt)=P;
		First(*L) = P;
	} else{
		First(*L) = P;
		Next(P) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
	address Pt = First(*L);
	
	if(IsEmpty(*L)) {
		First(*L) = P;
		Next(P) = P;
	} else{
		Next(P) = First(*L);
		while(Next(Pt)!=First(*L)){
			Pt=Next(Pt);
		}
		//Pt Elemen terakhir
		Next(Pt) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
	Next(P) = Next(Prec);
	Next(Prec)=P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	address Pt = First(*L);
	
	*P = First(*L);
	while(Next(Pt)!=First(*L)){
		Pt= Next(Pt);
	}
	if(*P!=Pt) {
		Next(Pt) = Next(*P);
		First(*L) = Next(*P);
		//Next(*P) = Nil;
	} else/*kalo elemen tunggal*/ CreateEmpty(L);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
	address Pt = Nil;
	
	*P=First(*L);
	while(Next(*P)!=First(*L)){
		Pt = *P;
		*P= Next(*P);
	}
	if(Pt!=Nil) Next(Pt)=First(*L);
	else/*kalo elemen tunggal*/ CreateEmpty(L);
	//Next(*P) = Nil;
}
	
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
	if(Next(Prec)==First(*L)){
		DelFirst(L, Pdel);
	} else{
		*Pdel = Next(Prec);
		Next(Prec)=Next(*Pdel);
		Next(*Pdel)=Nil;
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){
	address P = Search(*L, X);
	address Pt = First(*L);
	
	if(P!=Nil){
		if(P==First(*L)){/*elemen tunggal*/ 
			DelFirst(L, &P);
			//Next(P) = Nil;
		} else{
			while(Next(Pt)!=P){
				Pt = Next(Pt);
			}
			//Next(Pt)==P
			Next(Pt)=Next(P);
			Next(P) = Nil;
		}
		Dealokasi(P);
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	address Pt;
	
	if(IsEmpty(L)){
		printf("[]");
	} else{
		printf("[");
		Pt = First(L);
		do{
			if(Pt==First(L)) printf("%d", Info(Pt));
			else printf(",%d", Info(Pt));
			Pt=Next(Pt);
		}while(Pt!=First(L));
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
