#include "mst.h"
#include <iostream>
using namespace std;

DisjointSet::DisjointSet(int n)
{
    set = new SetNode[n];
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
    if(set[vertex].up != vertex)
        set[vertex].up = findSet(set[vertex].up);
    return set[vertex].up;
}

void DisjointSet::unionSets(Edge edge)
{
    int u, v;

    u = findSet(edge.vert1);    // Find representant of vert1
    v = findSet(edge.vert2);    // Find represetnant of vert2

    if(u != v)
    {
        if(set[u].rank > set[v].rank) // Compare ranks of both sets
            set[v].up = u;  // If u rank is greater, union v
        else
        {
            set[u].up = v;  // Else union u
            if(set[u].rank == set[v].rank)
                set[v].rank++;
        }
    }
}

//TODO: Kruskal algorithm 

MST::MST(int n)
{
    int i;
    neighbourhoodList = new TreeNode *[n];  // Dynamic array
    for (i = 0; i < n; i++)
        neighbourhoodList[i] = nullptr;
    listSize = n - 1;
    weight = 0;
}

MST::~MST()
{
    int i;
    TreeNode *neigh, *b;

    for (i = 0; i < listSize; i++)
    {
        neigh = neighbourhoodList[i];
        while(neigh)
        {
            b = neigh;
            neigh = neigh->next;
            delete b;
        }
    }
    delete[] neighbourhoodList;
}

TreeNode *MST::getNeighList(int n)
{
    return neighbourhoodList[n];
}

void MST::addEdge(Edge edge)
{
    TreeNode *neigh;

    weight += edge.weight;      // To the weight of tree add edge weight
    neigh = new TreeNode;       // Create new node
    neigh->vertex = edge.vert2;     // Ending node
    neigh->weight = edge.weight;    // Edge weight
    neigh->next = neighbourhoodList[edge.vert1]; // Add neigh to the list of vertex1
    neighbourhoodList[edge.vert1] = neigh;

    neigh = new TreeNode;   // Same action for second edge`
    neigh->vertex = edge.vert1; // Ending vertex
    neigh->weight = edge.weight; // Edge weight
    neigh->next = neighbourhoodList[edge.vert2]; // Add neigh to the list of vertex2
    neighbourhoodList[edge.vert2] = neigh;
}

void MST::printMST()
{
    int i;
    TreeNode *node;

    cout << "\n";
    for (i = 0; i < listSize; i++)
    {
        cout << "Vertex " << i << " - ";
        for (node = neighbourhoodList[i]; node; node = node->next)
            cout << node->vertex << ":" << node->weight << " ";
        cout << "\n";
    }
    cout << "\n\n"
         << "Minimal Spinning Tree Weight = " << weight << "\n\n";
}