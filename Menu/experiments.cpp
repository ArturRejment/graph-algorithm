float NANOSEC = 1000000.0f;

void dikstraExperiment(DirectedGraph **directedGraph, UndirectedGraph **undirectedGraph)
{
    float matrixTime = 0, listTime = 0;
    int numberOfVerice, numberOfTests;
    float density;

    cout << "Enter number of verice for the graph: " << flush;
    cin >> numberOfVerice;

    cout << "Enter the density of the graph: " << flush;
    cin >> density;

    cout << "Enter number of tests to perform: " << flush;
    cin >> numberOfTests;

    int counter = 0;
    for (counter; counter < numberOfTests; counter++)
    {
        fillGraphWithRandomData(directedGraph, undirectedGraph, numberOfVerice, density);

        Timer timerMatrix;
        dijkstraAlgoMatrix(**directedGraph, 0);
        matrixTime += timerMatrix.getTime().count() * NANOSEC;

        Timer timerList;
        dijkstraAlgoList(**directedGraph, 0);
        listTime += timerList.getTime().count() * NANOSEC;

        deleteUndirectedGraph(undirectedGraph);
        deleteDirectedGraph(directedGraph);
    }
    cout << "Dikstra's algorithm for incidence matrix took on average: " << matrixTime / numberOfTests << "ms\n";
    cout << "Dikstra's algorithm for list took on average: " << listTime / numberOfTests << "ms\n";
}


void bellmanFordExperiment(DirectedGraph **directedGraph, UndirectedGraph **undirectedGraph)
{
    float matrixTime = 0, listTime = 0;
    int numberOfVerice, numberOfTests;
    float density;

    cout << "Enter number of verice for the graph: " << flush;
    cin >> numberOfVerice;

    cout << "Enter the density of the graph: " << flush;
    cin >> density;

    cout << "Enter number of tests to perform: " << flush;
    cin >> numberOfTests;

    int counter = 0;
    for (counter; counter < numberOfTests; counter++)
    {
        fillGraphWithRandomData(directedGraph, undirectedGraph, numberOfVerice, density);

        Timer timerMatrix;
        bellmanFord(**directedGraph, 0, false);
        matrixTime += timerMatrix.getTime().count() * NANOSEC;

        Timer timerList;
        bellmanFord(**directedGraph, 0, true);
        listTime += timerList.getTime().count() * NANOSEC;

        deleteUndirectedGraph(undirectedGraph);
        deleteDirectedGraph(directedGraph);
    }
    cout << "Bellman-Ford's algorithm for incidence matrix took on average: " << matrixTime / numberOfTests << "ms\n";
    cout << "Bellman-Ford's algorithm for list took on average: " << listTime / numberOfTests << "ms\n";
}



void PrimExperiment(DirectedGraph **directedGraph, UndirectedGraph **undirectedGraph)
{
    float matrixTime = 0, listTime = 0;
    int numberOfVerice, numberOfTests;
    float density;

    cout << "Enter number of verice for the graph: " << flush;
    cin >> numberOfVerice;

    cout << "Enter the density of the graph: " << flush;
    cin >> density;

    cout << "Enter number of tests to perform: " << flush;
    cin >> numberOfTests;

    int counter = 0;
    for (counter; counter < numberOfTests; counter++)
    {
        fillGraphWithRandomData(directedGraph, undirectedGraph, numberOfVerice, density);

        Timer timerMatrix;
        primAlgoMatrix(**undirectedGraph);
        matrixTime += timerMatrix.getTime().count() * NANOSEC;

        Timer timerList;
        primAlgoList(**undirectedGraph);
        listTime += timerList.getTime().count() * NANOSEC;

        deleteUndirectedGraph(undirectedGraph);
        deleteDirectedGraph(directedGraph);
    }
    cout << "Prim's algorithm for incidence matrix took on average: " << matrixTime / numberOfTests << "ms\n";
    cout << "Prim's algorithm for list took on average: " << listTime / numberOfTests << "ms\n";
}


void KruskalExperiment(DirectedGraph **directedGraph, UndirectedGraph **undirectedGraph)
{
    float matrixTime = 0, listTime = 0;
    int numberOfVerice, numberOfTests;
    float density;

    cout << "Enter number of verice for the graph: " << flush;
    cin >> numberOfVerice;

    cout << "Enter the density of the graph: " << flush;
    cin >> density;

    cout << "Enter number of tests to perform: " << flush;
    cin >> numberOfTests;

    int counter = 0;
    for (counter; counter < numberOfTests; counter++)
    {
        fillGraphWithRandomData(directedGraph, undirectedGraph, numberOfVerice, density);

        Timer timerMatrix;
        kruskalAlgoMatrix(**undirectedGraph);
        matrixTime += timerMatrix.getTime().count() * NANOSEC;

        Timer timerList;
        kruskalAlgoList(**undirectedGraph);
        listTime += timerList.getTime().count() * NANOSEC;
        
        deleteUndirectedGraph(undirectedGraph);
        deleteDirectedGraph(directedGraph);
    }
    cout << "Kruskal's algorithm for incidence matrix took on average: " << matrixTime / numberOfTests << "ms\n";
    cout << "Kruskal's algorithm for list took on average: " << listTime / numberOfTests << "ms\n";
}