#include "point.h"
#include <stdio.h>

int main () {
    POINT P[2];
    int a,x;
    boolean isExit = false;
    while (!isExit) {
        scanf("%d",  &x);
        if (x == 0) isExit = true;
        else if (x == 1) {
            scanf("%d", &a);
            BacaPOINT(&P[a]);
        } else if (x == 2) {
            scanf("%d", &a);
            TulisPOINT(P[a]);
        } else if (x == 3) {
            printf("%d\n", EQ(P[0],P[1]));
        } else if (x == 4) {
            printf("%d\n", AdjPOINT(P[0],P[1]));
        }
    }
}