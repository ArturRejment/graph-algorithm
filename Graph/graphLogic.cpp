void fillGraphWithRandomData(Graph &graph, Graph &undirectedGraph, int vertices, float density)
{
    int edges = ((float)(((density / 100) * vertices * (vertices - 1)) / 2));
    cout << "Verice: " << vertices << "\nDensity: " << density;
    cout << "\nEDGES: " << edges << endl;
    DisjointSet set(vertices);
    Edge edge;
    int starting, ending, numberOfAddedEdges = 0;
    srand(time(NULL));

    graph.createMatrix(vertices);
    undirectedGraph.createMatrix(vertices);

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
        graph.addEdge(edge.vert1, edge.vert2, edge.weight);
        undirectedGraph.addEdge(edge.vert1, edge.vert2, edge.weight);

        numberOfAddedEdges++;
        set.unionSets(edge);
    }

    while (numberOfAddedEdges < edges)
    {
        cout << "No przeca tu jestem no\n";
        do
        {
            starting = rand() % vertices;
            ending = rand() % vertices;
        } while (starting == ending || graph.checkEdge(starting, ending));

        edge.vert1 = starting;
        edge.vert2 = ending;
        edge.weight = rand() % (edges + 50) + 1;
        graph.addEdge(edge.vert1, edge.vert2, edge.weight);
        undirectedGraph.addEdge(edge.vert1, edge.vert2, edge.weight);
        numberOfAddedEdges++;
    }
}

void deleteGraph(DirectedGraph **graph1, UndirectedGraph **graph2)
{
    if ((*graph1)->getVertices() == 0 || (*graph2)->getVertices() == 0)
    {
        cout << "One of the graphs is aleredy empty!\n";
        return;
    }

    delete *graph1;
    *graph1 = new DirectedGraph();

    delete *graph2;
    *graph2 = new UndirectedGraph();
    cout << "Graphs deleted successfully!\n";
}