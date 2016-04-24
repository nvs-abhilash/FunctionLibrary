#include <stdio.h>

int Front = -1, Rear = -1, MaxSize = 0;

void InitializeQ (int Max)
{
	Front = -1;
	Rear = -1;
	MaxSize = Max;
}

int IsEmptyQ ()
{
	if (Front == -1)
		return 1;
	return 0;
}

int IsFullQ ()
{
	if (Front == (Rear + 1) % MaxSize)
		return 1;
	return 0;
}

void Enqueue (Vertex **Q, Vertex *V)
{
	if (Q == NULL)
	{
		fprintf (stderr, "\nNULL Queue was passed.");
		return;
	}

	if (Front == -1)
	{
		Front += 1;
	}

	else if ((Rear + 1) % MaxSize == Front)
	{
		// Full
		fprintf (stderr, "\nQueue space cannot exceed than number of vertices!.");
		return;
	}

	Rear = (Rear + 1) % MaxSize;
	Q[Rear] = V;
}

Vertex* Dequeue (Vertex** Q)
{
	int Temp;

	if (Front == -1)
		return NULL;
	if (Front == Rear)
	{
		Front = -1;
		Temp = Rear;
		Rear = -1;
		return Q[Temp];
	}
	Temp = Front;
    Front = (Front + 1) % MaxSize;
	return Q[Temp];
}
