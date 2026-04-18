// Parv Pahuja - 25070521089

// Value Added Problem - 2

/*
Problem 2:
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine
whether the Expression is balanced or not.
An expression is balanced if:
1. Each opening bracket has a corresponding closing bracket of the same type.
2. Opening brackets must be closed in the correct order.
Concept: Stack

Examples:
Input: s = "[[()}]"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "("
Output: false
Explanation: The expression is not balanced as there is a missing ')' at the end.

Input: s = "([{]})"
Output: false
Explanation: The expression is not balanced as there is a closing ']' before the closing 'J'.

Constraints:
1 ≤ s.size() ≤ 106 s[i] ∈ {'{', '}', '(', ')', '[', ']'}

Company: Flipkart, Amazon, Microsoft, OYO, Oracle, Walmart, Adobe, Google
*/

// Code For Problem 2

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(char* s) {
    int n = strlen(s);
    if (n == 0) return true;

    // Allocate memory on the heap for large strings (up to 10^6)
    char* arr = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char current = s[i];
        
        // If it's an opening bracket, push to our "stack" array
        if (current == '(' || current == '{' || current == '[') {
            arr[++top] = current;
        } 
        else {
            // If we find a closing bracket but the stack is empty
            if (top == -1) {
                free(arr);
                return false;
            }
            
            // Pop the last opening bracket and compare
            char lastOpen = arr[top--];
            if (!isMatching(lastOpen, current)) {
                free(arr);
                return false;
            }
        }
    }

    bool result = (top == -1);
    free(arr); // Always free dynamic memory
    return result;
}

int main() {
    char s1[] = "{[()]}";
    char s2[] = "[(])";

    printf("Input: %s | Output: %s\n", s1, isBalanced(s1) ? "true" : "false");
    printf("Input: %s | Output: %s\n", s2, isBalanced(s2) ? "true" : "false");

    return 0;
}

/*
Output: 
Input: {[()]} | Output: true
Input: [(]) | Output: false
*/
