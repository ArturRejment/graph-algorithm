#include "priorityQueue.h"

Queue::Queue(int n)
{
    heap = new Edge[n];
    heapPosition = 0;
}

Queue::~Queue()
{
    delete[] heap;
}

Edge Queue::front()
{
    return heap[0];
}

void Queue::push(Edge edge)
{
    int i, j;

    i = heapPosition++; // Set i at the end of the heap
    j = (i - 1) >> 1;   // Calculate the position of parent

    // Find place in the heap for new edge
    while (i && (heap[j].weight > edge.weight))
    {
        heap[i] = heap[j];
        i = j;
        j = (i - 1) >> 1;
    }
    heap[i] = edge;
}

void Queue::pop()
{
    int i, j;
    Edge edge;

    if (heapPosition)
    {
        edge = heap[--heapPosition];

        i = 0;
        j = 1;

        while (j < heapPosition)
        {
            if ((j + 1 < heapPosition) && (heap[j + 1].weight < heap[j].weight))
            {
                j++;
            }
            if (edge.weight <= heap[j].weight)
                break;

            heap[i] = heap[j];
            i = j;
            j = (j << 1) + 1;
        }
        heap[i] = edge;
    }
}