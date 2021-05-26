#include "directedGraph.h"

void DirectedGraph::addEdge(int vertex1, int vertex2, int weight)
{
    // Add Edge to the neighbourhood list
    ListElement *temp;
    temp = new ListElement;
    temp->vertex = vertex2;
    temp->weight = weight;
    temp->next = list[vertex1];
    list[vertex1] = temp;

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