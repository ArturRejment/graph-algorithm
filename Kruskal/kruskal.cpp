void kruskalAlgoMatrix(Graph &graph, bool isTest=false)
{
    // Useful variables
    int i;
    int n = graph.getVertices();
    int m = graph.getEdges();
    int **matrix = graph.getMatrix();
    Edge edge;

    DisjointSet set(n); // Disjoint sets structure
    Queue queue(2 * m); // Priority queue
    UndirectedGraph *mst = new UndirectedGraph();
    mst->createMatrix(n);

    for (i = 0; i < n; i++)
        set.makeSet(i); // Make set for every vertex

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] > 0)
            {
                edge.vert1 = i;
                edge.vert2 = graph.getEndingVertex(j, i);
                edge.weight = matrix[i][j];
                queue.push(edge);
            }
        }
    }

    for (i = 1; i < n; i++)
    {
        do
        {
            edge = queue.front();
            queue.pop();
        } while (set.findSet(edge.vert1) == set.findSet(edge.vert2));
        mst->addEdge(edge.vert1, edge.vert2, edge.weight);
        set.unionSets(edge);
    }
    if(isTest) mst->printMatrix();
}

void kruskalAlgoList(UndirectedGraph &graph, bool isTest=false)
{
    // Useful variables
    int i;
    int n = graph.getVertices();
    int m = graph.getEdges();
    ListElement **neighbourhoodList = graph.getList();
    ListElement *temp;
    Edge edge;

    DisjointSet set(n); // Disjoint sets structure
    Queue queue(2 * m); // Priority queue
    UndirectedGraph *mst = new UndirectedGraph();
    mst->createMatrix(n);

    for (i = 0; i < n; i++)
        set.makeSet(i); // Make set for every vertex

    for (i = 0; i < n; i++)
    {
        temp = neighbourhoodList[i];
        while (temp)
        {
            edge.vert1 = i;
            edge.vert2 = temp->vertex;
            edge.weight = temp->weight;
            queue.push(edge);
            temp = temp->next;
        }
    }

    for (i = 1; i < n; i++)
    {
        do
        {
            edge = queue.front();
            queue.pop();
        } while (set.findSet(edge.vert1) == set.findSet(edge.vert2));
        mst->addEdge(edge.vert1, edge.vert2, edge.weight);
        set.unionSets(edge);
    }

    if (isTest) mst->printList();
}