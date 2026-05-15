/**
 * Problem: Rabin Karp Algorithm (String Pattern Matching)
 * -----------------------------------------------------
 * Find all occurrences of a pattern P in a text T.
 * 
 * Concept:
 * Use a rolling hash to compare the hash of the pattern with hashes of 
 * substrings of the text. If hashes match, perform a character-by-character 
 * check (to handle collisions).
 * 
 * Time Complexity: 
 * - Average/Best Case: O(N + M)
 * - Worst Case: O(N * M) (if many hash collisions)
 * 
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define D 256 // Number of characters in the alphabet
#define Q 101 // A prime number for modulo

/**
 * Rabin-Karp Implementation
 */
void search(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(D, M-1) % Q"
    for (i = 0; i < M - 1; i++)
        h = (h * D) % Q;

    // Calculate the initial hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (D * p + pat[i]) % Q;
        t = (D * t + txt[i]) % Q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern. 
        // If the hash values match then only check for characters one by one
        if (p == t) {
            bool flag = true;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove leading digit, 
        // add trailing digit
        if (i < N - M) {
            t = (D * (t - txt[i] * h) + txt[i + M]) % Q;

            // We might get negative value of t, converting it to positive
            if (t < 0) t = (t + Q);
        }
    }
}

int main() {
    string txt, pat;
    cout << "Enter Text: ";
    getline(cin, txt);
    cout << "Enter Pattern: ";
    getline(cin, pat);
    
    search(pat, txt);
    
    return 0;
}

/**
 * Interview Tips:
 * - Explain rolling hash and why modulo arithmetic is important.
 * - Discuss spurious hits (collisions) and how to minimize them (better prime Q).
 * - Mention its usage in plagiarism detection and multiple pattern search.
 */
