/**
 * Problem: String Compression
 * --------------------------
 * Given an array of characters, compress it in-place.
 * The length after compression must always be smaller than or equal to the original array.
 * 
 * Example:
 * Input: ["a","a","b","b","c","c","c"]
 * Output: ["a","2","b","2","c","3"]
 * 
 * Input: ["a","b","1","2"] (no compression)
 * Output: ["a","b","1","2"]
 * 
 * Note: If count is 1, don't append the number.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Approach: Two Pointers
 * ---------------------
 * One pointer (i) to iterate through the input.
 * Another pointer (write) to update the array in-place.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1) - in-place modification
 */
int compress(vector<char>& chars) {
    int n = chars.size();
    int write = 0;
    int i = 0;
    
    while (i < n) {
        char currentChar = chars[i];
        int count = 0;
        
        // Count occurrences of currentChar
        while (i < n && chars[i] == currentChar) {
            i++;
            count++;
        }
        
        // Write the character
        chars[write++] = currentChar;
        
        // Write the count if it's > 1
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }
    }
    
    return write; // New length
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    
    vector<char> chars(n);
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }
    
    int newLen = compress(chars);
    
    cout << "Compressed String: ";
    for (int i = 0; i < newLen; i++) {
        cout << chars[i];
    }
    cout << endl;
    cout << "New length: " << newLen << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Emphasize the "in-place" constraint.
 * - Handle cases where count > 9 (converting count to string).
 * - Edge case: Single character strings.
 */
