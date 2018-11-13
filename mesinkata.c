/* NIM/Nama  : 13517064/Naufal Aditya Dirgandhavi
 * Nama file : mesinkata.c
 * Topik     : ADT Mesin Kata
 * Tanggal   : 10 September 2018   
 * Deskripsi : Membuat suatu Abstract Data Type sesuai dengan header mesinkata.h 
*/

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

char CC;
boolean EOP;
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
	while((CC==BLANK)&&(CC!=MARK)){
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC �� BLANK atau CC = MARK */

void STARTKATA(){
	START();
	ADVKATA();
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
	IgnoreBlank();
	SalinKata();
	if(CC==MARK) EndKata=true;
	else EndKata=false;
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
	int i;
	
	i=0;
	while((CC!=MARK)&&(CC!=BLANK)&&(i<NMax)){
		i++;
		CKata.TabKata[i]=CC;
		ADV();
	}
	CKata.Length = i;
	if(!EOP) IgnoreBlank();
}
		
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


Kata StringToKata (char* s) {
	int i = 0;
	Kata K;
	while (s[i] != '\0' && i < NMax) {
		++i;
		K.TabKata[i] = s[i-1];
	}
	K.Length = i;
}

boolean IsEqKata (Kata a, Kata b) {
	if (a.Length != b.Length) return false;
	int i;
	for (i = 1; i <= a.Length; ++i) {
		if (a.TabKata[i] != b.TabKata[i])
			return false;
	}
	return true;
}