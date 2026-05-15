/**
 * Problem: Balanced Brackets
 * --------------------------
 * Check if the given expression has balanced brackets.
 * This is similar to Valid Parentheses but often used in the context 
 * of mathematical expressions.
 * 
 * Example:
 * Input: "[()]{}" -> Balanced
 * Input: "[(])"   -> Not Balanced
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * Approach: Stack
 */
bool isBalanced(string expr) {
    stack<char> s;
    char x;
 
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }
 
        // If it's a closing bracket and stack is empty, it's unbalanced
        if (s.empty()) return false;
 
        switch (expr[i]) {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[') return false;
            break;
 
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[') return false;
            break;
 
        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{') return false;
            break;
        }
    }
 
    return (s.empty());
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;
 
    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}

/**
 * Interview Tips:
 * - Explain why a stack is the ideal data structure (Last In First Out).
 * - Mention time complexity O(N) and space complexity O(N).
 * - Discuss edge cases like empty string or only opening/closing brackets.
 */
