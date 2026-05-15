/**
 * Problem: Remove Duplicates from String
 * -------------------------------------
 * Given a string, remove all duplicate characters while maintaining the original order.
 * 
 * Example:
 * Input: "programming"
 * Output: "progamin"
 * 
 * Approaches:
 * 1. Using a Hash Set / Frequency Array (Best for Order Preservation)
 * 2. Sorting (Changes order, but good for count/check)
 * 3. In-place using a boolean array (Time: O(N), Space: O(1) for ASCII)
 * 
 * Time Complexity: O(N) where N is the length of the string.
 * Space Complexity: O(1) as we use a fixed-size array/set for 256 ASCII characters.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * Approach 1: Using an Unordered Set
 * ----------------------------------
 * We iterate through the string and keep track of seen characters.
 * If a character hasn't been seen, we add it to the result and mark it as seen.
 */
string removeDuplicatesSet(string s) {
    unordered_set<char> seen;
    string result = "";
    
    for (char c : s) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

/**
 * Approach 2: Using a Frequency Array (Optimized Space)
 * ---------------------------------------------------
 * Since characters are usually ASCII, we can use a boolean array of size 256.
 * This is more space-efficient than an unordered_set.
 */
string removeDuplicatesEfficient(string s) {
    vector<bool> seen(256, false);
    string result = "";
    
    for (char c : s) {
        if (!seen[(unsigned char)c]) {
            seen[(unsigned char)c] = true;
            result += c;
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    cout << "Original: " << input << endl;
    
    // Using Set Approach
    cout << "After removing duplicates (Set): " << removeDuplicatesSet(input) << endl;
    
    // Using Frequency Array Approach
    cout << "After removing duplicates (Efficient): " << removeDuplicatesEfficient(input) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Clarify if the order needs to be maintained.
 * - Ask if the string contains only lowercase, uppercase, or any ASCII/Unicode characters.
 * - Mention that using a frequency array is O(1) space if the character set is finite (like ASCII).
 */
