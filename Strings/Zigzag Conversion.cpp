/**
 * Problem: Zigzag Conversion
 * -------------------------
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows:
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Example:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Approach: Row-by-Row Construction
 * --------------------------------
 * We use an array of strings, where each string represents a row.
 * We iterate through the original string and append characters to rows 
 * in a zigzag fashion (going down, then up).
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N) to store the rows.
 */
string convert(string s, int numRows) {
    if (numRows <= 1 || numRows >= s.length()) return s;
    
    vector<string> rows(numRows);
    int currentRow = 0;
    bool goingDown = false;
    
    for (char c : s) {
        rows[currentRow] += c;
        
        // Change direction when we hit the top or bottom row
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
        
        currentRow += goingDown ? 1 : -1;
    }
    
    string result = "";
    for (string row : rows) {
        result += row;
    }
    
    return result;
}

int main() {
    string s;
    int numRows;
    
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter number of rows: ";
    cin >> numRows;
    
    cout << "Zigzag Conversion: " << convert(s, numRows) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Mention the edge cases: numRows = 1 or numRows >= length.
 * - Visualize the zigzag as a "bouncing" movement between 0 and numRows-1.
 * - Space can be slightly optimized by calculating the index directly, but the row-based approach is much cleaner.
 */
