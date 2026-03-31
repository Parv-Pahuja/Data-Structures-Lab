//Parv Pahuja - 25070521089

//Graph implementation - Adjacency list Directed graph

/*
Write a C program to represent a Directed Graph using an adjacency list.

Functions to be implemented in GraphsAdjacencyListDirectedGraph.c file:

1. void print(int *N) - This function should display the adjacency list of the directed graph.
For each vertex that has outgoing edges, print the vertex followed by =>.
Print all adjacent vertices separated by a tab character.
Print each vertex’s adjacency list on a new line.

2. void insertVertex(int *N) - This function should insert a new vertex into the graph.
Read the number of edges from existing vertices to the new vertex
For each such edge, read the source vertex number
An edge is added from the source vertex to the new vertex
Read the number of edges from the new vertex to existing vertices
For each such edge, read the destination vertex number
An edge is added from the new vertex to the destination vertex
If an invalid vertex is entered, display:
Invalid vertex.
After successful insertion, display:
After inserting vertex the adjacency list is :
and print the updated adjacency list.

3. void insertEdge(int *N) - This function should insert a directed edge from a source vertex to a destination vertex.
Enter the source vertex of the edge :
Enter the destination vertex of the edge :
If either of the vertex is invalid, display:
Invalid vertex.
After inserting the edge, display:
After inserting edge the adjacency list is :
and print the updated adjacency list.

4. void deleteVertex(int *N) - This function should delete a specified vertex from the graph.
Remove all edges associated with that vertex.
If the graph is empty, display:
Graph is empty.
If the vertex is invalid, display:
Invalid vertex.
After deletion, display:
After deleting vertex the adjacency list is :
and print the updated adjacency list.

5. void deleteEdge(int *N) - This function should delete a directed edge from a given source vertex to a destination vertex.
Enter the source vertex of the edge :
Enter the destination vertex of the edge :
After deleting the edge, display:
After deleting edge the adjacency list is :
and print the updated adjacency list.

Menu:
After graph creation, the following menu is displayed after every operation:

1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit

Input and Output Format:

1. The program first reads:
Number of vertices (
)
Enter the number of vertices :
Number of edges (
)
Enter the number of edges :
Source and destination for each edge
Enter source :
Enter destination :

2. After displaying the menu, the program reads an integer option from the user as:

Enter your option:
And perform the operations as described in the function implementation

3. Output is displayed immediately after each operation, exactly in the specified format.

4. Vertices are numbered starting from 1.

5. The graph is a directed graph.

Note:
A part of the program is already provided, which includes the structure definition, global adjacency list array, and a menu-driven main() function.
You are required to implement the user-defined functions in the file GraphsAdjacencyListDirectedGraph.c to perform various graph operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

typedef struct node *GNODE;

GNODE graph[20] = {NULL};


GNODE createNode(int v) {
    GNODE temp = (GNODE)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}


void print(int *N) {
    for (int i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>", i);
            GNODE temp = graph[i];
            while (temp != NULL) {
                printf("%d\t", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}


void insertEdge(int *N) {
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE newNode = createNode(dest);

    if (graph[src] == NULL) {
        graph[src] = newNode;
    } else {
        GNODE temp = graph[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}


void insertVertex(int *N) {
    (*N)++;

    int edges, v;


    printf("Enter number of edges from existing vertices to new vertex : ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d", &v);
        if (v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            continue;
        }

        GNODE newNode = createNode(*N);

        if (graph[v] == NULL)
            graph[v] = newNode;
        else {
            GNODE temp = graph[v];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }


    printf("Enter number of edges from new vertex to existing vertices : ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d", &v);
        if (v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            continue;
        }

        GNODE newNode = createNode(v);

        if (graph[*N] == NULL)
            graph[*N] = newNode;
        else {
            GNODE temp = graph[*N];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}


void deleteEdge(int *N) {
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE temp = graph[src], prev = NULL;

    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL)
        graph[src] = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}


void deleteVertex(int *N) {
    int v;
    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }


    for (int i = 1; i <= *N; i++) {
        GNODE temp = graph[i], prev = NULL;

        while (temp != NULL) {
            if (temp->vertex == v) {
                if (prev == NULL)
                    graph[i] = temp->next;
                else
                    prev->next = temp->next;

                GNODE del = temp;
                temp = temp->next;
                free(del);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }

   
    GNODE temp = graph[v];
    while (temp != NULL) {
        GNODE del = temp;
        temp = temp->next;
        free(del);
    }

    for (int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }

    graph[*N] = NULL;


    for (int i = 1; i <= *N; i++) {
        GNODE temp2 = graph[i];
        while (temp2 != NULL) {
            if (temp2->vertex > v)
                temp2->vertex--;
            temp2 = temp2->next;
        }
    }

    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}
