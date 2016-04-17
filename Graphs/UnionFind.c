#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* Parent;
	int Vertex;
	int Rank;
}Element;

Element* MakeSet(int X)
{
	Element* E1 = malloc (sizeof (Element));
	E1 -> Parent = E1;
	E1 -> Vertex = X;
	E1 -> Rank = 0;
	return E1;
}

Element* FindSet (Element* A)
{
	if (A -> Parent == A)
	{
		printf (" %d |", A -> Vertex);

		return A;
	}

	else
	{
		printf (" %d -> ", A -> Vertex);

		A -> Parent = FindSet(A -> Parent);
		return A -> Parent;
	}
}

void Link(Element* Parent1, Element* Parent2)
{
	if (Parent1 -> Rank > Parent2 -> Rank)
	{
		// Join to parent1.
		Parent2 -> Parent = Parent1;
	}

	else if (Parent1 -> Rank < Parent2 -> Rank)
	{
		// Join to parent2.
		Parent1 -> Parent = Parent2;
	}

	else
	{
		Parent2 -> Parent = Parent1;
		Parent1 -> Rank += 1;
	}
}

void Union(Element *A, Element* B)
{
	Element* Aparent = FindSet(A);
	Element* Bparent = FindSet(B);

	if (Aparent != Bparent)
	{
		Link (Aparent, Bparent);
		printf ("\n\tUnion done!\n");
	}
	else
		fprintf (stderr, "\n\tSame parent cant do union!\n");

}

int main ()
{
	// Menu Driven Program.
	Element *Data[100], *RootNode;
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
