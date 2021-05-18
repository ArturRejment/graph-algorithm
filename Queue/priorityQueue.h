struct Edge {
    int vert1;      // Starting vertex of the edge
    int vert2;      // Ending vertex of the edge
    int weight;     // Weight of the edge
};

class Queue
{
    private:
        Edge *heap;         // Priority queue implemented as a heap
        int heapPosition;   // Position of the heap
    
    public:
        Queue(int n);       // Create n-element array for the heap
        ~Queue();           // Delete heap from the memory
        Edge front();       // Returns edge from the beginning of the heap
        void push(Edge e);  // Puts on the heap new edge and restores heap properties
        void pop();         // Delete root from the heap and restore heap properties
};