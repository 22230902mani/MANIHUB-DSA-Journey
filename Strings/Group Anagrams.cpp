/**
 * Problem: Group Anagrams
 * ----------------------
 * Given an array of strings, group the anagrams together.
 * You can return the answer in any order.
 * 
 * Example:
 * Input: ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * Approaches:
 * 1. Sorting each string and using a HashMap: O(N * K log K)
 * 2. Frequency counting and using a HashMap: O(N * K)
 * 
 * where N is number of strings and K is max length of a string.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Approach: Sorting as Key
 * -----------------------
 * Anagrams, when sorted, result in the same string.
 * We use this sorted string as a key in a hash map.
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto const& [key, group] : groups) {
        result.push_back(group);
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    
    vector<string> strs(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    vector<vector<string>> result = groupAnagrams(strs);
    
    cout << "Grouped Anagrams:" << endl;
    for (auto const& group : result) {
        cout << "[ ";
        for (string s : group) {
            cout << s << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/**
 * Interview Tips:
 * - Mention that sorting is easier to implement but O(N * K log K).
 * - Frequency array (size 26 for lowercase) converted to a string key is O(N * K).
 * - Explain why `unordered_map` is used for O(1) average lookup.
 */
