#include <stdio.h>
#include "GraphLibrary.c"

int Time = 0;

void DFSVisit (Graph *G, Vertex *u)
{
	Vertex *TempV;
	AdjNode *Pt;
	Time += 1;
	u -> DFSd = Time;

	u -> Color = 'G';

	Pt = u -> Adj;
	while (Pt != NULL)
	{
		TempV = Pt -> V;
		if (TempV -> Color == 'W')
		{
			TempV -> P = u;
			DFSVisit (G, TempV);
		}
		Pt = Pt -> Next;
	}

	u -> Color = 'B';
	Time += 1;
	u -> DFSf = Time;
}

void DFS (Graph *G)
{
	int i;
	Vertex *TempV;

	for (i = 0; i < G -> NoOfV; i++)
	{
		TempV = G -> V[i];
		TempV -> Color = 'W';
		TempV -> P = NULL;
	}

	Time = 0;
	for (i = 0; i < G -> NoOfV; i++)
	{
		TempV = G -> V[i];
		if (TempV -> Color == 'W')
			DFSVisit (G, TempV);
	}
}

int main (void)
{
	Graph *G = MakeGraph();

	DFS (G);

	printf ("\nAll dataas follows: \n");
	PrintGraphDFS (G);

	return 0;
}
