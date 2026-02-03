// Parv Pahuja - 25070521089

// Singly Linked List Operations

/*
Write a menu-driven C program to implement the fundamental operations on a Singly Linked List using dynamic memory allocation.

You are provided with a partially completed code that already defines the following:
- A struct Node representing a node in the linked list
- A struct LinkedList containing the head pointer and the size of the list
- Function prototypes with empty bodies for the operations you need to implement for insert(struct LinkedList* list, int data, int position), deleteNode(struct LinkedList* list, int position), and reverse(struct LinkedList* list).
- A menu-driven main() function for user interaction

You need to complete the logic inside these functions without modifying the given structure definitions or the main() function.

Functions Requirements:
1. insert(struct LinkedList* list, int data, int position)
- Insert a node with the given data at the specified position.
- If the position is less than 0 or greater than the current size of the list, print:
Invalid position
- Otherwise, insert the node and print:
Element <data> inserted at position <position>

2. deleteNode(struct LinkedList* list, int position)
- Delete a node from the specified position.
- If the position is less than 0 or greater than or equal to the size of the list, print:
Invalid position
- Otherwise, delete the node and print:
Element at position <position> deleted

3. reverse(struct LinkedList* list)
- Reverse the linked list using pointer manipulation.
- This function is used only for displaying the list in reverse order.
- After displaying, the list must be restored to its original order, so that future operations work on the original list.

4. displayReversed(struct LinkedList* list) - - Display the linked list (used after reversing the list).

5. Exit: Exit the program.

Menu Operations:
1. Insert
2. Delete
3. Reverse
4. Display
5. Exit

Input Format:
- The input prompts to enter an integer n, the number of elements in the linked list, as:
Enter the number of elements in the linked list: 
- The next line prompts to enter n space-separated integers - initial elements of the list, as:
Enter the elements:
- A sequence of menu choices (1–5) along with required inputs for each operation as mentioned above.
- For Insert, program reads the data and position in separate lines as follows:
Enter data to insert: 
Enter position to insert: 
- For Delete, the program reads the position in the below format:
Enter position to delete: 
- For Reverse and Display, no additional input is needed.
- Menu repeats until the user selects Exit.

Output Format:
- Display appropriate messages for each operation exactly as described in the Function Requirements section.
- Display the linked list in the below format:
<data1> -> <data2> -> ... -> NULL

Constraints:
0 <= n <= 1000
Positions are 0-based

Note:
- Use the given function definitions and print statements already provided in the editor.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList* initializeList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void insert(struct LinkedList* list, int data, int position) {
    // write your code here for insertion

	if (position < 0 || position > list -> size) {
		printf("Invalid position\n");
		return;
	}

	struct Node* newNode = createNode(data);

	if (position == 0) {
		newNode->next = list->head;
		list->head = newNode;
	} else {
		struct Node* current = list->head;
		for (int i = 0; i < position - 1; i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	list->size++;
	printf("Element %d inserted at position %d\n", data, position);
	
}
void deleteNode(struct LinkedList* list, int position) {
    // write your code here 

	if (position < 0 || position >= list->size) {
		printf("Invalid position\n");
		return;
	}

	struct Node* temp = list->head;

	if (position == 0) {
		list->head = list->head->next;
		free(temp);
	} else {
		struct Node* prev = NULL;
		for (int i = 0; i < position; i++) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		free(temp);
	}

	list->size--;
	printf("Element at position %d deleted\n", position);

}
void reverse(struct LinkedList* list) {
    // write your code here 

	struct Node* prev = NULL;
	struct Node* current = list->head;
	struct Node* next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
    
    
    
    
    
}
void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayReversed(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int num_elements;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &num_elements);
    struct LinkedList* list = initializeList();
    int data;
    printf("Enter the elements:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &data);
        insert(list, data, i);
    }
    int choice, position;
    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Reverse\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert(list, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(list, position);
                break;
            case 3:
                reverse(list);
                printf("Reversed List: ");
                displayReversed(list);
                reverse(list); 
                break;
            case 4:
                printf("Linked List: ");
                display(list);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
