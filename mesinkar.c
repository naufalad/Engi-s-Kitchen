/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;
int CInt;

static FILE * pita;
static int retval;

void OPENFILE(char* filename)
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    pita = fopen(filename,"r");
    if (pita == NULL)
        {
        perror("failed: ");
        }
    }
void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */
    {
    /* KAMUS LOKAL */
	/* ALGORITMA */
    pita = fopen(filename,"r");
    if (pita == NULL)
        {
        perror("failed: ");
        }
	ADV();
    }

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}

void ADVInt(){
    
    fscanf(pita,"%d", &CInt);
}

char NumToChar (int x) {
    if (x == 0) return ' ';
    else return x + '0';
}