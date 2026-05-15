/**
 * Problem: String Permutations
 * ---------------------------
 * Given a string, print all permutations of it.
 * 
 * Example:
 * Input: "ABC"
 * Output: "ABC", "ACB", "BAC", "BCA", "CBA", "CAB"
 * 
 * Approaches:
 * 1. Backtracking (Swapping characters)
 * 2. STL's next_permutation
 * 
 * Time Complexity: O(N * N!) where N is length.
 * Space Complexity: O(N) for recursion depth.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Approach 1: Backtracking (Swapping)
 * ----------------------------------
 * Fix each character at the current index and permute the rest.
 */
void permute(string& s, int left, int right) {
    if (left == right) {
        cout << s << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(s[left], s[i]);
            permute(s, left + 1, right);
            swap(s[left], s[i]); // Backtrack
        }
    }
}

/**
 * Approach 2: Using STL next_permutation
 * -------------------------------------
 * Requires the string to be sorted initially.
 */
void permuteSTL(string s) {
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    cout << "--- Permutations (Backtracking) ---" << endl;
    permute(s, 0, s.length() - 1);
    
    cout << "\n--- Permutations (STL) ---" << endl;
    permuteSTL(s);
    
    return 0;
}

/**
 * Interview Tips:
 * - Discuss how to handle duplicate characters (using a set or sorting).
 * - Complexity analysis is important: Why N!? (N options for 1st char, N-1 for 2nd...).
 * - Mention that for very long strings, this is infeasible.
 */
