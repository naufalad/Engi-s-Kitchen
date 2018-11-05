/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : array.c
 * Topik     : ADT Array
 * Tanggal   : 10 September 2018   
 * Deskripsi : Membuat suatu Abstract Data Type sesuai dengan header array.h 
*/

#include <stdio.h>
#include "boolean.h"
#include "array.h"

void MakeEmpty (TabInt * T){
	Neff(*T) = 0;
}

int NbElmt (TabInt T){
	return (Neff(T));
}
int MaxNbEl (TabInt T){
	return(IdxMax);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
	return(IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T){
	return(GetFirstIdx(T)+(Neff(T)-1));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
	return((i>=IdxMin)&&(i<=IdxMax));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
	return((i>=GetFirstIdx(T))&&(i<=GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	return(Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
	return(Neff(T)==IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
	IdxType i;
	
		do{
		scanf("%d", &Neff(*T));
	}while((Neff(*T)<0) || (Neff(*T)>MaxNbEl(*T)));
	
	if(IsEmpty(*T)==false){
		for(i=GetFirstIdx(*T); i<=Neff(*T);i++){
			scanf("%d", &TI(*T)[i]);
		}
	}
}
		
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu """"""""""diakhiri enter"""""""""" */
/*    Jika N = 0; hanya terbentuk T kosong */
void BacaIsiTab (TabInt * T){
	IdxType i;
	ElType x;
	i=GetFirstIdx(*T)-1;
	do{
		scanf("%d", &x);
		if(x!=-9999){
			i++;
			TI(*T)[i] = x;
		}
	}while((x!=-9999)&&(i<=IdxMax));
	Neff(*T)=i;
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
void TulisIsi (TabInt T){
	IdxType i;
	
	if(IsEmpty(T)){
		printf("Tabel kosong\n");
	} else{
		for(i=1;i<=Neff(T);i++){
			printf("[%d]%d\n", i, TI(T)[i]);
		}
	}
}
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
void TulisIsiTab (TabInt T){
	IdxType i;
	
	if(Neff(T)==0){
		printf("[]");
	} else{
		printf("[");
		if(Neff(T)>1){
			for(i=1;i<=Neff(T)-1;i++){
				printf("%d,", TI(T)[i]);
			}
		}
		printf("%d",TI(T)[Neff(T)]);
		printf("]");
	}
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt Tambah;
	IdxType i;
	
	Neff(Tambah)=Neff(T1);
	for(i=1;i<=Neff(Tambah);i++){
		TI(Tambah)[i]=TI(T1)[i]+TI(T2)[i];
	}
	return Tambah;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
TabInt MinusTab (TabInt T1, TabInt T2){
	TabInt Tkurang;
	IdxType i;
	
	Neff(Tkurang)=Neff(T1);
	for(i=1;i<=Neff(Tkurang);i++){
		TI(Tkurang)[i]=TI(T1)[i]-TI(T2)[i];
	}
	return Tkurang;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2){
	TabInt Tkali;
	IdxType i;
	
	Neff(Tkali)=Neff(T1);
	for(i=1;i<=Neff(Tkali);i++){
		TI(Tkali)[i]=TI(T1)[i]*TI(T2)[i];
	}
	return Tkali;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c){
	TabInt Tkali;
	IdxType i;
	
	Neff(Tkali)=Neff(Tin);
	for(i=1;i<=Neff(Tkali);i++){
		TI(Tkali)[i]=TI(Tin)[i] * c;
	}
	return Tkali;
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
	IdxType i;
	
	if(Neff(T1)==Neff(T2)){
		if(Neff(T1)==0){
			return(true);
		} else {
			i=1;
			do{
				if(TI(T1)[i]==TI(T2)[i]){
					i++;
				} else{
					return(false);
				}
			} while(i<=Neff(T1));
			return(true);
		}
	} else {
		return(false);
	}
}

/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2){
	IdxType i;
	
	if(Neff(T1)<Neff(T2)){
		return(true);
	} else{
		/*sebelumnya kalo sama doang */
		i=1;
		do{
			if(TI(T1)[i]>=TI(T2)[i]){
				return(false);
			} else {
				i++;
			}
		}while(i<=Neff(T2));
		return(true);
	}
	return(false);
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
	IdxType a,i;
	
	i=GetFirstIdx(T);
	while((i<=Neff(T)) && (TI(T)[i]!=X)){
		i++;
	}
	if(TI(T)[i]!=X){
		return(IdxUndef);
	} else {
		a=i;
	}
	return a;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X){
	boolean Found;
	IdxType i;
	
	Found=false;
	i=1;
	do{
		if(TI(T)[i]==X){
			Found=true;
		} else {
			i++;		}
	}while((i<=Neff(T))&&(!Found));
	if(Found){
		return(i);
	} else{
		return(IdxUndef);
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X){
	IdxType i;
	boolean found;
	
	i=1;
	while((i<=Neff(T))&&(TI(T)[i]!=X)){
		i++;
	}
	if(TI(T)[i]==X){
		found = true;
	} else found = false;
	return(found);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X){
	IdxType i;
	
	TI(T)[0]=X;
	i=Neff(T);
	while(TI(T)[i]!=X){
		i--;
	}
	if(i==0){
		return(false);
	} else {
		return true;
	}
}
			
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
	ElType Max;
	IdxType i;
	
	Max=TI(T)[1];
	for(i=2;i<=Neff(T);i++){
		if(TI(T)[i]>Max){
			Max=TI(T)[i];
		}
	}
	return(Max);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T){
	ElType Min;
	IdxType i;
	
	Min=TI(T)[1];
	for(i=2;i<=Neff(T);i++){
		if(TI(T)[i]<Min){
			Min=TI(T)[i];
		}
	}
	return(Min);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
	ElType Max;
	IdxType i,a;
	
	Max=TI(T)[1];
	a=1;
	for(i=2;i<=Neff(T);i++){
		if(TI(T)[i]>Max){
			Max=TI(T)[i];
			a=i;
		}
	}
	return(a);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T){
	ElType Min;
	IdxType i,a;
	
	Min=TI(T)[1];
	a=1;
	for(i=2;i<=Neff(T);i++){
		if(TI(T)[i]<Min){
			Min=TI(T)[i];
			a=i;
		}
	}
	return(a);

}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
	IdxType i;
	
	Neff(*Tout)=Neff(Tin);
	for (i=1;i<=Neff(Tin);i++){
		TI(*Tout)[i]=TI(Tin)[i];
	}
}

/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T){
	IdxType i;
	TabInt T1;

	if(IsEmpty(T)){
		return(T);
	}
	Neff(T1)=Neff(T);
	for(i=0;i<=(Neff(T));i++){
		TI(T1)[GetFirstIdx(T)+i]=TI(T)[Neff(T)-i];
	}
	return(T1);
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T){
	IdxType i;
	
	if(IsEmpty(T)) return true;
	i=0;
	do{
		if((TI(T)[IdxMin+i]==TI(T)[Neff(T)-i])){
			i++;	
		} else {
			return(false);
		}
	}while((i<=Neff(T))&&((TI(T)[IdxMin+i]==TI(T)[Neff(T)-i])));
	return(true);
}
			

/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T){
	ElType temp;
	IdxType i,pass, imax;
	
	if(!IsEmpty(*T)){
		for(pass=1;pass<=Neff(*T)-1;pass++){
			imax=pass;
			for (i=pass+1;i<=Neff(*T);i++){
				if(TI(*T)[i]>TI(*T)[imax]){
					imax = i;
				}
			}
			temp = TI(*T)[pass];
			TI(*T)[pass]=TI(*T)[imax];
			TI(*T)[imax]=temp;
		}
	}
}
			 
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
void InsSortAsc (TabInt * T){
	ElType temp;
	IdxType i,pass;
	
	if(Neff(*T)>1){
		for(pass=2;pass<=Neff(*T);pass++){
			temp=TI(*T)[pass];
			i = pass-1;
			while((TI(*T)[pass]<TI(*T)[i])&&(i>1)){
				TI(*T)[i+1]=TI(*T)[i];
				i--;
			}
			if(temp>=TI(*T)[i]){
				TI(*T)[i+1]=temp;
			} else {
				TI(*T)[i+1]=TI(*T)[i];
				TI(*T)[i]=temp;
			}
		}
	}
}
			
				
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
	Neff(*T)=Neff(*T)+1;
	TI(*T)[Neff(*T)]=X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabInt * T, ElType X, IdxType i){
	IdxType j;
	
	for(j=Neff(*T);j>=i;j--){
		TI(*T)[j+1]=TI(*T)[j];
	}
	TI(*T)[i]=X;
	Neff(*T)++;
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
	*X = TI(*T)[GetLastIdx(*T)];
	Neff(*T)=Neff(*T)-1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, ElType * X){
	IdxType j;
	
	*X= TI(*T)[i];
	for(j=i;j<=Neff(*T)-1;j++){
		TI(*T)[j]=TI(*T)[j+1];
	}
	Neff(*T)=Neff(*T)-1;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X){
	if(SearchSentinel(*T, X)){
		printf("nilai sudah ada\n");
	} else {
		Neff(*T)=Neff(*T)+1;
		TI(*T)[Neff(*T)] = X;
	}
}
	
/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X){
	return (Search2(T, X));
}

ElType MaxUrut (TabInt T){
	return (TI(T)[GetLastIdx(T)]);
}

ElType MinUrut (TabInt T){
	return (TI(T)[GetFirstIdx(T)]);
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X){
	if(Neff(*T)!=MaxNbEl(*T)){
		Neff(*T)=Neff(*T)+1;
		TI(*T)[Neff(*T)] = X;
		InsSortAsc(T);
	}
}

void Del1Urut (TabInt * T, ElType X){
	IdxType i;
	
	if(SearchB(*T, X)){
		i=Search1(*T, X);
		DelEli(T, i, &X);
	}
}
