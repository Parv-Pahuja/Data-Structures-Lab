// Parv Pahuja - 25070521089

// Value Added Problem - 1

/*
Problem-1

Given a Binary Search Tree and a range [low, high]. Find all the numbers in the BST that
lie in the given range.
Note: Element greater than or equal to root go to the right side.
Concept: Binary Search Tree

Example-1:
Input:
     17
     /\
    4  18
   /\
  2  9
l = 4, h = 24
Output: 
4 9 17 18

Example-2:
Input:
     16
     /\
    7  20
   /\
  1  10
l = 13, h = 23
Output: 
16 20

Company: Flipkart, Amazon, Microsoft
*/

// Code Of Problem-1

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void printRange(struct Node* root, int low, int high) {
    if (root == NULL) {
        return;
    }

    if (low < root->data) {
        printRange(root->left, low, high);
    }

    if (low <= root->data && high >= root->data) {
        printf("%d ", root->data);
    }

    if (high > root->data) {
        printRange(root->right, low, high);
    }
}

int main() {
    /* Example 1 Tree Construction
          17
         /  \
        4    18
       / \
      2   9
    */
    struct Node* root = newNode(17);
    root->left = newNode(4);
    root->right = newNode(18);
    root->left->left = newNode(2);
    root->left->right = newNode(9);

    int low = 4, high = 24;
    printf("Elements in range [%d, %d]: ", low, high);
    printRange(root, low, high); 
    // Output: 4 9 17 18

    return 0;
}

// Output: Elements in range [4, 24]: 4 9 17 18 
