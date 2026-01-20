//Parv Pahuja - 25070521089
//Bubble Sort

/*Write a C program that reads n integer numbers and arranges them in ascending order using Bubble Sort.

Input Format:
The first line contains an integer n, representing the size of the array.
The second line contains n space-separated integers, representing the elements of the array.

Output Format:
The output displays the sorted elements of an array in ascending order, separated by a space.

Note:
The driver code is already provided for you. You need to complete the bubbleSort() function to perform the Bubble Sort correctly.*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    // write the code..
  for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-1-i; j++) {
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
