// Definition of disjoint sets (zbiory rozłączne)
struct SetNode
{
    int up;
    int rank;
};

class DisjointSet
{
private:
    SetNode *set; // Array for sets elements
    int setSize;  // Size of the DisjointSet

public:
    DisjointSet(int n);       // Create array for n sets
    ~DisjointSet();           // Delete array
    void makeSet(int vertex); // Make set in the array
    int findSet(int vertex);  // Returns index of the representant of the set where is vertex
    void unionSets(Edge);     // Unions sets with v and u
    bool isAllOneSet();       // Checks if all verices belongs to one set
};

// Definition of MST
struct TreeNode
{
    TreeNode *next; // Next node
    int vertex;     // Starting Vertex
    int weight;     // Weight
};

class MST
{
private:
    TreeNode **neighbourhoodList; // Neighbourhood list
    int listSize;                 // Amount of units in the list
    int weight;

public:
    MST(int n);
    ~MST();
    void addEdge(Edge);          // Add edge to the tree
    void printMST();             // Print tree and its weight
    TreeNode *getNeighList(int); // Returns pointer for beginning neighbourhood list
};