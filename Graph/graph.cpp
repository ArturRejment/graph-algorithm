#include <fstream>
#include <iostream>
#include <iomanip>
#include "graph.h"
using namespace std;

Graph::Graph()
{
    this->n = 0;
    this->m = 0;
    this->matrix = nullptr;
    this->list = nullptr;
}

Graph::~Graph()
{
    int i;
    ListElement *temp, *temp2;
    for (i = 0; i < n; i++)
    {
        delete[] matrix[i];

        temp2 = list[i];
        while (temp2)
        {
            temp = temp2;
            temp2 = temp2->next;
            delete temp;
        }
    }
    delete[] matrix;
    delete[] list;
}

int Graph::getVertices()
{
    return n;
}

int Graph::getEdges()
{
    return m;
}

int **Graph::getMatrix()
{
    return matrix;
}

ListElement **Graph::getList()
{
    return list;
}

int Graph::getStartingVertex(int edge)
{
    if (edge > m - 1)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][edge] > 0)
        {
            return i;
        }
    }

    return -1;
}

int Graph::getEndingVertex(int edge)
{
    if (edge > m - 1)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][edge] < 0)
        {
            return i;
        }
    }
    return -1;
}

void Graph::printMatrix()
{
    int i, j;
    cout << "      |";
    for (i = 0; i < m; i++)
        cout << setw(6) << i;
    cout << "\n   ---|";
    for (int i = 0; i < m * 6 + 2; i++)
        cout << "-" << flush;
    cout << "\n";
    for (i = 0; i < n; i++)
    {
        cout << setw(6) << i << "|";
        for (j = 0; j < m; j++)
            cout << setw(6) << matrix[i][j];
        cout << "\n";
    }
    cout << "\n\n";
}

void Graph::printList()
{
    ListElement *temp;
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "     List [" << i << "]: ";
        temp = list[i];
        while (temp)
        {
            cout << setw(3) << temp->vertex << ":(" << temp->weight << "), ";
            temp = temp->next;
        }
        cout << "\n";
    }
    cout << "\n";
}

void Graph::printGraph()
{
    printMatrix();
    printList();
}

void Graph::importGraphFromFile()
{
    int i, j;
    int vert1, vert2, weight;
    fstream file;
    file.open("./data.txt", ios::in);

    if (matrix != nullptr)
    {
        cout << "[Graph] Graph is not empty!\n";
        return;
    }

    if (!file.is_open())
    {
        cout << "[Graph] Cannot open data.txt!\n";
        return;
    }
    file >> n >> m; // Get vertices and adges number

    matrix = new int *[n];       // Create array of pointers for the matrix
    list = new ListElement *[n]; // Create array of pointers for the list

    for (i = 0; i < n; i++)
    {
        matrix[i] = new int[m]; // Create rows
        list[i] = nullptr;
    }

    // Fill matrix with 0
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            matrix[i][j] = 0;

    ListElement *temp;
    // Read consecutive edges
    for (i = 0; i < m; i++)
    {
        file >> vert1 >> vert2 >> weight; // Read starting vertex, ending vertex and weight of the edge

        matrix[vert1][i] = weight;  // Starting vertex
        matrix[vert2][i] = -weight; // Ending vertex

        temp = new ListElement;
        temp->vertex = vert2;
        temp->weight = weight;
        temp->next = list[vert1];
        list[vert1] = temp;
    }
    cout << "Structure filled with success!\n";

    file.close();
}

void Graph::fillGraphWithRandomData(int vertices, int density)
{
    int edges = (int)((float)(((density / 100) * vertices * (vertices - 1)) / 2));
    DisjointSet set(vertices);
    Edge edge;
    int starting, ending;
    srand(time(NULL));

    for (int i = 0; i < vertices; i++)
        set.makeSet(i);

    while (!set.isAllOneSet())
    {
        // Generate starting and ending vertex as long, as they values are the same
        // and they belongs to the same sets
        do
        {
            starting = rand() % vertices;
            ending = rand() % vertices;
        } while ((starting == ending) || (set.findSet(starting) == set.findSet(ending)));
    }
}