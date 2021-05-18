const int MAXVALUE = 2147483647; // Const represents infinity
using namespace std;

void dijkstraAlgoList(Graph *&graph, int startingVertex)
{
    // Useful variables
    int n = graph->getVertices();
    int m = graph->getEdges();
    ListElement **neighbourhoodList = graph->getList();

    // Required arrays
    int *weightTable = new int[n];
    int *successorsList = new int[n];
    bool *isVisited = new bool[n];

    // Arrays initiation
    for (int i = 0; i < n; i++)
    {
        weightTable[i] = MAXVALUE;
        successorsList[i] = -1;
        isVisited[i] = false;
    }

    weightTable[startingVertex] = 0; // Weight of the route to the starting vertex is 0

    int i, j, minWeightPosition;
    ListElement *temp;
    // Find the route
    for (i = 0; i < n; i++)
    {
        // Find unvisited vertex with the lowest wage
        for (j = 0; isVisited[j]; j++)
            ;
        for (minWeightPosition = j++; j < n; j++)
            if (!isVisited[j] && (weightTable[j] < weightTable[minWeightPosition]))
                minWeightPosition = j;

        // Mark this vertex as visited
        isVisited[minWeightPosition] = true;

        // Modify all the minWeightPosition neighours that are not visited
        for (temp = neighbourhoodList[minWeightPosition]; temp; temp = temp->next)
        {
            if (!isVisited[temp->vertex] && (weightTable[temp->vertex] > weightTable[minWeightPosition] + temp->weight))
            {
                weightTable[temp->vertex] = weightTable[minWeightPosition] + temp->weight;
                successorsList[temp->vertex] = minWeightPosition;
            }
        }
    }

    cout << "\n";
    cout << "Shortest routes: \n";
    for (i = 0; i < n; i++)
    {
        cout << i << ": " << weightTable[i] << "\n";
    }
}

void dijkstraAlgoMatrix(Graph *&graph, int startingVertex)
{
    // Useful variables
    int n = graph->getVertices();
    int m = graph->getEdges();
    int **matrix = graph->getMatrix();

    // Required arrays
    int *weightTable = new int[n];
    int *successorsList = new int[n];
    bool *isVisited = new bool[n];

    // Arrays initiation
    for (int i = 0; i < n; i++)
    {
        weightTable[i] = MAXVALUE;
        successorsList[i] = -1;
        isVisited[i] = false;
    }

    weightTable[startingVertex] = 0; // Weight of the route to the starting vertex is 0

    int i, j, minWeightPosition;

    // Find the route
    for (i = 0; i < n; i++)
    {
        // Find unvisited vertex with the lowest wage
        for (j = 0; isVisited[j]; j++)
            ;
        for (minWeightPosition = j++; j < n; j++)
            if (!isVisited[j] && (weightTable[j] < weightTable[minWeightPosition]))
                minWeightPosition = j;

        // Mark this vertex as visited
        isVisited[minWeightPosition] = true;

        // Modify all the minWeightPosition neighours that are not visited
        for (int j = 0; j < m; j++)
        {
            if (matrix[minWeightPosition][j] > 0 && !isVisited[graph->getEndingVertex(j)] && weightTable[graph->getEndingVertex(j)] > weightTable[minWeightPosition] + matrix[minWeightPosition][j])
            {
                weightTable[graph->getEndingVertex(j)] = weightTable[minWeightPosition] + matrix[minWeightPosition][j];
                successorsList[graph->getEndingVertex(j)] = minWeightPosition;
            }
        }
    }

    cout << "\n";
    cout << "Shortest routes: \n";
    for (i = 0; i < n; i++)
    {
        cout << i << ": " << weightTable[i] << "\n";
    }
}