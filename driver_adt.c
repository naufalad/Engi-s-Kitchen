#include <stdio.h>
#include "boolean.h"
#include "ADT.h"
#include "cobatubes.h"
#include <unistd.h>

int main(){
    Resep = assignResep();
	RealTime = CurrentTime();
	init_all();
	assignMatriks();
	TulisMATRIKS(Tampilan);
	PrintTree(Resep, 2);
	 printf("\n---------------------------------------------------------------\n");
    printf("|<NAME>          |Money: 500 |Life: 2    |Time: 5             |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("|Waiting Cust    |   | C |   |   |   |   |   |   |Food Stack  |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|2               | C | 1 | C |   |   | C | 2 | C |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   | C |   |   | P |   |   |   |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   |   |   |   |   |   |   |   |            |\n");
    printf("--------------------------------------------------------------|\n");
    printf("|Order           |   |   |   |   |   |   |   |   |Hand        |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   | X |   |   |   |   |   |   |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                | X | 3 | X |   |   | C | 4 | C |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   | X |   |   |   |   |   |   |            |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("|Command: GU                                                  |\n");
    printf("---------------------------------------------------------------\n");
	return 0;
}