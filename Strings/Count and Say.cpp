/**
 * Problem: Count and Say
 * ----------------------
 * The count-and-say sequence is a sequence of digit strings defined by 
 * the recursive formula:
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1).
 * 
 * Example:
 * n = 4
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" -> "11" (one 1)
 * countAndSay(3) = say "11" -> "21" (two 1s)
 * countAndSay(4) = say "21" -> "1211" (one 2, then one 1)
 * 
 * Input: n = 4
 * Output: "1211"
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Approach: Iterative Construction
 * -------------------------------
 * Generate each sequence based on the previous one.
 */
string countAndSay(int n) {
    if (n == 1) return "1";
    
    string res = "1";
    for (int i = 2; i <= n; i++) {
        string nextRes = "";
        int len = res.length();
        
        for (int j = 0; j < len; j++) {
            int count = 1;
            // Count consecutive occurrences of same digit
            while (j + 1 < len && res[j] == res[j + 1]) {
                count++;
                j++;
            }
            nextRes += to_string(count) + res[j];
        }
        res = nextRes;
    }
    
    return res;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << "Count and Say (" << n << "): " << countAndSay(n) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Explain the recursive nature of the problem even if implementing iteratively.
 * - This is more of a simulation problem than a complex algorithm.
 * - Mention string concatenation efficiency in different languages (C++ strings are mutable, which is good).
 */
