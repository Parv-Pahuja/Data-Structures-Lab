//Parv Pahuja - 25070521089
//Selection Sort

/* Write a program to sort the elements of an array in descending order using the Selection Sort algorithm.

Input Format:

The first line contains an integer n, the number of elements in the array.
The second line contains n space-separated integers, the elements of the array.

Output Format:
The output displays the sorted array in descending order as a single line of space-separated integers.

Note:
The driver code is already provided for you. You need to complete the selectionSort() function to perform the selection sort correctly. */

#include <stdio.h>

void selectionSort(int arr[], int n) {
    //write your code here...
	int min;
    for(int i = 0; i < n-1; i++) {
		min = i;
		for(int j = i+1; j < n; j++) {
			if(arr[j] > arr[min]){
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main() {
    int n;

    // Input number of elements in the array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order using selection sort
    selectionSort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
