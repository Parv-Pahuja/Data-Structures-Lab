// Parv Pahuja - 25070521089

// Concatenate Operation on Single Linked List

/*
Write a C program to implement a menu-driven application for performing operations on two Singly Linked Lists. The program should allow the user to create two singly linked lists, display them, and concatenate the second list to the end of the first list.

Functions need to be implemented in AllOperations.c:
1. NODE createNode(int x)
Create a new node using dynamic memory allocation, assign the given value to the data field, initialize the next pointer to NULL, and return the address of the newly created node.
2. NODE addNode(NODE first, int x)
Insert a new node with the given value at the end of the specified linked list and return the updated head pointer.
3. NODE concatenate(NODE t1, NODE t2)
Concatenate the second singly linked list to the end of the first singly linked list and return the head pointer of the resulting list.
If either list is empty, return the non-empty list.
4. void displayList(NODE first)
Traverse and display the elements of the linked list in the format:
data --> data --> ... --> NULL

Menu Options:
The program should repeatedly display the following menu until user selects exit operation:
1. Create SLL1
2. Create SLL2
3. Display SLL1
4. Display SLL2
5. Concatenation
6. Exit
The user should enter a number (1-6) to select the operation.

Input Format:
The program repeatedly displays the menu, and the user enters a number between 1 and 6 to select an operation.
Creating a linked list (choices 1 or 2): After choosing 1 or 2, the program prompts:
Enter elements for SLL1 (-1 to end):
or
Enter elements for SLL2 (-1 to end):
The user then enters a sequence of integers separated by spaces. Enter -1 to indicate the end of input for the list.
Other operations (choices 3-5): No additional input is required.
Choice 6 exits the program.

Output Format:
Display the menu after every operation.
For displaying lists, print elements using the format:
data --> data --> ... --> NULL
After concatenation, display the concatenated list using the same format.
You are already provided with SingleLinkedList.c, which contains the menu-driven main() function and the required structure definition. Now you are required to write the code in a separate file named AllOperations.c using appropriate user-defined functions to support the operations on singly linked lists.
*/

struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        return NULL;
    }
    temp->data = x;
    temp->next = NULL;
    return temp;
}

NODE addNode(NODE first, int x) {
    NODE temp, cur;

    temp = createNode(x);
    if (first == NULL) {
        return temp;
    }

    cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;

    return first;    
}

NODE concatenate(NODE t1, NODE t2) {
    NODE cur;

    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;

    cur = t1;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = t2;

    return t1;  
}

void displayList(NODE first) {
    NODE cur = first;

    while (cur != NULL) {
        printf("%d --> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");  
}
