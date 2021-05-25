#include "disjointSet.h"
#include <iostream>
using namespace std;

DisjointSet::DisjointSet(int n)
{
    set = new SetNode[n];
    setSize = n;
}

DisjointSet::~DisjointSet()
{
    delete[] set;
}

void DisjointSet::makeSet(int vertex)
{
    set[vertex].up = vertex;
    set[vertex].rank = 0;
}

int DisjointSet::findSet(int vertex)
{
    if (set[vertex].up != vertex)
        set[vertex].up = findSet(set[vertex].up);
    return set[vertex].up;
}

void DisjointSet::unionSets(Edge edge)
{
    int u, v;

    u = findSet(edge.vert1); // Find representant of vert1
    v = findSet(edge.vert2); // Find represetnant of vert2

    if (u != v)
    {
        if (set[u].rank > set[v].rank) // Compare ranks of both sets
            set[v].up = u;             // If u rank is greater, union v
        else
        {
            set[u].up = v; // Else union u
            if (set[u].rank == set[v].rank)
                set[v].rank++;
        }
    }
}

bool DisjointSet::isAllOneSet()
{
    int mainParent = this->set[0].up;
    int i;

    for (i = 1; i < this->setSize; i++)
        if (mainParent != this->set[i].up)
            return false;

    return true;
}
