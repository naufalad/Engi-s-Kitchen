#include<stdio.h>
#include <stdlib.h>
#include "arraypesanan.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (TabPesanan * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (TabPesanan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return Neff(T);
}
int MaxNbEl (TabPesanan T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax-IdxMin+1;
}
/* *** Selektor INDEKS *** */
int GetFirstIdx (TabPesanan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
int GetLastIdx (TabPesanan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return Neff(T)+IdxMin-1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArray (TabPesanan T, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (i>=GetFirstIdx(T) && i<=MaxNbEl(T));
}
boolean IsIdxEffArray (TabPesanan T, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabPesanan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFullArray (TabPesanan T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (Neff(T) == MaxNbEl(T));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabPesanan * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T) Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  int n;
  do {
  scanf("%d",&n);
  } while(!(n>=0 && n<=MaxNbEl(*T) ));
  int i;//iterator
  MakeEmptyArray(T);
  for(i=0;i<n;i++){
    ElmtArray(*T,IdxMin+i).Menu = InputKata();
    scanf("%d", &ElmtArray(*T,IdxMin+i).MejaID);
    Neff(*T)++;
  }
}
void BacaIsiTab (TabPesanan * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
  int i = IdxMin;//Index
  //baca input
  Kata temp;
  MakeEmptyArray(T);
  while(IsEqKata(temp, StringToKata("-9999")) && i<=MaxNbEl(*T)){
    temp = InputKata();
    scanf("%d", &ElmtArray(*T,IdxMin+i).MejaID);
    ElmtArray(*T,i).Menu = temp;
    Neff(*T) = i;
    i++;
  }
}
void TulisIsi (TabPesanan T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
  //cek KOSONG
  if(Neff(T)==0){
    printf("Tabel kosong\n");
  }else{
    //ada isinya
    int i;//iterator
     for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
       printf("[%d]",i);
       OutputKata(ElmtArray(T,i).Menu);
       printf("-> %d",ElmtArray(T,IdxMin+i).MejaID);
       printf("\n");
     }
  }
}
void TulisIsiTab (TabPesanan T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  //cek KOSONG
  if(Neff(T)==0){
    printf("[]");
  }else{
    //tidak kosong
    //print siku buka
    printf("[");
    //print elemen ke 1 hingga terakhir-1
    int i;//iterator
    for(i=GetFirstIdx(T);i<GetLastIdx(T);i++){
      OutputKata(ElmtArray(T,i).Menu);
      printf("-> %d",ElmtArray(T,IdxMin+i).MejaID);
    }
    //print elemen terakhir dan siku tutup
    OutputKata(ElmtArray(T,i).Menu);
    printf("-> %d",ElmtArray(T,IdxMin+i).MejaID);
    printf("]");
  }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
boolean SearchArray (TabPesanan T, PesananID X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
  boolean Found = false;
  int i = GetFirstIdx(T);//iterator
  while(i<=GetLastIdx(T) && !(Found)){
    if(IsEqKata(ElmtArray(T,i).Menu,X.Menu) && ElmtArray(T,i).MejaID == X.MejaID){
      Found = true;
    }else{
      i++;
    }
  }
  return Found;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabPesanan Tin, TabPesanan * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  Neff(*Tout) = Neff(Tin);
  int i;//Iterator
  for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
    ElmtArray(*Tout,i) = ElmtArray(Tin,i);
  }
}
TabPesanan InverseTab (TabPesanan T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  TabPesanan temp;
  Neff(temp) = Neff(T);
  //cek KOSONG
  if(Neff(T)==0){
    return temp;//karena temp adalah tabel kosong
  }else{
    //isi temp secara terbalik
    int i;//iterator
    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      ElmtArray(temp,Neff(temp)-i+GetFirstIdx(T)) = ElmtArray(T,i);
    }
    //selesai mengisi
    return temp;
  }
}
boolean IsSimetris (TabPesanan T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  //cek KOSONG
  if(Neff(T)==0){
    return true;
  }else{
    TabPesanan putar = InverseTab(T);
    return (TI(T) == TI(putar));
  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabPesanan * T, PesananID X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  Neff(*T)++;
  ElmtArray(*T,GetLastIdx(*T)) = X;
}
void AddEli (TabPesanan * T, PesananID X, int i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
  int j;
  Neff(*T) ++;
  j = GetLastIdx(*T)-1;
  while(j >= i)
  {
    ElmtArray(*T, j+1) = ElmtArray(*T, j);
    j -= 1;
  }

  ElmtArray(*T, i) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabPesanan * T, PesananID * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = ElmtArray(*T, GetLastIdx(*T));
    Neff(*T) -= 1;
}
void DelEli (TabPesanan * T, int i, PesananID * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
  if (IsIdxEffArray(*T, i))
  {
    *X = ElmtArray(*T, i);
    int j;//iterator
    for (j=i; j <= GetLastIdx(*T); j++)
    {
      ElmtArray(*T, j) = ElmtArray(*T, j+1);
    }
    Neff(*T) -= 1;
  }
}

void SubKesabaranArray (TabPesanan* T, int* Life) {
  if (!IsEmptyArray(*T)) {
    int i = 1, j = 1;
    while (true) {
      --Elmt(*T,i).Kesabaran;
      if (Kesabaran(Elmt(*T,i)) == 0) {
          --*Life;
      } else {
          Elmt(*T,j) = Elmt(*T,i);
          j++;
      }
      if (i == Neff(*T)) break;
      i++;
    }
    Neff(*T) = j-1;
  }
}