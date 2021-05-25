void fillGraphWithRandomData(Graph *&graph, int vertices, int density)
{
    int edges = (int)((float)(((density / 100) * vertices * (vertices - 1)) / 2));
    DisjointSet set(vertices);
    Edge edge;
    int starting, ending, numberOfAddedEdges = 0;
    srand(time(NULL));

    graph->createMatrix(vertices);

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

        edge.vert1 = starting;
        edge.vert2 = ending;
        edge.weight = rand() % (edges + 50) + 1;
        graph->addEdge(edge.vert1, edge.vert2, edge.weight);

        numberOfAddedEdges++;
        set.unionSets(edge);
    }

    while (numberOfAddedEdges < edges)
    {
        do
        {
            starting = rand() % vertices;
            ending = rand() % vertices;
        } while (starting == ending || graph->checkEdge(starting, ending));

        edge.vert1 = starting;
        edge.vert2 = ending;
        edge.weight = rand() % (edges + 50) + 1;
        graph->addEdge(edge.vert1, edge.vert2, edge.weight);
        numberOfAddedEdges++;
    }
}