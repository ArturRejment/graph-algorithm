void primAlgoMatrix(Graph &graph, bool isTest=false)
{
    int i, j, vertex;
    int n = graph.getVertices();
    int m = graph.getEdges();
    int **matrix = graph.getMatrix();
    Edge edge;
    ListElement *node;

    Queue queue(m);
    UndirectedGraph *mst = new UndirectedGraph();
    mst->createMatrix(n);

    bool *visited = new bool[n];

    for (i = 0; i < n; i++)
        visited[i] = false;

    vertex = 0;
    visited[vertex] = true;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            if (matrix[vertex][j] > 0 && !visited[graph.getEndingVertex(j, vertex)])
            {
                edge.vert1 = vertex;
                edge.vert2 = graph.getEndingVertex(j, vertex);
                edge.weight = matrix[vertex][j];
                queue.push(edge);
            }
        }

        do
        {
            edge = queue.front();
            queue.pop();
        } while (visited[edge.vert2]);

        mst->addEdge(edge.vert1, edge.vert2, edge.weight);
        visited[edge.vert2] = true;
        vertex = edge.vert2;
    }
    if(isTest) mst->printMatrix();
    delete[] visited;
}

void primAlgoList(Graph &graph, bool isTest=false)
{
    int i, j, vertex;
    int n = graph.getVertices();
    int m = graph.getEdges();
    ListElement **neighbourhoodList = graph.getList();
    Edge edge;
    ListElement *temp;

    Queue queue(2 * m);
    UndirectedGraph *mst = new UndirectedGraph();
    mst->createMatrix(n);
    bool *visited = new bool[n];

    for (i = 0; i < n; i++)
        visited[i] = false;

    vertex = 0;
    visited[vertex] = true;

    for (i = 1; i < n; i++)
    {
        temp = neighbourhoodList[vertex];
        while (temp)
        {
            if (!visited[temp->vertex])
            {
                edge.vert1 = vertex;
                edge.vert2 = temp->vertex;
                edge.weight = temp->weight;
                queue.push(edge);
            }
            temp = temp->next;
        }

        do
        {
            edge = queue.front();
            queue.pop();
        } while (visited[edge.vert2]);

        mst->addEdge(edge.vert1, edge.vert2, edge.weight);
        visited[edge.vert2] = true;
        vertex = edge.vert2;
    }

    if(isTest) mst->printList();
    delete[] visited;
}