
int HeapSize = 0;

int Root(int Child)
{
    return (Child - 1) / 2;
}

int LeftChild(int Parent)
{
    return Parent * 2 + 1;
}

int RightChild(int Parent)
{
    return Parent * 2 + 2;
}

void MinHeapify(Vertex** Q, int Root)
{
    int Smallest = Root;
    int Left = LeftChild(Root);
    int Right = RightChild(Root);

    if ((Left < HeapSize) && (Q[Left] -> D < Q[Smallest] -> D))
        Smallest = Left;

    if ((Right < HeapSize) && (Q[Right] -> D < Q[Smallest] -> D))
        Smallest = Right;

    if (Smallest != Root)
    {
        // Swap Smallest and Root.
        Vertex* Temp = Q[Smallest];
        Q[Smallest] = Q[Root];
        Q[Root] = Temp;
        MinHeapify (Q, Smallest);
    }

}

int GraphBuildHeap(Vertex** Q)
{
    int i = Root(HeapSize);
    while (i >= 0)
    {
        MinHeapify(Q, i);
        i--;
    }

    return 0;
}

int IsEmptyHeap ()
{
    if (HeapSize  <= 0)
        return 1;
    return 0;
}

Vertex* GraphExtractMin (Vertex** Q)
{
    // Swap with last vertex and call heapify.
    if (HeapSize > 0)
    {
        Vertex* TempV = Q[0];
        Q[0] = Q[HeapSize - 1];
        Q[HeapSize - 1] = TempV;
        HeapSize--;
        return TempV;
    }

    return NULL;
}

Vertex** GraphInitializeHeap (Graph *G)
{
    int i;
    Vertex **Q = malloc (sizeof (Vertex *) * G -> NoOfV);
    for (i = 0; i < G -> NoOfV; i++)
    {
        Q[i] = G -> V[i];
    }

    HeapSize = G -> NoOfV;
    GraphBuildHeap (Q);
    return Q;
}
