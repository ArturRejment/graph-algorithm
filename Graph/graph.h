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
    int weight;         // The weight of Graph (sum of all edges weight)

public:
    // Getters
    int getVertices();          // Returns number of vertices
    int getEdges();             // Returns number of edges
    int getStartingVertex(int); // Returns staring vertex of edge
    int getEndingVertex(int);   // Returns ending vertex of edge
    int **getMatrix();          // Returns incidence matrix
    ListElement **getList();    // Returns neighbour list

    // Others
    Graph();                                // Creates an epty graph
    ~Graph();                               // Deletes and graph
    void printMatrix();                     // Prints incidence matrix of the graph
    void printList();                       // Prints heighbour list of the graph
    void printGraph();                      // Prints both list and matrix
    void importGraphFromFile();             // Imtorts data from the file into the graph
    void fillGraphWithRandomData(int, int); // Fills graph with random data
    void createMatrix(int);                 // Creates starting matrix
    void addEdge(int, int, int);            // Adds an edge to the graph
    bool checkEdge(int, int);               // Checks if given edge already exists
};