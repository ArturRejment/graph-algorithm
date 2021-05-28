float NANOSEC = 1000000000.0f;

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
        
        deleteDirectedGraph(directedGraph);
    }
    cout << "Dikstra's algorithm for incidence matrix took on average: " << matrixTime / numberOfTests << "ns\n";
    cout << "Dikstra's algorithm for list took on average: " << listTime / numberOfTests << "ns\n";
}