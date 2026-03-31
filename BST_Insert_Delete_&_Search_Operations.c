//Parv Pahuja - 25070521089

//Binary Search Tree (BST) - Insert, Delete, and Search Operations

/*
Write a program to implement the following operations in a Binary Search Tree (BST)

Inserting a node
Deleting a node
Search a node

Input Format:
The first line of input contains an integer N, representing the number of operations to be performed on the Binary Search Tree.
The next N lines contain space-separated integers where:
The first integer indicates the operation to be performed.
The second integer is the element to be inserted, deleted, or searched.
The operations are defined as follows:
 → Insert element X into the BST.
 → Delete element X from the BST.
 → Search for element X in the BST.

Output Format:
Print "found" if the element is found during the search operation.
Print "not found" if the element is not found during the search operation.
If the element to be deleted is not found, continue to the next operation without modifying the tree.
Display the output after processing all inputs.

Sample Test Case:
Input:
6
1 50
1 30
1 70
3 30
2 30
3 30

Output:
found  
not found  

Note:
If an element to be deleted is not present, the tree remains unchanged.
Display all outputs after processing all inputs.
Refer to the visible test cases for a better understanding.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_OPS 100


typedef struct Node {
    
    //code here...
    int data;
    struct Node *left, *right;
    
    
} Node;


Node* createNode(int data) {
    
    //code here...
     Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
    
}


Node* insert(Node *root, int data) {
    
    
    //code here...
    
     if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


Node* findMin(Node *root) {
    
    
    //code here...
    while (root && root->left != NULL)
        root = root->left;
    return root;
    
    
}


Node* deleteNode(Node *root, int key) {
    
    
    //code here...
     if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
    


    
    
    
}

// Search for a key in the BST.
bool search(Node *root, int key) {
    
    
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
    //code here..
    
    
}

int main() {
    int opCount;
    scanf("%d", &opCount);
    
    Node *root = NULL;
    
    char outputs[MAX_OPS][50];
    int outIndex = 0;
    
    int op, key;
    for (int i = 0; i < opCount; i++) {
        scanf("%d", &op);
        if(op == 1 || op == 2 || op == 3)
            scanf("%d", &key);
            
        switch(op) {
            case 1: // Insert
                root = insert(root, key);
                break;
            case 2: // Delete
                if(search(root, key))
                    root = deleteNode(root, key);
                break;
            case 3: { // Search
                if(search(root, key))
                    strcpy(outputs[outIndex++], "found");
                else
                    strcpy(outputs[outIndex++], "not found");
                break;
            }
            default:
                break;
        }
    }
    
    for (   int i = 0; i < outIndex; i++      ) {
        
        printf("%s\n", outputs[i]);
        
        }

    return 0;
        
        
        
        
}
