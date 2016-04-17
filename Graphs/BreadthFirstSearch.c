#include <stdio.h>
#include "GraphLibrary.c"
#include "Queue.c"

void BFS (Graph* G, Vertex* S)
{
	int i;
	Vertex *TempV, *u;
	AdjNode *Pt;
	for (i = 0; i < G -> NoOfV; i++)
	{
		TempV = G -> V[i];
		TempV -> Color = 'W';
		TempV -> D = 2000000000;
		TempV -> P = NULL;
	}

	S -> Color = 'G';
	S -> D = 0;

	Vertex** Q = malloc (sizeof (Vertex *) * G -> NoOfV);
	InitializeQ (G -> NoOfV);

	Enqueue (Q, S);
	while (!IsEmptyQ ())
	{
		u = Dequeue (Q);
		Pt = u -> Adj;
		while (Pt != NULL)
		{
			TempV = Pt -> V;
			if (TempV -> Color == 'W')
			{
				TempV -> Color = 'G';
				TempV -> D = u -> D + 1;
				TempV -> P = u;

				Enqueue (Q, TempV);
			}

			Pt = Pt -> Next;
		}

		u -> Color = 'B';
	}
}

int main (void)
{
	int i;
	Graph *G = MakeGraph();
	BFS (G, G -> V[1]);

	printf ("All data are as follows: \n");
	for (i = 0; i < (G -> NoOfV); i++)
		PrintVertexData(G -> V[i]);

	for (i = 0; i < (G -> NoOfE); i++)
		PrintEdgeData(G -> E[i]);

	return 0;
}
