// Parv Pahuja - 25070521089

// Merge Sort

/*
You are tasked with writing a program that sorts an array using the Merge Sort algorithm. The program should read the elements of the array, display them before and after sorting.

Input Format:
First, read an integer n representing the number of elements in the array.
Then read n space-separated integers, representing the elements of the array.

Output Format:
The first line of output should display the elements of the original array separated by a space.
The second line should display the elements of the sorted array.

Constraints:
1 <= n <= 1000
1 <= arr[i] <= 10^5

Note:
The driver code is already provided for you. You need to complete the required functions to perform the merge sort correctly.
*/

#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {

	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];

// write your code here

	for(int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for(int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}
	while(i < n1) {
		arr[k++] = L[i++];
	}
	while(j < n2) {
		arr[k++] = R[j++];
	}


}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {

  // write your code here
	if(left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
  
  
   
}

// Function to print an array
void printArray(int arr[], int size) {

// write your code here
	for(int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if(i < size - 1) {
			printf(" ");
		}
	}
	printf(" \n");
	
}

int main() {
    int n;
    
    // Input the size of the array
    printf("");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("");
    printArray(arr, n);

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);
    
    // Print the sorted array
    printf("");
    printArray(arr, n);

    return 0;
}
