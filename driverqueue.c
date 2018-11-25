#include <stdio.h>
#include "prioqueue.h"

int main(){
	Queue Q;
	int i;
	infotypeQueue X;

	CreateEmptyQueue(&Q, 10);
	PrintQueue(Q);
	X.info = 4;
	X.kesabaran = 40;
	X.prio = 3;
	AddQueue(&Q, X);
	PrintQueue(Q);
	return 0;
}

