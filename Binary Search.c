//Parv Pahuja - 25070521089

//Binary Search

/*
Write a C program that performs a binary search to find the position of the given integer in the array.

Input Format:
The first line contains an integer n, the number of elements in the array.
The second line contains n space-separated integers in sorted order.
The third line contains an integer x, the target element to search for.


Output Format:
If the target element is found, output the message:
Element found at index <index>
Where,
<index> is the index of the target element, starting from 0
If the target element is not found, output:
Element not found

Note:
The indexing starts from 0.
The driver code is already provided for you. You need to complete the binarySearch() function to perform the Binary Search correctly.
*/

#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        
		int mid = left + (right - left) / 2;

		if (arr[mid] == x)
			return mid;
		if (arr[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
    }
    return -1;
}

int main() {
    int n, x;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &x);
    
    int result = binarySearch(arr, n, x);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
