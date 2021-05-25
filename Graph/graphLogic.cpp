void fillGraphWithRandomData(int vertices, int density)
{
    int edges = (int)((float)(((density / 100) * vertices * (vertices - 1)) / 2));
    DisjointSet set(vertices);
    Edge edge;
    int starting, ending;
    srand(time(NULL));

    for (int i = 0; i < vertices; i++)
        set.makeSet(i);

    while (!set.isAllOneSet())
    {
        // Generate starting and ending vertex as long, as they values are the same
        // and they belongs to the same sets
        do
        {
            starting = rand() % vertices;
            ending = rand() % vertices;
        } while ((starting == ending) || (set.findSet(starting) == set.findSet(ending)));

        edge.weight = rand() % (edges + 50) + 1;
    }
}