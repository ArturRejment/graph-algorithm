struct ListElement
{
    ListElement *next;
    int vertex; // The number of vertex
    int weight; // Weight of the edge
};

class Graph
{
private:
    int n;              // Number of vertices
    int m;              // Number of edges
    int **matrix;       // Incidence matrix
    ListElement **list; // Neighbour list

public:
    // Getters
    int getVertices();       // Returns number of vertices
    int getEdges();          // Returns number of edges
    int **getMatrix();       // Returns incidence matrix
    ListElement **getList(); // Returns neighbour list

    // Others
    Graph();                    // Creates an epty graph
    void printMatrix();         // Prints incidence matrix of the graph
    void printList();           // Prints heighbour list of the graph
    void printGraph();          // Prints both list and matrix
    void importGraphFromFile(); // Imtorts data from the file into the graph
};