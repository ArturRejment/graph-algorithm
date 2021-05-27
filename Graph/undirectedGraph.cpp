#include "undirectedGraph.h"

void UndirectedGraph::addEdge(int vertex1, int vertex2, int weight)
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
    this->matrix[vertex2][this->m] = weight;

    this->weight += weight;
    this->m += 1;
}

int UndirectedGraph::getEndingVertex(int edge, int startingVertex)
{
    if (edge > this->m - 1)
        return -1;

    for (int i = 0; i < this->n; i++)
    {
        if (i == startingVertex)
            continue;

        if (this->matrix[i][edge] > 0)
            return i;
    }
    return -1;
}