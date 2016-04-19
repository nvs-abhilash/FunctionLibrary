#include <stdio.h>
#include <malloc.h>

struct Vertex;

typedef struct AdjNode
{
	struct Vertex *V;
	int W;
	struct AdjNode* Next;
}AdjNode;

typedef struct Vertex
{
	// Index of the vertex.
	int V;

	// D value of that vertex.
	int D;

	// Time stamp for DFS discovered.
	int DFSd;

	// Time stamp for DFS finish.
	int DFSf;

	// Color for traversing algorithms.
	char Color; // Values possible {'W', 'G', 'B'}

	// To know the adjacent vertices.
	AdjNode *Adj;

	// Parent to keep track of parent of the vertex (traversing)
	struct Vertex *P;

}Vertex;

typedef struct Edge
{
	// For (G -> Dir)ected Graph edge is outgoing for S,
	// incoming for Des.
	Vertex* S;
	Vertex* Des;

	int W;
}Edge;

typedef struct Graph
{
	Vertex** V;
	Edge** E;

	int Dir;
	int Wt;

	int NoOfV;
	int NoOfE;
}Graph;

Vertex* MakeVertex (int V)
{
	Vertex *TempV = malloc (sizeof (Vertex));

	TempV -> V = V;
	TempV -> D = 0;
	TempV -> Color = 'W';
	TempV -> Adj = NULL;

	return TempV;
}

Edge* MakeEdge (Vertex* S, Vertex* Des, int W)
{
	Edge *TempE = malloc (sizeof (Edge));

	TempE -> S = S;
	TempE -> Des = Des;
	TempE -> W = W;

	return TempE;
}

void PrintVertexBFS (Vertex *V)
{
	printf ("\nV%d", V -> V);
	printf ("\nD(V%d) = %d", V -> V, V -> D);
	printf ("\nColor = \'%c\'", V -> Color);
	printf ("\nAdj(V%d) = ", V -> V);

	AdjNode *P = V -> Adj;
	while (P != NULL)
	{
		printf (" V%d ", P -> V -> V);
		P = P -> Next;
	}
	printf ("\n");
}

void PrintEdgeBFS (Edge *E)
{
	printf ("\nSource : V%d", E -> S -> V);
	printf ("\nDestination : V%d", E -> Des -> V);
	printf ("\nWeight : %d", E -> W);
	printf ("\n");
}

void PrintVertexDFS (Vertex *V)
{
	printf ("\nV%d", V -> V);
	printf ("\nD(V%d) = %d", V -> V, V -> DFSd);
	printf ("\nF(V%d) = %d", V -> V, V -> DFSf);
	printf ("\nColor = \'%c\'", V -> Color);
	printf ("\nAdj(V%d) = ", V -> V);

	AdjNode *P = V -> Adj;
	while (P != NULL)
	{
		printf (" V%d ", P -> V -> V);
		P = P -> Next;
	}
	printf ("\n");
}

void PrintGraphBFS (Graph *G)
{
	int i;
	for (i = 0; i < (G -> NoOfV); i++)
		PrintVertexBFS(G -> V[i]);

}

void PrintGraphDFS (Graph *G)
{
	int i;
	for (i = 0; i < (G -> NoOfV); i++)
		PrintVertexDFS(G -> V[i]);
}

AdjNode* MakeAdjNode (Vertex* V)
{
	AdjNode *TempAdj = malloc (sizeof (AdjNode));

	TempAdj -> V = V;
	TempAdj -> W = 0;
	TempAdj -> Next = NULL;

	return TempAdj;
}

int InsertAdj (Vertex *S, Vertex *Des, int W)
{
	AdjNode *P = S -> Adj, *Q = NULL, *TempAdj;
	while (P != NULL)
	{
		if (P -> V == Des)
			return -1;
		Q = P;
		P = P -> Next;
	}

	// Adding the edge to the graph.

	TempAdj = MakeAdjNode (Des);
	if (Q != NULL)
		Q -> Next = TempAdj;

	else
		S -> Adj = TempAdj;
	return 0;
}

Graph* MakeGraph ()
{
	Graph *G = malloc (sizeof (Graph));

	int i, S, Des, Val, W, Val1, Val2;
	Vertex *TempV = NULL;


	printf ("How many vertices: ");
	scanf ("%d", &(G -> NoOfV));

	G -> V = malloc (sizeof (Vertex *) * (G -> NoOfV));
	printf ("Automatic numbering - ");
	for (i = 0; i < (G -> NoOfV); ++i)
	{
		printf ("%d ", i);
		TempV = MakeVertex (i);
		if (TempV == NULL)
		{
			fprintf (stderr, "Error creating vertex.");
			return NULL;
		}
		G -> V[i] = TempV;
	}

	printf ("How many edges: ");
	scanf ("%d", &(G -> NoOfE));

	G -> E = malloc (sizeof (Edge *) * (G -> NoOfE));

	printf ("Directed(1) or Undirected(0): ");
	scanf ("%d", &(G -> Dir));

	printf ("Weighted(1) or Unweighted(0): ");
	scanf ("%d", &(G -> Wt));

	if ((G -> Dir))
	{
		for (i = 0; i < (G -> NoOfE); i++)
		{
			W = 0;
			printf ("\nEdge %d ", i + 1);
			printf ("\nEnter Source: ");
			scanf ("%d", &S);

			printf ("\nEnter destination: ");
			scanf ("%d", &Des);

			if (S > G -> NoOfV || Des > G -> NoOfV)
			{
				fprintf (stderr, "\nInvalid Source or Destination try again!");
				i--;
				continue;
			}

			if ((G -> Wt))
			{
				printf ("\nEnter weight: ");
				scanf ("%d", &W);
			}
			Val = InsertAdj (G -> V[S], G -> V[Des], W);
			if (Val == -1)
			{
				fprintf (stderr, "\nError making adjacency list.");
				i--;
				continue;
			}
			else
				G -> E[i] = MakeEdge (G -> V[S], G -> V[Des], W);
		}
	}
	else
	{
		for (i = 0; i < (G -> NoOfE); i++)
		{
			W = 0;
			printf ("\nEdge %d: ", i + 1);
			printf ("\nEnter first Vertex: ");
			scanf ("%d", &S);

			printf ("\nEnter second Vertex: ");
			scanf ("%d", &Des);

			if (S > G -> NoOfV || Des > G -> NoOfV)
			{
				fprintf (stderr, "\nInvalid Source or Destination try again!");
				i--;
				continue;
			}

			if ((G -> Wt))
			{
				printf ("\nEnter weight: ");
				scanf ("%d", &W);
			}
			Val1 = InsertAdj (G -> V[S], G -> V[Des], W);
			Val2 = InsertAdj (G -> V[Des], G -> V[S], W);
			if (Val1 == -1 || Val2 == -1)
			{
					fprintf (stderr, "\nError making adjacency list.");
					i--;
					continue;
			}

			else
				G -> E[i] = MakeEdge (G -> V[S], G -> V[Des], W);

		}
	}

	/*
	printf ("All data are as follows: \n");
	for (i = 0; i < (G -> NoOfV); i++)
		PrintVertexData(G -> V[i]);

	for (i = 0; i < (G -> NoOfE); i++)
		PrintEdgeData(G -> E[i]);
	*/
	return G;
}
