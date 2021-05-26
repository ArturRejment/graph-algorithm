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
    this->weight = 0;
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

void Graph::createMatrix(int verice)
{
    this->list = new ListElement *[verice];
    this->matrix = new int *[verice];
    this->n = verice;

    for (int i = 0; i < verice; i++)
    {
        this->matrix[i] = new int[0];
        this->list[i] = nullptr;
    }
}

bool Graph::checkEdge(int vert1, int vert2)
{
    for (int i = 0; i < m; i++)
        if (matrix[vert1][i] > 0 && matrix[vert2][i] != 0)
            return true; // Edge already exists

    return false; // There is no edge (vert1, vert2) in the graph
}

void Graph::addEdge(int vertex1, int vertex2, int weight)
{
    // Add Edge to the neighbourhood list
    ListElement *temp;
    temp = new ListElement;
    temp->vertex = vertex2;
    temp->weight = weight;
    temp->next = list[vertex1];
    list[vertex1] = temp;

    ListElement *temp2;
    temp2 = new ListElement;
    temp2->vertex = vertex1;
    temp2->weight = weight;
    temp2->next = list[vertex2];
    list[vertex2] = temp2;

    // Add edge to the matrix
    for (int i = 0; i < this->n; i++)
    {
        this->matrix[i] = (int *)realloc(this->matrix[i], (this->m + 1) * sizeof(int));
        this->matrix[i][this->m] = 0;
    }

    this->matrix[vertex1][this->m] = weight;
    this->matrix[vertex2][this->m] = -1 * weight;

    this->weight += weight;
    this->m += 1;
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
    cout << "\nWeight of the tree: " << this->weight << "\n\n";
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
    cout << "\nWeight of the tree: " << this->weight << "\n\n";
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
    int vert, edges;
    file >> vert >> edges; // Get number of vertice and edges

    this->createMatrix(vert);

    // Read consecutive edges
    while (!file.eof())
    {
        file >> vert1 >> vert2 >> weight; // Read starting vertex, ending vertex and weight of the edge
        cout << vert1 << " " << vert2 << " " << weight << endl;

        this->addEdge(vert1, vert2, weight);
        cout << "Added" << endl;
    }
    cout << "Structure filled with success!\n";

    file.close();
}
