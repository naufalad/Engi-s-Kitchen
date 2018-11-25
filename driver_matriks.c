#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

int main(){
	MATRIKS M1;	
	
	MakeEmptyMatriks(&M1);
	TulisMATRIKS(M1);
	BacaMATRIKS(&M1, 3, 3);
	TulisMATRIKS(M1);
	
	
	
	return 0;
}


