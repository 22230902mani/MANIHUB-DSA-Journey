/**
 * Problem: Longest Substring Without Repeating Characters
 * ------------------------------------------------------
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example:
 * Input: "abcabcbb"
 * Output: 3 ("abc")
 * 
 * Approaches:
 * 1. Sliding Window with Set: O(2N)
 * 2. Optimized Sliding Window with Map/Index Array: O(N)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Approach: Optimized Sliding Window
 * ---------------------------------
 * Use a map (or array) to store the last seen index of each character.
 * When a character repeats, move the left pointer to max(left, lastSeenIndex + 1).
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(min(m, n)) where m is character set size.
 */
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    int left = 0;
    
    // lastIndex[char] stores the index after the last occurrence of char
    vector<int> lastIndex(256, -1);
    
    for (int right = 0; right < n; right++) {
        if (lastIndex[s[right]] != -1) {
            // Jump left pointer to avoid the repeated character
            left = max(left, lastIndex[s[right]] + 1);
        }
        
        lastIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    
    cout << "Length of Longest Substring Without Repeating Characters: " 
         << lengthOfLongestSubstring(s) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Explain why `max(left, lastIndex + 1)` is used instead of just `lastIndex + 1`.
 * - Discuss character set size (ASCII 256 vs Extended ASCII vs Unicode).
 * - Show both the Set approach (easier) and Optimized Map approach (better).
 */
