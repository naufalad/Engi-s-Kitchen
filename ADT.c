#include <stdio.h>
#include "boolean.h"
#include "ADT.h"

void convert(int x, int *p, int *q){
	switch(x){
			case 1 :
				*p = 1;
				*q = 1;
				break;
			case 2 :
				*p = 1;
				*q = 2;
				break;
			case 3 : 
				*p = 1;
				*q = 3;
				break;
			case 4 :
				*p = 2;
				*q = 1;
				break;
			case 5 :
				*p = 2;
				*q = 2;
				break;
			case 6 :
				*p = 2;
				*q = 3;
				break;
			case 7 :
				*p = 3;
				*q = 1;
				break;
			case 8 : 
				*p = 3;
				*q = 2;
				break;
			case 9 : 
				*p = 3;
				*q = 3;
				break;
				
	}
}

void tampil(){
	char a = 'X';
	char b = 'O';
	if(Elmt(M,1,1)==1) printf("\n%c|", a);
	else if(Elmt(M,1,1)==2) printf("\n%c|", b);
	else printf("\n |");
	if(Elmt(M,1,2)==1) printf("%c", a);
	else if(Elmt(M,1,2)==2) printf("%c", b);
	else printf(" ");
	if(Elmt(M,1,3)==1) printf("|%c", a);
	else if(Elmt(M,1,3)==2) printf("|%c", b);
	else printf("| ");
	printf("\n-------\n");
	if(Elmt(M,2,1)==1) printf("%c|", a);
	else if(Elmt(M,2,1)==2) printf("%c|", b);
	else printf(" |");
	if(Elmt(M,2,2)==1) printf("%c", a);
	else if(Elmt(M,2,2)==2) printf("%c", b);
	else printf(" ");
	if(Elmt(M,2,3) ==1) printf("|%c", a);
	else if(Elmt(M,2,3) ==2) printf("|%c", b);
	else printf("| ");
	printf("\n-------\n");
	if(Elmt(M,3,1)==1) printf("%c|", a);
	else if(Elmt(M,3,1)==2) printf("%c|", b);
	else printf(" |");
	if(Elmt(M,3,2)==1) printf("%c", a);
	else if(Elmt(M,3,2)==2) printf("%c", b);
	else printf(" ");
	if(Elmt(M,3,3)==1) printf("|%c\n", a);
	else if(Elmt(M,3,3)==2) printf("|%c\n", b);
	else printf("| \n");
}
void Isi(MATRIKS *M, int i, int *sum){
	int x;
	boolean t;
	printf("Masukkan angka yang anda inginkan(1-9) : ");
	do{
		t = false;
		scanf("%d", &x);
		switch(x){
			case 1 :
				if(Elmt(*M,1,1)==0){
					Elmt(*M,1,1) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 2 :
				if(Elmt(*M,1,2)==0){
					Elmt(*M,1,2) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 3 :
				if(Elmt(*M,1,3)==0){
					Elmt(*M,1,3) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 4 :
				if(Elmt(*M,2,1)==0){
					Elmt(*M,2,1) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 5 :
				if(Elmt(*M,2,2)==0){
					Elmt(*M,2,2) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 6 :
				if(Elmt(*M,2,3) ==0){
					Elmt(*M,2,3) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 7 :
				if(Elmt(*M,3,1)==0){
					Elmt(*M,3,1) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 8 :
				if(Elmt(*M,3,2)==0){
					Elmt(*M,3,2) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			case 9 :
				if(Elmt(*M,3,3)==0){
					Elmt(*M,3,3) = i;
					t = true;
					*sum = *sum * 10 + x;
				}
				else printf("Angka sudah terisi, masukkan kembali! ");
				break;
			default :
				printf("Masukkan salah! ");
		}
	}while(t==false);
}
void TampilStates(){
	int i;
	i=1;
	printf("\nGAME STATES\n");
	do{
		if(i-1==0) printf("Basic States :");
		printf("[%d] q%d = %d\n", i-1, i-1, ArrS[i]);
		i++;
	}while(ArrS[i]!=0);
	if(menang){
		printf("\nStates Menang : \n");
		if((Elmt(M,1,1)==Elmt(M,1,2))&&(Elmt(M,1,2)==Elmt(M,1,3))) printf("(1,2,3)");
		else if((Elmt(M,2,1)==Elmt(M,2,2))&&(Elmt(M,2,2)==Elmt(M,2,3))) printf("(4,5,6)");
		else if((Elmt(M,3,1)==Elmt(M,3,2))&&(Elmt(M,3,2)==Elmt(M,3,3))) printf("(7,8,9)");
		else if((Elmt(M,1,1)==Elmt(M,2,1))&&(Elmt(M,2,1)==Elmt(M,3,1))) printf("(1,4,7)");
		else if((Elmt(M,1,2)==Elmt(M,2,2))&&(Elmt(M,2,2)==Elmt(M,3,2))) printf("(2,5,8)");
		else if((Elmt(M,1,3)==Elmt(M,2,3))&&(Elmt(M,2,3)==Elmt(M,3,3))) printf("(3,6,9)");
		else if((Elmt(M,1,1)==Elmt(M,2,2))&&(Elmt(M,2,2)==Elmt(M,3,3))) printf("(1,5,9)");
		else if((Elmt(M,1,3)==Elmt(M,2,2))&&(Elmt(M,2,2)==Elmt(M,3,1))) printf("(3,5,7)");
	}
}
