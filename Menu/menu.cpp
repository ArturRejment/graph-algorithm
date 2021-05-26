#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "../Queue/priorityQueue.cpp"
#include "../Graph/graphClass.cpp"
#include "../Graph/directedGraph.cpp"
// #include "../Graph/graphClass.cpp"
#include "../DisjointSet/disjointSet.cpp"
#include "../Dijkstra/dijkstra.cpp"
#include "../Bellman-ford/bellman-ford.cpp"
// #include "../Kruskal/kruskal.cpp"
// #include "../Prim/prim.cpp"
#include "../Graph/graphLogic.cpp"
using namespace std;

DirectedGraph *directedGraph = new DirectedGraph();

void testingMenu()
{
    int vert;
    int dens;
    char choice;
    do
    {
        cout << "------------TESTING MENU-------------\n";
        cout << "[1] Read data from file\n";
        cout << "[2] Generate random data\n";
        cout << "[3] Print graph\n";
        cout << "[4] Dijkstra Algorithm\n";
        cout << "[5] Bellman-Ford Algorithm\n";
        cout << "[6] Kruskal Algorithm\n";
        cout << "[7] Prim Algorithm\n";
        cout << "[8] Exit\n";

        choice = getch();
        switch (choice)
        {
        case '1':
            system("cls");
            directedGraph->importGraphFromFile();
            break;
        case '2':
            system("cls");
            cout << "Enter the number of verice: ";
            cin >> vert;
            cout << "Enter the dencity of graph: ";
            cin >> dens;
            fillGraphWithRandomData(*directedGraph, vert, dens);
            break;
        case '3':
            system("cls");
            directedGraph->printGraph();
            break;
        case '4':
            system("cls");
            cout << "Enter the starting vertex: ";
            cin >> vert;
            dijkstraAlgoList(*directedGraph, vert);
            dijkstraAlgoMatrix(*directedGraph, vert);
            break;
        case '5':
            system("cls");
            cout << "Enter the starting vertex: ";
            cin >> vert;
            bellmanFord(*directedGraph, vert, true);  // Bellman-ford using neighbor List
            bellmanFord(*directedGraph, vert, false); // Bellman-ford using matrix
            break;
            // case '6':
            //     system("cls");
            //     kruskalAlgoList(graph);
            //     kruskalAlgoMatrix(graph);
            //     break;
            // case '7':
            //     system("cls");
            //     primAlgoList(graph);
            //     primAlgoMatrix(graph);
            break;
        case '8':
            return;

        default:
            break;
        }
    } while (true);
}

void selectMode()
{
    char choice;
    do
    {
        system("cls");
        cout << "---------------START-----------------\n";
        cout << "[1] Experiment mode\n";
        cout << "[2] Testing mode\n";
        cout << "[3] Exit program\n";
        cout << "Press key with your choice\n";

        choice = getch();
        switch (choice)
        {
        case '1':
            break;
        case '2':
            system("cls");
            testingMenu();
            break;
        case '3':
            return;
        default:
            break;
        }
    } while (true);
}