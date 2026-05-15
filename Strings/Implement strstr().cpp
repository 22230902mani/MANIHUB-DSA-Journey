/**
 * Problem: Implement strstr()
 * --------------------------
 * Returns the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 * 
 * Example:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * Approaches:
 * 1. Brute Force (Sliding Window) - O(N*M)
 * 2. KMP Algorithm - O(N+M)
 * 3. Rabin-Karp - O(N+M)
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Approach 1: Brute Force (Sliding Window)
 * ---------------------------------------
 * Iterate through haystack and check if the substring starting at current index 
 * matches the needle.
 * 
 * Time Complexity: O(N * M) where N = haystack.length(), M = needle.length()
 */
int strStrBruteForce(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();
    
    if (m == 0) return 0;
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == m) return i;
    }
    
    return -1;
}

/**
 * Approach 2: Using string::find()
 * --------------------------------
 * C++ standard library's built-in way.
 */
int strStrSTL(string haystack, string needle) {
    size_t found = haystack.find(needle);
    if (found != string::npos) {
        return (int)found;
    }
    return -1;
}

int main() {
    string haystack, needle;
    cout << "Enter haystack: ";
    getline(cin, haystack);
    cout << "Enter needle: ";
    getline(cin, needle);
    
    cout << "Index (Brute Force): " << strStrBruteForce(haystack, needle) << endl;
    cout << "Index (STL find): " << strStrSTL(haystack, needle) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Clarify what to return if needle is empty (usually 0).
 * - Mention that O(N*M) is acceptable for most basic interviews, 
 *   but KMP/Rabin-Karp are the "pro" answers.
 */
