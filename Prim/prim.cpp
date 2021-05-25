void primAlgoMatrix(Graph *&graph)
{
    int i, j, vertex;
    int n = graph->getVertices();
    int m = graph->getEdges();
    int **matrix = graph->getMatrix();
    Edge edge;
    ListElement *node;

    Queue queue(m);
    Graph mst;
    Graph graph_s;
    bool *visited = new bool[n];

    for (i = 0; i < n; i++)
        visited[i] = false;

    vertex = 0;
    visited[vertex] = true;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            if (matrix[vertex][j] < 0)
            {
                edge.vert1 = vertex;
                edge.vert2 = graph->getStartingVertex(j);
                edge.weight = -matrix[vertex][j];
                queue.push(edge);
            }
            else if (matrix[vertex][j] > 0)
            {
                edge.vert1 = vertex;
                edge.vert2 = graph->getEndingVertex(j);
                edge.weight = matrix[vertex][j];
                queue.push(edge);
            }
        }

        do
        {
            edge = queue.front();
            queue.pop();
        } while (visited[edge.vert2]);

        mst.addEdge(edge.vert1, edge.vert2, edge.weight);
        visited[edge.vert2] = true;
        vertex = edge.vert2;
    }
}

void primAlgoList(Graph *&graph)
{
    int i, j, vertex;
    int n = graph->getVertices();
    int m = graph->getEdges();
    ListElement **neighbourhoodList = graph->getList();
    Edge edge;
    ListElement *node;
    ListElement *temp;

    Queue queue(m);
    Graph mst;
    Graph graph_s;
    bool *visited = new bool[n];

    for (i = 0; i < n; i++)
        visited[i] = false;

    for (i = 0; i < n; i++)
    {
        temp = neighbourhoodList[i];
        while (temp)
        {
            edge.vert1 = i;
            edge.vert2 = temp->vertex;
            edge.weight = temp->weight;
            graph_s.addEdge(edge.vert1, edge.vert2, edge.vert2);
            temp = temp->next;
        }
    }

    vertex = 0;
    visited[vertex] = true;

    for (i = 1; i < n; i++)
    {
        for (node = *graph_s.getList(); node; node = node->next)
        {
            if (!visited[node->vertex])
            {
                edge.vert1 = vertex;
                edge.vert2 = node->vertex;
                edge.weight = node->weight;
                queue.push(edge);
            }
        }

        do
        {
            edge = queue.front();
            queue.pop();
        } while (visited[edge.vert2]);

        cout << edge.vert1 << " " << edge.vert2 << " (" << edge.weight << ")\n";
        mst.addEdge(edge.vert1, edge.vert2, edge.weight);
        visited[edge.vert2] = true;
        vertex = edge.vert2;
        cout << "vertex: " << vertex << endl;
    }
}