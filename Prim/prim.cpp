void primAlgoMatrix (Graph *&graph)
{
    int i, j, vertex;
    int n = graph->getVertices();
    int m = graph->getEdges();
    int **matrix = graph->getMatrix();
    Edge edge;
    TreeNode *node;

    Queue queue(m);
    MST mst(n);
    MST graph_s(n);
    bool *visited = new bool[n];

    for (i = 0; i < n; i++)
        visited[i] = false;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(matrix[i][j] != 0)
            {
                edge.vert1 = i;
                edge.vert2 = j;
                edge.weight = matrix[i][j];
                graph_s.addEdge(edge);
            }

        }
    }

    vertex = 0;
    visited[vertex] = true;

    for (i = 1; i < n; i++)
    {
        for (node = graph_s.getNeighList(vertex); node; node = node->next)
        {
            if(!visited[node->vertex])
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

        mst.addEdge(edge);
        visited[edge.vert2] = true;
        vertex = edge.vert2;
    }

    mst.printMST();
}


void primAlgoList (Graph *&graph)
{
    int i, j, vertex;
    int n = graph->getVertices();
    int m = graph->getEdges();
    ListElement **neighbourhoodList = graph->getList();
    Edge edge;
    TreeNode *node;
    ListElement *temp;

    Queue queue(m);
    MST mst(n);
    MST graph_s(n);
    bool *visited = new bool[n];

    for (i = 0; i < n; i++)
        visited[i] = false;

    for (i = 0; i < n; i++)
    {
        temp = neighbourhoodList[i];
        while(temp)
        {
            edge.vert1 = i;
            edge.vert2 = temp->vertex;
            edge.weight = temp->weight;
            graph_s.addEdge(edge);
            temp = temp->next;
        }
    }
    

    vertex = 0;
    visited[vertex] = true;

    for (i = 1; i < n; i++)
    {
        for (node = graph_s.getNeighList(vertex); node; node = node->next)
        {
            if(!visited[node->vertex])
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

        mst.addEdge(edge);
        visited[edge.vert2] = true;
        vertex = edge.vert2;
    }

    mst.printMST();
}