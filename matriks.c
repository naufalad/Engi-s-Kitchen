/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : matriks.c
 * Topik     : ADT Matriks
 * Tanggal   : 16 September 2018   
 * Deskripsi : Membuat suatu Abstract Data Type sesuai dengan header matriks.h 
*/

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

void MakeMATRIKS (int NB, int NK, MATRIKS * M){

	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
	return((i>=BrsMin)&&(i<=BrsMax)&&(j>=KolMin)&&(j<=KolMax));
}
/* Mengirimkan true jika i, j adalah int yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
int GetFirstIdxBrs (MATRIKS M){
	return(BrsMin);
}
/* Mengirimkan int baris terkecil M */
int GetFirstIdxKol (MATRIKS M){
	return(KolMin);
}
/* Mengirimkan int kolom terkecil M */
int GetLastIdxBrs (MATRIKS M){
	return(NBrsEff(M));
}
/* Mengirimkan int baris terbesar M */
int GetLastIdxKol (MATRIKS M){
	return(NKolEff(M));
}
/* Mengirimkan int kolom terbesar M */
boolean IsIdxEff (MATRIKS M, int i, int j){
	return((i>=GetFirstIdxBrs(M))&&(i<=GetLastIdxBrs(M))&&(j>=GetFirstIdxKol(M))&&(j<=GetLastIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah int efektif bagi M */
int GetElmtMatriksDiagonal (MATRIKS M, int i){
	return(ElmtMatriks(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	*MHsl = MIn;
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	int i,j;
	
	
	MakeMATRIKS(NB, NK, M); /* ga yakin di manggil M nya*/
	for(i=1;i<=NBrsEff(*M);i++){
		for(j=1;j<=NKolEff(*M);j++){
			scanf("%d", &ElmtMatriks(*M,i,j));
		}
	}
}

/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
	int i,j;
	
	
	for(i=1;i<=NBrsEff(M);i++){
		for(j=1;j<=NKolEff(M);j++){
			if(i!=NBrsEff(M)){
				if(j!=NKolEff(M)){
					printf("%d ", ElmtMatriks(M,i,j));
				} else {
					printf("%d\n", ElmtMatriks(M,i,j));
				}
			} else {
				if(j!=NKolEff(M)){
					printf("%d ", ElmtMatriks(M,i,j));
				} else {
					printf("%d", ElmtMatriks(M,i,j));
				}
			}
		}
	}
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
	int i, j;
	MATRIKS M;
	
	M = M1;
	for(i=1;i<=NBrsEff(M);i++){
		for(j=1;j<=NKolEff(M);j++){
			ElmtMatriks(M,i,j)= ElmtMatriks(M1,i,j)+ElmtMatriks(M2,i,j);
		}
	}
	return M;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
	int i, j;
	MATRIKS M;
	
	M = M1;
	for(i=1;i<=NBrsEff(M);i++){
		for(j=1;j<=NKolEff(M);j++){
			ElmtMatriks(M,i,j)= ElmtMatriks(M1,i,j)-ElmtMatriks(M2,i,j);
		}
	}
	return M;
}
/* Prekondisi : M berukuran sama dengan M */

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
	int i, j, k;
	MATRIKS M;
	int sum;
	
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M);
	sum = 0;
	for(i=1;i<=NBrsEff(M);i++){
		for(j=1;j<=NKolEff(M);j++){
			for(k=1;k<=NKolEff(M1);k++){
				sum = sum + (ElmtMatriks(M1,i,k)*ElmtMatriks(M2,k,j));
			}
			ElmtMatriks(M,i,j)= sum;
			sum = 0;
		}
	}
	return M;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, int X){
	int i, j;
	MATRIKS M1;
	
	M1 = M;
	for(i=1;i<=NBrsEff(M1);i++){
		for(j=1;j<=NKolEff(M1);j++){
			ElmtMatriks(M1,i,j)= ElmtMatriks(M,i,j)*X;
		}
	}
	return M1;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, int K){
	int i, j;
	
	for(i=1;i<=NBrsEff(*M);i++){
		for(j=1;j<=NKolEff(*M);j++){
			ElmtMatriks(*M,i,j)= ElmtMatriks(*M,i,j)*K;
		}
	}
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQMatriks (MATRIKS M1, MATRIKS M2){ /* masih harus dibenerin */
	int i, j;	
	if((GetFirstIdxBrs(M1) == GetFirstIdxBrs(M2))&&(GetLastIdxKol(M1) == GetLastIdxKol(M2))&&(NBElmtMatriks(M1)==(NBElmtMatriks(M2)))){
		for(i=GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++){
			for(j=GetFirstIdxKol(M1);j<=NKolEff(M1);j++){
				if(ElmtMatriks(M1,i,j)!=ElmtMatriks(M2,i,j)) return false;
			}
		}
	} else return false;
	return true;
}
	
/* Mengirimkan true jika M1 = M2, yaitu NbElmtMatriks(M1) = NbElmtMatriks(M2) dan */
/* untuk setiap i,j yang merupakan int baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQMatriks (MATRIKS M1, MATRIKS M2){
	if(EQMatriks(M1,M2)) return (false);
	else return(true);
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
	return((NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmtMatriks(MATRIKS M){
	return(NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	return(NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
	int i,j;
	
	if(!IsBujurSangkar(M)){
		return false;
	}
	for(i=1;i<=NBrsEff(M);i++){
		for(j=1;j<=NKolEff(M);j++){
			if(ElmtMatriks(M,i,j)!= ElmtMatriks(M,j,i)) return false;
		}
	}
	return true;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
	int i,j;
	
	if(!IsBujurSangkar(M)) return false;
	else{
		for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
			for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
				if(i==j){
					if(GetElmtMatriksDiagonal(M,i)!=1){
						return false;
					}
				} else {
					if(ElmtMatriks(M,i,j)!=0){
						return false;
					}
				}
			}
		}
	}
	return true;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M){
	int i,j,count;
	
	count = 0;
	for(i=1;i<=NBrsEff(M);i++){
		for(j=1;j<=NKolEff(M);j++){
			if(ElmtMatriks(M,i,j)!=0) count++;
		}
	}
	if(count*0.1/NBElmtMatriks(M) <= 0.05) return true;
	else return false;
}
/* Mengirimkan true jika M adalah matriks sparse: mariks �gjarang�h dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M){
	return(KaliKons(M,-1));
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
	float det;
	int i, tempbaris, tempkolom, k, l;
	MATRIKS temp;
	
	if(NBrsEff(M)==1) det = ElmtMatriks(M,1,1);
	else if(NBrsEff(M)==2){
		det = (ElmtMatriks(M,1,1)*ElmtMatriks(M,2,2))-(ElmtMatriks(M,1,2)*ElmtMatriks(M,2,1));
	} else {
		det = 0;
		MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &temp);
	tempbaris = 1;
	tempkolom = 1;
	for(i=1;i<=NBrsEff(M);i++){
				// copy matriks
			for(k=1;k<=NBrsEff(M);k++){
				for(l=1;l<=NKolEff(M);l++){
						if((k!=i)&&(l!=1)){
							ElmtMatriks(temp, tempbaris, tempkolom)=ElmtMatriks(M,k,l);
							if(tempkolom!=NKolEff(temp)){
								tempkolom++;
							} else {
								if(tempbaris!=NBrsEff(temp)){
									tempbaris++;
									tempkolom = 1;
								} else {
									tempbaris = 1;
									tempkolom = 1;
								}
							}
						
					}
				}
			}
			if((i+1)%2==0) {
				det=det+(ElmtMatriks(M,i,1)*Determinan(temp));
			} else {
				det=det+(-1*Determinan(temp)*ElmtMatriks(M,i,1));
				
			}
			//copy matriks beres
		}
		
	}
	return det;
}
		
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
	*M = Inverse1(*M);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
	int i,j;
	int temp;
	for(i=1;i<=NBrsEff(*M);i++){
		for(j=i;j<=NKolEff(*M);j++){
			temp = ElmtMatriks(*M,i,j);
			ElmtMatriks(*M,i,j)= ElmtMatriks(*M,j,i);
			ElmtMatriks(*M,j,i)=temp;
		}
	}
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
void MakeEmptyMatriks(MATRIKS *M){
	int i,j;
	for(i=1;i<=NBrsEff(*M);i++){
		for(j=1;j<=NKolEff(*M);j++){
			ElmtMatriks(*M,i,j)= 0;
		}
	}
}