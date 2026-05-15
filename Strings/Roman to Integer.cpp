/**
 * Problem: Roman to Integer
 * -------------------------
 * Given a roman numeral, convert it to an integer.
 * 
 * Roman Numerals:
 * I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
 * 
 * Subtraction Rules:
 * I before V or X (IV = 4, IX = 9)
 * X before L or C (XL = 40, XC = 90)
 * C before D or M (CD = 400, CM = 900)
 * 
 * Example:
 * Input: "LVIII"
 * Output: 58
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * Approach: Linear Scan with Lookahead
 * -----------------------------------
 * We iterate through the string. If the current value is less than the 
 * next value, it means we subtract the current from the next (e.g., IV).
 * Otherwise, we just add it.
 */
int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        // If current value is less than next value, subtract current from result
        if (i < n - 1 && roman[s[i]] < roman[s[i+1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    
    return result;
}

int main() {
    string s;
    cout << "Enter a Roman Numeral: ";
    cin >> s;
    
    cout << "Integer value: " << romanToInt(s) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Mention that scanning from right to left can also work and might be slightly cleaner for some.
 * - Handle invalid characters if necessary (though usually the input is guaranteed valid in LC).
 * - Space complexity is O(1) because the map size is constant (7 symbols).
 */
