void kruskalAlgoMatrix(Graph *&graph)
{
    // Useful variables
    int i;
    int n = graph->getVertices();
    int m = graph->getEdges();
    int **matrix = graph->getMatrix();
    Edge edge;

    DisjointSet set(n); // Disjoint sets structure
    Queue queue(m);     // Priority queue
    Graph mst;

    for (i = 0; i < n; i++)
        set.makeSet(i); // Make set for every vertex

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                edge.vert1 = i;
                edge.vert2 = j;
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
        mst.addEdge(edge.vert1, edge.vert2, edge.weight);
        set.unionSets(edge);
    }
}

void kruskalAlgoList(Graph *&graph)
{
    // Useful variables
    int i;
    int n = graph->getVertices();
    int m = graph->getEdges();
    ListElement **neighbourhoodList = graph->getList();
    ListElement *temp;
    Edge edge;

    DisjointSet set(n); // Disjoint sets structure
    Queue queue(m);     // Priority queue
    Graph mst;

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
        mst.addEdge(edge.vert1, edge.vert2, edge.vert2);
        set.unionSets(edge);
    }
}