/**
 * Problem: Valid Parentheses
 * -------------------------
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * Criteria:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 
 * Example:
 * Input: "()[]{}"
 * Output: true
 * 
 * Approaches:
 * 1. Using a Stack (Standard Approach)
 * 
 * Time Complexity: O(N) where N is the length of the string.
 * Space Complexity: O(N) for the stack.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * Approach: Stack Based Validation
 * -------------------------------
 * Push opening brackets onto the stack. When a closing bracket appears,
 * check if it matches the top of the stack.
 */
bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false; // Closing bracket with no opening
            
            char top = st.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false; // Mismatched brackets
            }
        }
    }
    
    return st.empty(); // If stack is not empty, some brackets weren't closed
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;
    
    if (isValid(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }
    
    return 0;
}

/**
 * Interview Tips:
 * - Discuss what happens if the string contains other characters.
 * - Mention that stack is the most natural fit for this "Last-In-First-Out" problem.
 * - Edge cases: empty string (valid usually), only opening/closing brackets.
 */
