void deleteDirectedGraph(DirectedGraph **graph1)
{
    if ((*graph1)->getVertices() == 0)
    {
        cout << "Graph is aleredy empty!\n";
        return;
    }

    delete *graph1;
    *graph1 = new DirectedGraph();
}

void deleteUndirectedGraph(UndirectedGraph **graph1)
{
    if ((*graph1)->getVertices() == 0)
    {
        cout << "Graph is aleredy empty!\n";
        return;
    }

    delete *graph1;
    *graph1 = new UndirectedGraph();
}

void fillGraphWithRandomData(DirectedGraph **directedGraph, UndirectedGraph **undirectedGraph, int vertices, float density)
{
    if((*directedGraph)->getVertices() != 0 || (*undirectedGraph)->getVertices() != 0)
    {
        deleteDirectedGraph(directedGraph);
        deleteUndirectedGraph(undirectedGraph);
    }
    int edges = ((float)(((density / 100) * vertices * (vertices - 1)) / 2));
    DisjointSet set(vertices);
    Edge edge;
    int starting, ending, numberOfAddedEdges = 0;
    srand(time(NULL));

    (*directedGraph)->createMatrix(vertices);
    (*undirectedGraph)->createMatrix(vertices);

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
        (*directedGraph)->addEdge(edge.vert1, edge.vert2, edge.weight);
        (*undirectedGraph)->addEdge(edge.vert1, edge.vert2, edge.weight);

        numberOfAddedEdges++;
        set.unionSets(edge);
    }

    while (numberOfAddedEdges < edges)
    {
        do
        {
            starting = rand() % vertices;
            ending = rand() % vertices;
        } while (starting == ending || (*undirectedGraph)->checkEdge(starting, ending));

        edge.vert1 = starting;
        edge.vert2 = ending;
        edge.weight = rand() % (edges + 50) + 1;
        (*directedGraph)->addEdge(edge.vert1, edge.vert2, edge.weight);
        (*undirectedGraph)->addEdge(edge.vert1, edge.vert2, edge.weight);
        numberOfAddedEdges++;
    }
}

