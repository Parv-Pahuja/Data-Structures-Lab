//Parv Pahuja - 25070521089

//Binary Search Tree Operations

/*
Write a C program to implement a binary search tree with the following functionalities:

Insert(): Insert a node into the binary search tree (BST).
Inorder(): Perform inorder traversal of the BST.
Preorder(): Perform preorder traversal of the BST.
Postorder(): Perform postorder traversal of the BST.
Delete(): Delete a node from the BST.
Exit(): Terminate the program.

Menu Options:
1. Insert Node
2. In-order Traversal  
3. Pre-order Traversal  
4. Post-order Traversal  
5. Delete Node
6. Exit

Option 1: Insert
Prompt the user with:
Data: <value>
Insert the value into the BST.
Duplicates are allowed and are always inserted in the right subtree of the node with the same value.
No confirmation message is needed after insertion.

Option 2: In-Order Traversal
If the tree is empty:
The tree is empty
Otherwise, print the node values using in-order traversal in a single line separated by spaces:
<value1> <value2> <value3> ...

Option 3: Pre-Order Traversal
If the tree is empty:
The tree is empty
Otherwise, print the node values using pre-order traversal in a single line separated by spaces:
<value1> <value2> <value3> ...

Option 4: Post-Order Traversal

If the tree is empty, print:
The tree is empty
Otherwise, print the node values using post-order traversal in a single line separated by spaces:
<value1> <value2> <value3> ...

Option 5: Delete
Prompt the user with:
Delete: <value>
Delete the node with the given value from the BST.
If the value is not found in the tree, print:
Value not found
If the node is successfully deleted, no confirmation message is needed.

Option 6: Exit
Terminate the program

Note:
If the user enters an invalid choice, print: "Invalid choice".
Each traversal must print a newline after completing the traversal
Refer to visible test cases to strictly match the input/output layout.
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void inorderHelper(struct TreeNode* node) {
    if (node != NULL) {
        inorderHelper(node->left);
        printf("%d ", node->val);
        inorderHelper(node->right);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty");
    } else {
        inorderHelper(root);
    }
}

void preorderHelper(struct TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->val);
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty");
    } else {
        preorderHelper(root);
    }
}

void postorderHelper(struct TreeNode* node) {
    if (node != NULL) {
        postorderHelper(node->left);
        postorderHelper(node->right);
        printf("%d ", node->val);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty");
    } else {
        postorderHelper(root);
    }
}

struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int val, int* found) {
    if (root == NULL) {
        return root;
    }
    if (val < root->val) {
        root->left = deleteNode(root->left, val, found);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val, found);
    } else {
        *found = 1;
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        int dummy = 0;
        root->right = deleteNode(root->right, temp->val, &dummy);
    }
    return root;
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}




int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                postorderTraversal(root);
                printf("\n");
                break;

            case 5: {
                printf("Delete: ");
                scanf("%d", &data);
                int found = 0;
                root = deleteNode(root, data, &found);
                if (!found) {
                    printf("Value not found\n");
                }
                break;
            }

            case 6:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
