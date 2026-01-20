//Parv Pahuja - 25070521089
//Insertion Sort

/* Write a program in C that implements the Insertion sort to sort a given array of integers in ascending order.

Input Format:
The first line of input should be an integer n, representing the number of elements in the array.
The second line contains n space-separated integers representing the elements of the array to be sorted.

Output Format:
The output displays the sorted array as space-separated integers in ascending order.

Note: The driver code is already provided for you. You need to complete the insertionSort() function to perform the insertion sort correctly.*/

#include <stdio.h>

void insertionSort(int a[], int n) {
    //write your code here...
	int key, i, j;
    for(i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main() {
    int a[20], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
