/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : listrek.c
 * Topik     : ADT List Rekurens
 * Tanggal   : 26 Oktober 2018   
 * Deskripsi : Membuat implementasi dari listrek.h 
*/

#include "boolean.h"
#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
  ElmtList *P = (ElmtList*) malloc (sizeof(ElmtList));
	if (P != NULL){ //alokasi berhasil
		Info(P) = X;
		Next(P) = NULL;
	}
	return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void Dealokasi (address P){
  free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
  return(L == NULL); 
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmt(List L){
  if(IsEmpty(L)) return 0;
  else return(Next(L)==NULL);
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotype FirstElmt (List L){
  if(!IsEmpty(L)) return(Info(L));
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail(List L){
  if(Next(L)!=NULL) return(Next(L));
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(infotype e, List L){
  address P = Alokasi(e);
  if(P!=NULL){
    Next(P)=L;
    return(P);
  } else return(L);
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List KonsB(List L, infotype e){
  address P = Alokasi(e);
  if(P!=NULL){
    if(IsEmpty(L)){
      return(P);
    } else{
      Next(L) = KonsB(Tail(L),e);
      return L;
    }
  } else return L;
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* *** Operasi Lain *** */
List Copy (List L){
  List P;
  if(IsEmpty(L)){
    P = NULL;
    //return P;
  } else {
    P = Alokasi(FirstElmt(L));
    if(P==NULL) P = L;
    else{
      Next(P) = Copy(Tail(L));
    }
  }
  return(P);
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
void MCopy (List Lin, List *Lout){
  *Lout = Copy(Lin);
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
List Concat (List L1, List L2){
  List P1, P2, P3;

  if(IsEmpty(L1)) {
    P3 =Copy(L2);
    if((!IsEmpty(L2)&&(P3==L2))) P3 = NULL;
  } else {
    P1 = Copy(L1);
    if((!IsEmpty(L1)&&(P1==L1))) P3 = NULL;
    else {
      P2 = Copy(L2);
      if((!IsEmpty(L2)&&(P3==L2))) P3 = NULL;
      else P3 = Konso(FirstElmt(P1), Concat(Tail(P1), P2));
    }
  }
  return P3;
}

/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NULL */
void MConcat (List L1, List L2, List *LHsl){
  *LHsl = Concat(L1, L2);
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (List L){
  if(IsEmpty(L)){
  } else{
    printf("%d\n", Info(L));
    PrintList(Tail(L));
  }
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList (List L){
  if(IsEmpty(L)) return 0;
  else return(1+NbElmtList(Tail(L)));
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search (List L, infotype X){
  if(IsEmpty(L)){
    return false;
  } else {
    if(Info(L)==X) return true;
    else Search(Tail(L), X);
  }
}
/* Mengirim true jika X adalah anggota list, false jika tidak */