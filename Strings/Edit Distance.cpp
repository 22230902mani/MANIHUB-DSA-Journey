/**
 * Problem: Edit Distance (Levenshtein Distance)
 * -------------------------------------------
 * Given two strings s1 and s2, return the minimum number of operations 
 * required to convert s1 to s2.
 * 
 * Operations:
 * 1. Insert a character
 * 2. Delete a character
 * 3. Replace a character
 * 
 * Example:
 * s1 = "horse", s2 = "ros"
 * Output: 3
 * (horse -> rorse -> rose -> ros)
 * 
 * Time Complexity: O(M * N)
 * Space Complexity: O(M * N)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Approach: Dynamic Programming
 * -----------------------------
 * dp[i][j] = min operations to convert s1[0...i-1] to s2[0...j-1].
 * 
 * If characters match: dp[i][j] = dp[i-1][j-1]
 * Else: dp[i][j] = 1 + min({
 *    dp[i-1][j],    // Delete
 *    dp[i][j-1],    // Insert
 *    dp[i-1][j-1]   // Replace
 * })
 */
int minDistance(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    
    cout << "Minimum Edit Distance: " << minDistance(s1, s2) << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - This is a fundamental DP problem.
 * - Mention applications like spell checkers, DNA sequence alignment.
 * - Mention space optimization to O(N) using only two rows.
 */
