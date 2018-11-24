/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata.h"
#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    while ((CC == BLANK || CC == '\n' || CC == ';' || CC == ',' || CC =='(' || CC == ')') && CC != MARK)
        {
        ADV();
        }
    }

void STARTKATA(char* filename)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    START(filename);
    IgnoreBlank();
    if (CC == MARK)
        {
        EndKata = true;
        }
    else /* CC != MARK */
        {

        EndKata = false;
        SalinKata();
        }
    }

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    IgnoreBlank();
    if (CC == MARK)
        {
        EndKata = true;
        }
    else /* CC != MARK */
        {
        SalinKata();
        //IgnoreBlank();
        }
    }

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    i = 1;
    for (;;)
        {
        CKata.TabKata[i] = CC;
        ADV();
        if (CC == MARK || CC == ';' || CC == '\n')
            {
            break;
            }
        else
            {
            i++;
            }
        }
    CKata.Length = i;
    }

Kata StringToKata (char* s) {
	int i = 0;
	Kata K;
	while (s[i] != '\0' && i < NMax) {
		i++;
		K.TabKata[i] = s[i-1];
	}
	K.Length = i;
	return K;
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

void OutputKata(Kata K){
	for (int i = 1; i <= K.Length; ++i) {
		printf("%c", K.TabKata[i]);
	}
}

Kata InputKata(){
	char* a=NULL;
	Kata K;

	scanf("%m[^\n]%*c", &a);
	K = StringToKata(a);
	return K;
}
void Length(Kata *kata)
    {
    /* KAMUS LOK
    AL */
    int i;
    /* ALGORITMA */
    for(i = 0; kata->TabKata[i] != '\0'; i++);
    kata->Length = i;
    }



boolean compareKata(Kata kata1, char* teks)
    {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
	for(i = 0; i <= kata1.Length; i++)
        {
		if (kata1.TabKata[i] != teks[i])
            {
            return false;
            }
        }
	return true;
    }

void printID(Kata kata1){
    /* KAMUS LOKAL */
    /* ALGORITMA */
	printf("%d", kata1.ID);
    }

/*boolean IsKataSama(Kata kata1, Kata kata2)
    {
    //KAMUS LOKAL
    boolean valid = true;
    int cnt, cnt2;
    //ALGORITMA
    Length(&kata1);
    Length(&kata2);
    cnt = kata1.Length;
    cnt2 = kata2.Length;
    if(cnt  != cnt2){
        valid = false;
    }else{
            for(int i = 0; i < cnt; i++){
                if(kata1[i] != kata2[i]){
                    valid = false;
                }
            }
        }
    return valid;
    }*/	

Kata NumToKata (int x) {
    Kata K;
    if (x <= 0) K.Length = 0;
    else {
        int a = 1;
        while (10*a <= x) a *= 10;
        int i = 1;
        Kata K;
        while (a) {
            K.TabKata[i] = (x/a)+'0';
            x -= a*(x/a);
            a /= 10;
            ++i;
        }
        K.Length = i-1;
    }
    return K;
}