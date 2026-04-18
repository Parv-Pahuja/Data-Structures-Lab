// Parv Pahuja - 25070521089

// Depth-First Search (DFS)

/*
Write a C program to implement and perform a Depth-First Search (DFS) on a directed graph represented using an adjacency list. The program should print all vertices reachable from a given starting vertex in the order they are visited by DFS.

Input Format:
The first line contains two integers: V (number of vertices) and E (number of edges).
The next E lines each contain two integers: u and v, where there is a directed edge from node u to node v.
The last line contains a single integer, which is the starting node for the DFS traversal.

Output Format:
Print the vertices reachable from the starting vertex in the exact order they are visited by DFS.
Each vertex should be printed, followed by a single space.
The output should be printed on one line only as:
v1 v2 v3 ... vn 

Constraints:
1 <= V <= 100
0 <= E <= V x (V-1)
Vertices are numbered from 0 to V-1


﻿Note:
In DFS, the smaller numbered node is visited first when there are multiple adjacent nodes, ensuring a consistent traversal order.
Refer to the visible test cases for a better understanding.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    //write your code here...
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
    
    
    
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    //write your code here...
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    //write your code here...
    for (int i = 0; i < V; i++) {

        int swapped;
        do {
            swapped = 0;
            Node* curr = adjList[i];
            while (curr != NULL && curr->next != NULL) {
                if (curr->vertex > curr->next->vertex) {
                    int temp = curr->vertex;
                    curr->vertex = curr->next->vertex;
                    curr->next->vertex = temp;
                    swapped = 1;
                }
                curr = curr->next;
            }
        } while (swapped);
	}
    
}

// Depth-First Search (DFS) function
void DFS(int start) {
    //write your code here...
    visited[start] = 1;
    printf("%d ", start);
    Node* temp = adjList[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
	}
    
    
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
