#include <stdio.h>
#include "graph.h"

int main () {
    Graph G;
    boolean isExit = false;
    int x, d, e, f;
    while(!isExit) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d", &d);
            MakeGraph(d,&G);
        } else if (x == 2) {
            scanf("%d %d", &d, &e);
            printf("%d\n", SearchEdge(G,d,e));
        } else if (x == 3) {
            scanf("%d %d", &d, &e);
            printf("%d\n", SearchEdge2(G,d,e));
        } else if (x == 4) {    
            scanf("%d %d %d", &d, &e, &f);
            CreateEdge(&G,d,e,f);
        } else if (x == 0) isExit = true;
    }

    return 0;
}