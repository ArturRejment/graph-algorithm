int m, n;
ListElement **neighbourhoodList;
int **matrix;
long long *weightTable;
int *successorsList;

// Fuction is appointing shortest paths
bool shortestPathList(int vertex)
{
    int i, temp;
    bool test;
    ListElement *pv;

    weightTable[vertex] = 0; // Set the weight of path to v on 0
    for (i = 1; i < n; i++)
    {
        test = true;
        for (temp = 0; temp < n; temp++)
        {
            for (pv = neighbourhoodList[temp]; pv; pv = pv->next)
            {
                if (weightTable[pv->vertex] > weightTable[temp] + pv->weight)
                {
                    test = false;
                    weightTable[pv->vertex] = weightTable[temp] + pv->weight;
                    successorsList[pv->vertex] = temp;
                }
            }
        }
        if (test)
            return true; // If there was no changes, finish function
    }

    // Check if there is a negative cycle
    for (temp = 0; temp < n; temp++)
        for (pv = neighbourhoodList[temp]; pv; pv = pv->next)
            if (weightTable[pv->vertex] > weightTable[temp] + pv->weight)
                return false; // There is a negative cycle!

    return true;
}

bool shortestPathMatrix(int vertex)
{
    int i, temp, j;
    bool test;
    ListElement *pv;

    weightTable[vertex] = 0; // Set the weight of path to v on 0
    for (i = 1; i < n; i++)
    {
        test = true;
        for (temp = 0; temp < n; temp++)
        {
            for (j = 0; j < n; j++)
            {
                if (weightTable[j] > weightTable[temp] + matrix[temp][j] && matrix[temp][j] != 0)
                {
                    test = false;
                    weightTable[j] = weightTable[temp] + matrix[temp][j];
                    successorsList[j] = temp;
                }
            }
        }
        if (test)
            return true; // If there was no changes, finish function
    }

    for (temp = 0; temp < n; temp++)
        for (j = 0; j < n; j++)
            if (weightTable[j] > weightTable[temp] + matrix[temp][j])
                return false; // There is a negative cycle!

    return true;
}

void bellmanFord(Graph *&graph, int startingVertex, bool isList)
{
    // Useful variables
    n = graph->getVertices();
    m = graph->getEdges();
    neighbourhoodList = graph->getList();
    matrix = graph->getMatrix();

    // Required arrays
    weightTable = new long long[n];
    successorsList = new int[n];
    bool *isVisited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        weightTable[i] = MAXVALUE;
        successorsList[i] = -1;
        isVisited[i] = false;
    }

    weightTable[startingVertex] = 0;

    if (isList ? shortestPathList(startingVertex) : shortestPathMatrix(startingVertex))
    {
        int *S = new int[n]; // Make a simple stack
        int stackPtr = 0;

        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            for (int temp = i; temp != -1; temp = successorsList[temp])
                S[stackPtr++] = temp;

            while (stackPtr)
                cout << S[--stackPtr] << " ";

            cout << "$" << weightTable[i] << endl;
        }
        delete[] S;
    }
    else
    {
        cout << "Negative Cycle found!" << endl;
    }
}