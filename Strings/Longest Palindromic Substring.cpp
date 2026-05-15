/**
 * Problem: Longest Palindromic Substring
 * -------------------------------------
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example:
 * Input: "babad"
 * Output: "bab" (or "aba")
 * 
 * Approaches:
 * 1. Brute Force: Check every substring (O(N^3)).
 * 2. Dynamic Programming: Store palindrome status of substrings (O(N^2) space).
 * 3. Expand Around Center: Check odd and even palindromes (O(N^2) time, O(1) space).
 * 4. Manacher's Algorithm: O(N) linear time.
 * 
 * Time Complexity: O(N^2) for Expand Around Center.
 * Space Complexity: O(1) extra space.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Approach: Expand Around Center
 * ------------------------------
 * A palindrome mirrors around its center. We can expand from each character 
 * (odd length) and between each character (even length).
 */
string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = s.substr(0, 1);
    
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindromes (center is at i)
        string p1 = expandAroundCenter(s, i, i);
        if (p1.length() > longest.length()) {
            longest = p1;
        }
        
        // Even length palindromes (center is between i and i+1)
        string p2 = expandAroundCenter(s, i, i + 1);
        if (p2.length() > longest.length()) {
            longest = p2;
        }
    }
    
    return longest;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Mention Dynamic Programming if asked for state-based thinking.
 * - Mention Manacher's Algorithm for O(N) complexity as a "bonus" knowledge.
 * - Always handle the empty string case.
 */
