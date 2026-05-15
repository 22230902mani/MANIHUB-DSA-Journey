/**
 * Problem: Reverse Words in Sentence
 * ----------------------------------
 * Given an input string s, reverse the order of the words.
 * 
 * Example:
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * Input: "  hello world  "
 * Output: "world hello"
 * 
 * Note: Your reversed string should not contain leading or trailing spaces.
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * Approach 1: Using stringstream and vector
 * -----------------------------------------
 * Simple and clean using C++ streams.
 */
string reverseWordsSTL(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    reverse(words.begin(), words.end());
    
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) result += " ";
    }
    return result;
}

/**
 * Approach 2: In-place Reversal
 * ----------------------------
 * 1. Reverse the whole string.
 * 2. Reverse each word individually.
 * 3. Clean up spaces.
 * 
 * This is more space-efficient (O(1) extra space excluding result).
 */
void reverseRange(string &s, int i, int j) {
    while (i < j) swap(s[i++], s[j--]);
}

string reverseWordsInPlace(string s) {
    // Reverse the entire string
    reverse(s.begin(), s.end());
    
    int n = s.length();
    int idx = 0;
    
    for (int start = 0; start < n; start++) {
        if (s[start] != ' ') {
            // Found start of a word
            if (idx != 0) s[idx++] = ' '; // Add space between words
            
            int end = start;
            while (end < n && s[end] != ' ') {
                s[idx++] = s[end++];
            }
            
            // Reverse the current word
            reverseRange(s, idx - (end - start), idx - 1);
            start = end;
        }
    }
    
    s.erase(s.begin() + idx, s.end()); // Remove extra characters
    return s;
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);
    
    cout << "Reversed (STL): [" << reverseWordsSTL(s) << "]" << endl;
    cout << "Reversed (In-place logic): [" << reverseWordsInPlace(s) << "]" << endl;
    
    return 0;
}

/**
 * Interview Tips:
 * - Emphasize handling multiple spaces between words and leading/trailing spaces.
 * - Mention the O(1) space complexity of the two-reversal trick.
 * - stringstream is great for quick implementation, but in-place reversal shows deeper understanding.
 */
