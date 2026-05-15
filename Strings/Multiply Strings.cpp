/**
 * Problem: Multiply Strings
 * -------------------------
 * Given two non-negative integers num1 and num2 represented as strings, 
 * return the product of num1 and num2, also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the 
 * inputs to integer directly.
 * 
 * Example:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * Time Complexity: O(M * N) where M and N are lengths of num1 and num2.
 * Space Complexity: O(M + N) to store the result.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Approach: Column-wise Multiplication (Grade School Method)
 * ---------------------------------------------------------
 * Multi-digit multiplication num1 * num2 results in a string of length at most length(num1) + length(num2).
 * Indices: num1[i] * num2[j] will contribute to indices [i+j] and [i+j+1] in the result array.
 */
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int n1 = num1.length();
    int n2 = num2.length();
    vector<int> result(n1 + n2, 0);
    
    // Reverse iterate to multiply digit by digit
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    // Convert result vector to string
    string s = "";
    for (int num : result) {
        if (!(s.empty() && num == 0)) { // Skip leading zeros
            s += to_string(num);
        }
    }
    
    return s.empty() ? "0" : s;
}

int main() {
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Product: " << multiply(num1, num2) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Explain why the result length is at most M+N.
 * - Demonstrate how i+j and i+j+1 indices are derived (visualize the grid).
 * - Mention that this handles very large numbers that long long cannot.
 */
