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
	int i, S;
	Graph *G = MakeGraph();

	printf ("Enter the source node index: ");
	scanf ("%d", &S);

	if (S >= G -> NoOfV)
		return 1;
	BFS (G, G -> V[S]);

	printf ("All data are as follows: \n");
	PrintGraphBFS (G);

	return 0;
}
