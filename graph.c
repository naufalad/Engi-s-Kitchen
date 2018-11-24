#include "graph.h"

void MakeGraph (int N, Graph * G) {
    Node(*G) = N;
    int i,j;
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= N; ++j)
            Adj(*G,i,j) = 0;
}

int SearchEdge (Graph G, int A, int B) {
    return Adj(G,A,B);
}

int SearchEdge2 (Graph G, int A, int C) {
    int i;
    for (i = 1; i <= Node(G); ++i)
        if (Adj(G,A,i) == C)
            return i;
    return 0;
}

void CreateEdge (Graph* G, int A, int B, int C) {
    Adj(*G,A,B) = Adj(*G,B,A) = C;
}