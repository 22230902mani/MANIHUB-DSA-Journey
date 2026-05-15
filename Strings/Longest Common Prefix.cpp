/**
 * Problem: Longest Common Prefix
 * -----------------------------
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * 
 * Example:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Approaches:
 * 1. Horizontal Scanning: Compare strings one by one.
 * 2. Vertical Scanning: Compare character by character across all strings.
 * 3. Sorting: Sort the array and compare the first and last string.
 * 4. Divide and Conquer / Binary Search.
 * 
 * Time Complexity: O(S) where S is the sum of all characters in all strings.
 * Space Complexity: O(1) extra space.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Approach 1: Sorting
 * ------------------
 * After sorting, the longest common prefix must be common to the first and last string.
 * Time: O(N * L log N) where N is number of strings and L is max length.
 */
string longestCommonPrefixSorting(vector<string>& strs) {
    if (strs.empty()) return "";
    
    sort(strs.begin(), strs.end());
    
    string first = strs[0];
    string last = strs[strs.size() - 1];
    string result = "";
    
    for (int i = 0; i < min(first.size(), last.size()); i++) {
        if (first[i] == last[i]) {
            result += first[i];
        } else {
            break;
        }
    }
    return result;
}

/**
 * Approach 2: Vertical Scanning
 * ----------------------------
 * Compare characters at the same index across all strings.
 * Time: O(S) where S is the total number of characters.
 */
string longestCommonPrefixVertical(vector<string>& strs) {
    if (strs.empty()) return "";
    
    for (int i = 0; i < strs[0].length(); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i == strs[j].length() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    
    vector<string> strs(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    // Testing both approaches
    cout << "LCP (Sorting Approach): " << longestCommonPrefixSorting(strs) << endl;
    cout << "LCP (Vertical Approach): " << longestCommonPrefixVertical(strs) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Vertical scanning is often better in practice because it stops early.
 * - Mention Trie as a data structure alternative if multiple LCP queries are needed.
 */
