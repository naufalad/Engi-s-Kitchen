/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : listliner.c
 * Topik     : ADT List Linier
 * Tanggal   : 23 Oktober 2018   
 * Deskripsi : Membuat implementasi dari listliner.h 
*/

#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return(First(L)==Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil; 
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address P;
	
	P = (ElmtList*) malloc (sizeof(ElmtList));
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
void Dealokasi (address *P){
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address Pt;
	
	Pt = First(L);
	while ((Info(Pt) != X)&&(Next(Pt)!=Nil)) {
		Pt = Next(Pt);
	} /* Info(Pt) = X */
	if (Info(Pt)==X) {
		return Pt;
	} else /* Pt = Last(L), Next(Pt)=Nil*/ {
		return Nil;
	}
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P;
	
	P = Alokasi(X);
	if (P != Nil)
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P;
	
	P = Alokasi(X);
	if (P != Nil){
		InsertLast(L, P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	address P;
	
	*X = Info(First(*L));
	P = First(*L);
	First(*L) = Next(P);
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	address Pt, P;

	Pt = First(*L);
	while(Next(Pt)!=Nil){
		Pt = Next(Pt);
	}
	if(Pt==First(*L)) First(*L) = Nil;
	else{
		P = First(*L);
		while(Next(P)!=Pt){
			P = Next(P);
		}
		Next(P) = Nil;
	}
	*X = Info(Pt);
	Dealokasi(&Pt);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	First(*L)=P;
}	
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
	Next(P) = Next(Prec);
	Next(Prec)=P;
}	
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
	address Pt;
	
	Pt = First(*L);
	while(Next(Pt)!=Nil){
		Pt = Next(Pt);
	}
	Next(Pt) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	address P, Pt;
	
	P = Search(*L, X);
	if(P!=Nil){
		if(P==First(*L)){
			First(*L)=Next(P);
		} else{ //kalo ditengah
			Pt = First(*L);
			while((Next(Pt)!=P)){
				Pt=Next(Pt);
			}
			//kalo Next(Pt) = P(ketemu di elmt selanjutnya)
			Next(Pt)=Next(Next(Pt));
		}
		Dealokasi(&P);
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
	address Pt;
	
	Pt = First(*L);
	if(Next(Pt)==Nil){
		First(*L) = Nil;
	} else {
		while(Next(Next(Pt))!=Nil){
			Pt = Next(Pt);
		}
		*P = Next(Pt);
		Next(Pt) = Nil;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

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
		}while(Pt!=Nil);
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
	int count;
	address Pt;
	
	count = 0;
	if(!IsEmpty(L)){
		Pt = First(L);
		count++;
		while(Next(Pt)!=Nil){
			Pt = Next(Pt);
			count++;
		}
	}
	return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
	address Pt;
	infotype maksimum;
	
	Pt = First(L);
	maksimum = Info(Pt);
	while(Next(Pt)!=Nil){
		Pt = Next(Pt);
		if(Info(Pt)>maksimum) maksimum = Info(Pt);
	}
	return maksimum;
}
	
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
	if(IsEmpty(*L1)){
		First(*L3) = First(*L2);
	} else {
		First(*L3) = First(*L1);
		InsertLast(L3, First(*L2));		
	}
	CreateEmpty(L1);
	CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
