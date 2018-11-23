#include "graph.h"

void MakeGraph (int N, Graph * M) {
    Node(*M) = N;
}

boolean SearchEdge (Graph G, int A, int B) {
    return Adj(G,A,B);
}

void CreateEdge (Graph* G, int A, int B) {
    Adj(*G,A,B) = Adj(*G,B,A) = true;
}