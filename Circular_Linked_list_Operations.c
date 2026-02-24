// Parv Pahuja - 25070521089

// Circular Linked list Operations

/*
Write a menu-driven C program to implement the following operations on a Circular Linked List (CLL):

1. Create
Create a circular linked list with n nodes.
Read n integers from the user and form the list in the given order.

2. Insert - Insert a new node with value x at the given 1-based indexing position pos.
If pos <= 0, print:
Position not found
If the specified position does not exist in the circular linked list, print:
Position not found
Otherwise, insert the element at the specified index.

3. Delete - Delete a node at the given 1-based indexing position pos.
If the list is empty, print:
CLL is empty
If pos is invalid [(pos < 1 or pos > n (where n is the current number of nodes in the CLL)], print:
Position not found
If deletion is successful, print:
Deleted element: <value>

4. Display
Display all elements of the circular linked list in the following format:
Elements in CLL are: value -> value -> value ->
If the list is empty, print:
CLL is empty

5. Reverse - Reverse the circular linked list permanently by modifying the links between nodes.
After reversing, it prints the following message:
CLL reversed
Display the reversed list in the same format as the display operation.
If the list is empty, print:
CLL is empty

6. Concatenate
Create a second circular linked list with n nodes and concatenate it to the first circular linked list.
After concatenation, display the resulting circular linked list.

7. Exit - Terminate the program.

Input Format:
The program repeatedly displays the menu and reads the user’s choice.
1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit
After the menu operations, the program reads the user's choice(1 - 7):
choice: 
1. For Create operations:
Read an integer n representing the number of nodes, as:
How many nodes? 
Read n space-separated integers.
2. For Concat operations:
Read an integer n representing the number of nodes, as:
Creating second CLL to concatenate...
How many nodes in second CLL? 
Read n space-separated integers.
3. For Insert operations:
Read the position pos, as:
Position: 
Element: 
For Insert, also read the element x.
4. For Delete operations:
Read the position pos, as:
Position:
For Insert, also read the element x.
Input continues until the user selects Exit (7).

Output Format
The output will print the respective message based on the operations performed as described in the function requirements.
After concatenation, the output will be:
Concatenated CLL:
value -> value -> value ->

Note: Refer to the visible test cases for better understanding and strictly match the input and output formats.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
	if (n <= 0)
		return NULL;

	NODE first = NULL, temp, last = NULL;
	int x;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		temp = createNodeInCLL(x);

		if (first == NULL) {
			first = temp;
			last = temp;
			last->next = first;
		} else {
			last->next = temp;
			last = temp;
			last->next = first;
		}
	}
	return first;
}

// Traverse CLL
void traverseListInCLL(NODE first) {
NODE temp = first;
	do {
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while (temp != first);
	printf("\n");


}

// Insert at given position in CLL
NODE insertAtPositionInCLL( NODE first, int pos, int x) {
 NODE temp = createNodeInCLL(x);

	if (first == NULL && pos == 1) {
		temp->next = temp;
		return temp;
	}

	int count = 1;
	NODE cur = first;

	do {
		count++;
		cur = cur->next;
	} while (cur != first);

	if (pos < 1 || pos > count) {
		printf("Position not found\n");
		return first;
	}

	if (pos == 1) {
		NODE last = first;
		while (last->next != first)
			last = last->next;

		temp->next = first;
		last->next = temp;
		first = temp;
	} else {
		NODE prev = first;
		for (int i = 1; i < pos - 1; i++)
			prev = prev->next;

		temp->next = prev->next;
		prev->next = temp;
	}

	return first;
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL( NODE first, int pos) {
if (first == NULL) {
		printf("CLL is empty\n");
		return first;
	}

	int count = 1;
	NODE temp = first;
	while (temp->next != first) {
		count++;
		temp = temp->next;
	}

	if (pos < 1 || pos > count) {
		printf("Position not found\n");
		return first;
	}

	if (pos == 1) {
		NODE last = first;
		while (last->next != first)
			last = last->next;

		NODE del = first;

		if (first->next == first) {
			printf("Deleted element: %d\n", del->data);
			free(del);
			return NULL;
		}

		first = first->next;
		last->next = first;
		printf("Deleted element: %d\n", del->data);
		free(del);
	} else {
		NODE prev = first;
		for (int i = 1; i < pos - 1; i++)
			prev = prev->next;

		NODE del = prev->next;
		prev->next = del->next;
		printf("Deleted element: %d\n", del->data);
		free(del);
	}

	return first;
}

// Reverse CLL
NODE reverseCLL(NODE first) {
NODE prev = NULL, current = first, next = NULL;
	NODE last = first;

	if (first == NULL || first->next == first)
		return first;

	do {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	} while (current != first);

	first->next = prev;
	first = prev;

	return first;
}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {
if (first == NULL)
		return second;
	if (second == NULL)
		return first;

	NODE temp1 = first;
	while (temp1->next != first)
		temp1 = temp1->next;

	NODE temp2 = second;
	while (temp2->next != second)
		temp2 = temp2->next;

	temp1->next = second;
	temp2->next = first;

	return first;
}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
