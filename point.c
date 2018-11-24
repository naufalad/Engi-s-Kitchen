#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include <math.h>

POINT MakePOINT (int X, int Y){
	POINT temp;
	
	Absis(temp) = X;
	Ordinat(temp) = Y;
	return temp;
}
void BacaPOINT (POINT * P){
	int X;
	int Y;
	
	printf("Masukkan absis dan ordinat : \n");
	scanf("%d %d", &X, &Y);
	Absis(*P) = X;
	Ordinat(*P) = Y;
}
void TulisPOINT (POINT P){
	printf("(%d,%d)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
	return((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
	return((Absis(P1)!=Absis(P2))&&(Ordinat(P1)!=Ordinat(P2)));
}

boolean IsOrigin (POINT P){
	return((Absis(P)==0)&& (Ordinat(P)==0));
}

boolean IsOnSbX (POINT P){
	return (Ordinat(P)==0);
}

boolean IsOnSbY (POINT P){
	return (Absis(P)==0);
}

int Kuadran (POINT P){
	int temp;
	
	if(Absis(P)>0){
		if(Ordinat(P)>0){
			temp = 1;
		} else {
			temp = 4;
		}
	} else {
		if(Ordinat(P)>0){
			temp = 2;
		} else {
			temp = 3;
		}
	}
	return temp;
}

int abs (int a) {
	if (a >= 0) return a;
	return -a;
}

boolean AdjPOINT (POINT a, POINT b) {
	return abs(Absis(a)-Absis(b))+abs(Ordinat(a)-Ordinat(b)) == 1;
}