#include <stdio.h>
#include "GraphLibrary.c"
#include "Heap.c"

Dijkstra (Graph *G, Vertex* S)
{

    int i;
    Vertex *TempV, *u;
    Vertex **Q;
    AdjNode *Pt;
    // Initialize the graph.
    for (i = 0; i < G -> NoOfV; i++)
    {
        TempV = G -> V[i];
        TempV -> D = 2000000000;
    }

    S -> D = 0;

    Q = GraphInitializeHeap (G);

    while (!IsEmptyHeap (Q))
    {
        u = GraphExtractMin (Q);

        Pt = u -> Adj;
        while (Pt != NULL)
        {
            TempV = Pt -> V;
            if (TempV -> Color == 'W')
            {
                if (TempV -> D > u -> D + Pt -> W)
                {
                    TempV -> D = u -> D + Pt -> W;

                }
            }

            Pt = Pt -> Next;
        }

        GraphBuildHeap (Q);

        u -> Color = 'B';
    }
}

int main (void)
{
    int i, S;
	Graph *G = MakeGraph();

	printf ("Enter the source node index: ");
	scanf ("%d", &S);

	if (S >= G -> NoOfV)
		return 1;
	Dijkstra (G, G -> V[S]);

	printf ("All data are as follows: \n");
	PrintGraphBFS (G);

	return 0;
}
