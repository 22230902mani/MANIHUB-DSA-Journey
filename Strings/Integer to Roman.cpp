/**
 * Problem: Integer to Roman
 * -------------------------
 * Given an integer, convert it to a roman numeral.
 * 
 * Range: 1 to 3999 (standard Roman numeral constraints)
 * 
 * Example:
 * Input: 1994
 * Output: "MCMXCIV"
 * 
 * Approaches:
 * 1. Using Value Mapping (Arrays)
 * 2. Greedy Approach
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Approach: Greedy Approach
 * -------------------------
 * We store the mapping of values to their Roman symbols in descending order.
 * We subtract the largest possible value and append its symbol until the number becomes zero.
 */
string intToRoman(int num) {
    // Define the mappings in descending order
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string result = "";
    
    for (auto const& [value, symbol] : roman) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }
    
    return result;
}

int main() {
    int num;
    cout << "Enter an integer (1-3999): ";
    cin >> num;
    
    if (num < 1 || num > 3999) {
        cout << "Out of range!" << endl;
        return 0;
    }
    
    cout << "Roman Numeral: " << intToRoman(num) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Explain why we include 'subtractive' cases (like IV, IX) in our mapping.
 * - Time Complexity: O(1) because the input range is fixed (max iterations is constant).
 * - Space Complexity: O(1) for the mapping.
 */
