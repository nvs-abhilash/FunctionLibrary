#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* P;
	int Vertex;
	int Rank;
}Vertex;

Vertex* MakeSet(int X)
{
	Vertex *E1 = MakeVertex (X);
	E1 -> P = E1;
	E1 -> Rank = 0;
	return E1;
}

Vertex* FindSet (Vertex* A)
{
	if (A -> P == A)
	{
		printf (" %d |", A -> V);

		return A;
	}

	else
	{
		printf (" %d -> ", A -> V);

		A -> P = FindSet(A -> P);
		return A -> P;
	}
}

void Link(Vertex* P1, Vertex* P2)
{
	if (P1 -> Rank > P2 -> Rank)
	{
		// Join to P1.
		P2 -> P = P1;
	}

	else if (P1 -> Rank < P2 -> Rank)
	{
		// Join to P2.
		P1 -> P = P2;
	}

	else
	{
		P2 -> P = P1;
		P1 -> Rank += 1;
	}
}

void Union(Vertex *A, Vertex* B)
{
	Vertex* AP = FindSet(A);
	Vertex* BP = FindSet(B);

	if (AP != BP)
	{
		Link (AP, BP);
		printf ("\n\tUnion done!\n");
	}
	else
		fprintf (stderr, "\n\tSame P cant do union!\n");

}

/*
int main ()
{
	// Menu Driven Program.
	Vertex *Data[100], *RootNode;
	int c = 1;
	int Index = 0, CurIndex = 0, Index1 = 0, Index2 = 0, X = 0;

	system("clear");

	while (c != 0)
	{
		printf ("\nMAIN MENU\n");
		printf ("\n\t1. Make set");
		printf ("\n\t2. FindSet");
		printf ("\n\t3. Union Set");
		printf ("\n\t0. Exit");
		printf ("\n> ");

		scanf ("%d", &c);

		switch (c)
		{
			case 0 :
			{
				return 0;
				break;
			}
			case 1 :
			{
				printf ("\n\tEnter the vertex number: ");
				scanf ("%d", &X);

				system("clear");
				Data[CurIndex++] = MakeSet(X);
				printf ("\nOUTPUT - Index(%d) - %d \n", X, CurIndex - 1);
				break;
			}

			case 2 :
			{
				printf ("\n\t Enter the index: ");
				scanf ("%d", &Index);

				if (Index >= 0 && Index < CurIndex)
				{
					system("clear");
					RootNode = FindSet(Data[Index]);
					printf ("\nOUTPUT - Data = %d\n", RootNode -> Vertex);
				}

				else
				{
					system("clear");
					fprintf (stderr, "\nOUTPUT - Wrong index\n");
				}
				break;
			}

			case 3 :
			{
				printf ("\n\t Enter index 1: ");
				scanf ("%d", &Index1);
				printf ("\n\t Enter index 2: ");
				scanf ("%d", &Index2);

				if ((Index1 >= 0 && Index1 < CurIndex) && (Index2 >= 0 && Index2 < CurIndex))
				{
					system("clear");
					printf ("\nOUTPUT - ");
					Union(Data[Index1], Data[Index2]);
				}

				else
				{
					system("clear");
					fprintf (stderr, "\nOUTPUT - Wrong index\n");
				}

				break;
			}

			default :
			{
				system("clear");
				printf ("\nOUTPUT - Incorrect input.");
				break;
			}
		}
	}

	return 0;
}
*/
