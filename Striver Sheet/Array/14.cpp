#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]

*/

vector<string> commonChars(vector<string> &words)
{
    // we make another min_freq map in which we store initially all elements having max frequency from a to z
    // what we are doing is we are making an unordered_map to store frequency of all characters inside each element of words
    // we then check min_frequency of each element, this way we get each element common
    unordered_map<char, int> min_frequency;
    vector<string> ans;

    // store min_frequency of all elements with max value
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        // storing max posible value
        min_frequency[ch] = 1000;
    }

    // Now go inside each element of words
    for (auto word : words)
    {
        unordered_map<char, int> frequency;
        // store frequency of each word
        for (auto ch : word)
        {
            frequency[ch]++;
        }

        // update the min_freq map for all elements from a to z
        for (auto ch = 'a'; ch <= 'z'; ch++)
        {
            min_frequency[ch] = min(min_frequency[ch], frequency[ch]);
        }
    }
    // store all elements back to answer vector based on common count
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        while (min_frequency[ch] > 0)
        {
            // to store char -> string we use string constructor
            ans.push_back(string(1, ch));
            min_frequency[ch]--;
        }
    }

    return ans;
}

int main()
{
    return 0;
}
