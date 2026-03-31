//Parv Pahuja - 25070521089

//Implement a Menu-Driven Doubly Linked List in C

/*
Write a menu-driven C program to perform operations on a Doubly Linked List.
The program should support insertion, deletion, display, reversal, concatenation of another list, and exit operations.

Menu
The program repeatedly displays the following menu:
Enter operation
1: Insert
2: Delete
3: Display
4: Reverse
5: Concatenate
6: Exit
The user selects an operation by entering a number from 1 to 6.

Operations Description:

1. Insert
Insert a number at the end of the doubly linked list, print:
Inserted successfully

2. Delete: Delete a specific number from the doubly linked list.
If the list is empty, print:
List is empty
If the number is not found, print:
Number <num> not found
If deletion is successful, print:
List after deletion: <elements>

3. Display: Display all elements in the doubly linked list in order, separated by spaces.
If the list is empty, print:
List is empty

4. Reverse: Reverse the doubly linked list and display the elements after reversal.
If the list is empty, print:
List is empty

5. Concatenate: Concatenate another doubly linked list to the existing list.
If the second list size is 0, print:
Second list is empty
Otherwise, display the concatenated list.

6. Exit:
Terminate the program and print:
Exit

Input Format:
The first line contains an integer representing the operation code:
1. Insert
2. Delete
3. Display
4. Reverse
5. Concatenate
6. Exit

For operations 1 and 2, the next line contains an integer representing the number to be inserted or deleted.
For operation 5 (Concatenate), the next line contains an integer n representing the number of elements in the second list, followed by a line containing n space-separated integers representing the elements of the second list.
The menu is displayed repeatedly, and input continues until the user enters 6 (Exit).

Output Format:
Display the menu before every operation.
Print outputs exactly as specified in the operation descriptions.
List elements should be printed space-separated.
After concatenation or reversal, display the updated list.
On exit, print "Exit".

Note: Refer to visible test cases for better understanding.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Head pointer of the first list
struct Node* head = NULL;

// Function to display the list
void display() {

   // write your code here..
			if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Function to insert a number at the end
void insert(int num) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (head == NULL) {
		head = newNode;
	} else {
		struct Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	printf("Inserted successfully\n");
}

// Function to delete a specific number
void deleteNumber(int num) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node* temp = head;
	while (temp != NULL && temp->data != num) {
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Number %d not found\n", num);
		return;
	}

	if (temp == head) {
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
	} else {
		temp->prev->next = temp->next;
		if (temp->next != NULL) {
			temp->next->prev = temp->prev;
		}
	}
	free(temp);

	printf("List after deletion: ");
	struct Node* curr = head;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

// Function to reverse the list
void reverseList() {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node* temp = NULL;
	struct Node* current = head;

	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		current = current->prev; 
	}

	if (temp != NULL) {
		head = temp->prev;
	}

	struct Node* curr = head;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");

}

// Function to concatenate another list
void concatenate() {
	int n, val;
	scanf("%d", &n);

	if (n == 0) {
		printf("Second list is empty\n");
		return;
	}
	struct Node* head2 = NULL;
	struct Node* tail2 = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = val;
		newNode->next = NULL;
		newNode->prev = NULL;
		if (head2 == NULL) {
			head2 = newNode;
			tail2 = newNode;
		} else {
			tail2->next = newNode;
			newNode->prev = tail2;
			tail2 = newNode;
		}
	}

	if (head == NULL) {
		head = head2;
	} else {
		struct Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = head2;
		head2->prev = temp;
	}

	struct Node* curr = head;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main() {
    int choice, num;

    while (1) {
        printf("Enter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &num);
                insert(num);
                break;

            case 2:
                scanf("%d", &num);
                deleteNumber(num);
                break;

            case 3:
                display();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exit\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
