#include <stdio.h>
#include "boolean.h"
#include "jam.h"
#include <time.h>


boolean IsJAMValid(int H, int M, int S){
	return((H>=0) && (H<= 23) && (M>=0) && (M<= 59) && (S>=0) && (S<=59) );
}

JAM MakeJAM(int HH, int MM, int SS){
	JAM temp;
	
	temp.HH = HH;
	temp.MM = MM;
	temp.SS = SS;
	
	return temp;
}

void BacaJAM(JAM *J){
	JAM temp;
	
	printf("Masukkan Jam : ");
	scanf("%d", &temp.HH);
	printf("\nMasukkan Menit : ");
	scanf("%d", &temp.MM);
	printf("\nMasukkan Detik : ");
	scanf("%d", &temp.SS);
	if(IsJAMValid(temp.HH, temp.MM, temp.SS)){
		*J = temp;
	} else {
		printf("Masukkan tidak valid!\n");
	}
}
void TulisJAM(JAM J){
	printf("%d:%d:%d\n", J.HH, J.MM, J.SS);
}


int GetHour(JAM J){
	int temp;
	
	temp = J.HH;
	
	return temp;
}
int GetMinute(JAM J){
	int temp;
	
	temp = J.MM;
	
	return temp;
}

int GetSecond(JAM J){
	int temp;
	
	temp = J.SS;
	
	return temp;
}
long JAMToDetik(JAM J){
	long detik;
	
	detik = (J.HH*3600)+(J.MM*60)+(J.SS);
	
	return detik;
}

JAM DetikToJAM(long N){
	JAM temp;
	
	if(N >= 86400){
		N = N%86400;
	}
	if(N>=3600){
		temp.HH = N/3600;
		N = N%3600;
	}
	if(N>=60){
		temp.MM = N/60;
		N = N%60;
	}
	temp.SS = N;
	
	return temp;
}

boolean JEQ (JAM J1, JAM J2){
	
	return( (J1.HH==J2.HH) && (J1.MM==J2.MM) && (J1.SS==J2.SS) );
}

boolean JNEQ (JAM J1, JAM J2){
	
	return ((J1.HH!=J2.HH)&& (J1.MM!=J2.MM) && (J1.SS!=J2.SS) );
}

boolean JLT (JAM J1, JAM J2){
	boolean temp;
	
	temp = false;
	if(JAMToDetik(J1)<JAMToDetik(J2)){
		temp = true;
	}
	return temp;
}

boolean JGT (JAM J1, JAM J2){
	boolean temp;
	
	temp = false;
	if(JAMToDetik(J1)>JAMToDetik(J2)){
		temp = true;
	}
	return temp;
}


JAM NextDetik(JAM J){
	JAM temp;
	
	temp = J;
	temp.SS = J.SS + 1;
	if(temp.SS>=60){
		temp.MM=temp.MM + 1;
		temp.SS = temp.SS-60;
		if(temp.MM>=60){
			temp.HH = temp.HH +1;
			temp.MM = temp.MM-60;
			if(temp.HH>=24){
				temp.HH=temp.HH-24;
			}
		}
	}
	
	
	return temp;
}

JAM NextNDetik(JAM J, int N){
	JAM temp;
	
	temp = J;
	temp.SS = J.SS + N;
	if(temp.SS>=60){
		temp.MM=temp.MM + 1;
		temp.SS = temp.SS-60;
		if(temp.MM>=60){
			temp.HH = temp.HH +1;
			temp.MM = temp.MM-60;
			if(temp.HH>=24){
				temp.HH=temp.HH-24;
			}
		}
	}
	
	return temp;
}
JAM PreviousDetik(JAM J){
	JAM temp;
	
	temp = J;
	temp.SS = J.SS - 1;
	if(temp.SS<0){
		temp.MM=temp.MM - 1;
		temp.SS = temp.SS+60;
		if(temp.MM<0){
			temp.HH = temp.HH - 1;
			temp.MM = temp.MM+60;
			if(temp.HH<0){
				temp.HH=temp.HH+24;
			}
		}
	}
	
	return temp;
}

JAM PreviousNDetik(JAM J, int N){
	JAM temp;
	
	temp = J;
	temp.SS = J.SS - N;
	if(temp.SS<0){
		temp.MM=temp.MM - 1;
		temp.SS = temp.SS+60;
		if(temp.MM<0){
			temp.HH = temp.HH - 1;
			temp.MM = temp.MM+60;
			if(temp.HH<0){
				temp.HH=temp.HH+24;
			}
		}
	}
	
	return temp;
}

long Durasi(JAM Jaw, JAM Jakh){
	long x,y;
	int lama;
	
	x = JAMToDetik(Jaw);
	y = JAMToDetik(Jakh);
	
	if(x>y){
		y = y + 86400;
	}
	
	lama = y-x;
	
	return lama;
}

JAM CurrentTime(){
	time_t rawtime;
  	JAM jam;

  	time ( &rawtime );
  	jam = DetikToJAM(rawtime);
  	jam.HH= GetHour(jam) + 7;
  	if(GetHour(jam)>23) jam.HH = GetHour(jam) - 24;
  	return jam;
}
