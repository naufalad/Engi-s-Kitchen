#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include <math.h>

POINT MakePOINT (float X, float Y){
	POINT temp;
	
	Absis(temp) = X;
	Ordinat(temp) = Y;
	return temp;
}
void BacaPOINT (POINT * P){
	float X;
	float Y;
	
	printf("Masukkan absis dan ordinat : \n");
	scanf("%f %f", &X, &Y);
	Absis(*P) = X;
	Ordinat(*P) = Y;
}
void TulisPOINT (POINT P){
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
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

POINT NextX (POINT P){
	Absis(P)++;
	return (P);
}

POINT NextY (POINT P){
	Ordinat(P)++;
	return (P);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return(P);
}

POINT MirrorOf (POINT P, boolean SbX){
	if(SbX){
		Ordinat(P) *= -1;
	} else {
		Absis(P) *= -1;
	}
	return P;
}

float Jarak0 (POINT P){
	float temp;
	temp = sqrt((Absis(P)*Absis(P))+(Ordinat(P)*Ordinat(P)));
	return temp;
}

float Panjang (POINT P1, POINT P2){
	float temp;
	temp = sqrt(((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2))+((Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2)))));
	return temp;
}

void Geser (POINT *P, float deltaX, float deltaY){
	*P = PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX (POINT *P){
	Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
	Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
	*P = MirrorOf(*P, SbX);
}
void Putar (POINT *P, float Sudut){
	
	Absis(*P) = Absis(*P)*cos(Sudut) - Ordinat(*P)*sin(Sudut);
	Ordinat(*P) = Absis(*P)*sin(Sudut) - Ordinat(*P)*cos(Sudut);
}
