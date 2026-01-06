//Parv Pahuja - 25070521089

// Linear Search in an Array

/*  
Input Format:
The first line contains an integer n, representing the size of the array.
The second line contains n space-separated integers, representing the elements of the array.
The third line contains an integer key, representing the search element.


Output Format:

If the search element is found, the program displays the message "found at position <pos>", where pos is the position of the element in the array (0-indexed).
If the search element is not found, the program displays the message "<key> not found", where key is the search element.


Note:

The output printing code is already provided. You must write your logic using the variables pos, and key correctly to perform the linear search.
*/

#include<stdio.h>
void main() {
	
	int len, pos = 0, flag = 0;

	scanf("%d", &len);
	int arr[len];
	for(int i = 0; i<len; i++) {
		scanf("%d", &arr[i]);
	}
	int key;
	scanf("%d", &key);
	for(int j = 0; j<len; j++) {
		if(arr[j] == key){
			pos = j;
			flag = 1;
		}
	
	}
	if (flag == 1) {
		printf("found at position %d\n", pos);
	} else {
		printf("%d not found\n", key);
	}
}
