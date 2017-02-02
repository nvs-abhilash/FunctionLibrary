#include <stdio.h>
#include "GraphLibrary.c"

BellmanFord(Graph *G, Vertex *S)
{
    int i;
    Vertex *TempV;
    Edge *TempE;

    for (i = 0; i < G -> NoOfV; i++)
    {
        TempV = G -> V[i];
        TempV -> D = 2000000000;
    }

    S -> D = 0;

    for (i = 0; i < G -> NoOfV - 1; i++)
    {
        for (i = 0; i < G -> NoOfE; i++)
        {
            TempE = G -> E[i];
            if (TempE -> Des -> D > (TempE -> S -> D + TempE -> W))
                TempE -> Des -> D = (TempE -> S -> D + TempE -> W);
        }
    }

    for (i = 0; i < G -> NoOfE; i++)
    {
        TempE = G -> E[i];
        if (TempE -> Des -> D > (TempE -> S -> D + TempE -> W))
            return 1;

    }

    return 0;
}

int main (void)
{
    int i, S;
	Graph *G = MakeGraph();

	printf ("Enter the source node index: ");
	scanf ("%d", &S);

	if (S >= G -> NoOfV)
		return 1;
	int Check = BellmanFord (G, G -> V[S]);
    if (Check == 1)
    {
        fprintf (stderr, "\nNegative cycle in the graph!");
        return 0;
    }

	printf ("All data are as follows: \n");
	PrintGraphBFS (G);

	return 0;
}
