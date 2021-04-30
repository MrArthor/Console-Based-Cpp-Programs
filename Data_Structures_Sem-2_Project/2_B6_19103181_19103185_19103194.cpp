#include <bits/stdc++.h>
using namespace std;
// namespace
class node
{
public:
    int val;
    int weight;
    node *next;
};

class edge
{
public:
    int weight;
    int u, v; // edge from u ---> v
};

// Adds an edge to an Adjacency List element
node *AddEdge(node *head, int num, int weight)
{
    node *p = new node;

    p->val = num;
    p->next = head;
    p->weight = weight;
    head = p;

    return p;
}

// enqueues an entry into the Priority Queue
void enqueue(edge heap[], int size, edge value)
{
    heap[size] = value;

    int i = size;
    edge temp;

    while (i >= 1)
    {
        if (heap[i / 2].weight > heap[i].weight)
        {
            temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;

            i = i / 2;
        }
        else
        {
            break;
        }
    }
}

void heapify(edge heap[], int size, int index)
{
    int i = index;
    edge temp;

    while ((2 * i) < size)
    {
        if ((2 * i) + 1 >= size)
        {
            if (heap[i].weight > heap[2 * i].weight)
            {
                temp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = temp;

                break;
            }
        }

        if (heap[i].weight > heap[2 * i].weight || heap[i].weight > heap[2 * i + 1].weight)
        {
            if (heap[2 * i].weight <= heap[(2 * i) + 1].weight)
            {
                temp = heap[2 * i];
                heap[2 * i] = heap[i];
                heap[i] = temp;

                i = 2 * i;
            }
            else if (heap[2 * i].weight > heap[(2 * i) + 1].weight)
            {
                temp = heap[(2 * i) + 1];
                heap[(2 * i) + 1] = heap[i];
                heap[i] = temp;

                i = (2 * i) + 1;
            }
        }
        else
        {
            break;
        }
    }
}

// Deletes and entry in the Priority Queue
void deleteNode(edge heap[], int size, int index)
{
    edge temp = heap[index];

    heap[index] = heap[size - 1];
    heap[size - 1] = temp;

    int i = index;
    --size;

    heapify(heap, size, i);
}

// Returns the element with
// Minimum Priority and deletes it
edge extractMin(edge heap[], int size)
{
    edge min = heap[0];

    deleteNode(heap, size, 0);

    return min;
}

// PrimMST's Algorithm function
void PrimMST(node *adjacencylist[], int vertices, int edges, int startVertex, node *MST[])
{
    int current = startVertex, newVertex;
    int visited[vertices + 1];
    node *temp;
    edge var;
    edge priorityQueue[2 * edges];
    int queueSize = 0;

    int i;

    for (i = 0; i <= vertices; ++i)
    { // Initializing
        visited[i] = 0;
    }

    i = 0;

    while (i < vertices)
    {
        if (visited[current] == 0)
        {                         // If current node is not visited
            visited[current] = 1; // Mark it visited
            temp = adjacencylist[current];

            while (temp != NULL)
            {
                var.u = current;
                var.v = temp->val;
                var.weight = temp->weight;

                if (!visited[var.v])
                {
                    // If the edge leads to an un-visited
                    // vertex only then queueSize it
                    enqueue(priorityQueue, queueSize, var);
                    ++queueSize;
                }

                temp = temp->next;
            }

            var = extractMin(priorityQueue, queueSize); // The greedy choice
            --queueSize;

            newVertex = var.v;
            current = var.u;

            if (visited[newVertex] == 0)
            {
                // If it leads to an un-visited vertex, add it to MST
                MST[current] = AddEdge(MST[current], newVertex, var.weight);
                MST[newVertex] = AddEdge(MST[newVertex], current, var.weight);
            }

            current = newVertex;
            ++i;
        }
        else
        {
            var = extractMin(priorityQueue, queueSize);
            --queueSize;
            newVertex = var.v;
            current = var.u;

            if (visited[newVertex] == 0)
            {
                MST[current] = AddEdge(MST[current], newVertex, var.weight);
                MST[newVertex] = AddEdge(MST[newVertex], current, var.weight);
            }

            current = newVertex;
        }
    }
}

int main()
{
    int vertices, edges, i, j, v1, v2, weight;

    cout << "Enter the Number of Places You Have To Deliver -\n";
    cin >> vertices;

    cout << "Enter the Number of Connections Between Places -\n";
    cin >> edges;

    node *adjacencyList[vertices + 1];
    node *MST[vertices + 1];

    for (i = 0; i <= vertices; ++i)
    {
        adjacencyList[i] = NULL;
        MST[i] = NULL;
    }

    for (i = 1; i <= edges; ++i)
    {
        cout << "Enter Source ";
        cin >> v1;
        cout << "Enter Distination ";
        cin >> v2;
        cout << "Enter Weight ";
        cin >> weight;
        adjacencyList[v1] = AddEdge(adjacencyList[v1], v2, weight); //Adding edge v1 ---W---> v2
        adjacencyList[v2] = AddEdge(adjacencyList[v2], v1, weight); //Adding edge v2 ---W---> v1
    }

    // Printing Adjacency List
    cout << "\nAdjacency List -\n\n";
    for (i = 1; i <= vertices; ++i)
    {
        cout << "adjacencyList[" << i << "]";

        node *temp = adjacencyList[i];

        while (temp != NULL)
        {
            cout << temp->val << " (" <<temp->weight << ") ";
            temp = temp->next;
        }

        cout << "\n";
    }

    int startVertex;

    cout << "\nEnter a Start Vertex - ";
    cin >> startVertex;
    PrimMST(adjacencyList, vertices, edges, startVertex, MST);

    // Printing MST
    cout << "\nMinimum Spanning Tree -\n\n";
    for (i = 1; i <= vertices; ++i)
    {
        cout << "MST[" << i << "] ";

        node *temp = MST[i];

        while (temp != NULL)
        {
            cout << temp->val <<   " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    return 0;
}