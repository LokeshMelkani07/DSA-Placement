#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// Character array or String
int get_Length(char name[])
{
    int count = 0;
    for(int i = 0;name[i]!= '\0';i++)
    {
        count++;
    }

    return count;
}

// Reverse a string
void reverse_string(char name[],int length)
{
    int s = 0;
    int e = length-1;
    while(s<e)
    {
        swap(name[s++],name[e--]);
    }
}

// Check string is palindrome or not
// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.
void toLowerCase(string &s)
{
    // Traverse through the string s
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // Check if ch is a uppercase letter
        if (ch <= 'Z' && ch >= 'A')
        {
            ch = ch - ('A' - 'a');
            s[i] = ch;
        }
    }
}

// This function reverse the string s
string reverseString(string s)
{
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
    {
        // Swap the ith and jth characters.
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    return s;
}

bool checkPalindrome(string s)
{
    // Convert uppercase letter into lowercase letter
    toLowerCase(s);

    // Find the reverse string of s
    string reversedS = reverseString(s);

    int n = s.length();
    int i = 0;
    int j = 0;

    while (i < n && j < n)
    {
        if (isalnum(s[i]) == 0)
        {
            // ith pointer points to invalid character.
            ++i;
        }
        else if (isalnum(reversedS[j]) == 0)
        {
            // jth pointer points to invalid character.
            ++j;
        }
        else if (s[i] == reversedS[j])
        {
            ++i;
            ++j;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// key difference between character array and string
// String is implemented to store sequence of characters and to be represented as a single data type and single entity. Character Array on the other hand is a sequential collection of data type char where each element is a separate entity.


// Max occuring character in a string
//Function to find the maximum occurring character in a string.
char getMaxOccuringChar(string str)
{
        int arr[26] = {0};

        for(int i = 0;i<str.length();i++)
        {
            char ch = str[i];
            int number = 0;
            if(ch<='z' && ch>='a')
            {
                number = ch - 'a';
            }
            else{
                number = ch - 'A';
            }
            arr[number]++;
        }

        int maxi = -1;
        int ans = 0;
        for(int i = 0;i<26;i++)
        {
            if(maxi<arr[i])
            {
                ans = i;
                maxi = arr[i];
            }
        }

        return 'a' + ans;
}

// Replace Spaces
// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
string replaceSpaces(string &str){
	string temp = "";
	for(int i = 0;i<str.length();i++)
	{
		if(str[i]==' ')
		{
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');
		}
		else{
			temp.push_back(str[i]);
		}
	}
	return temp;
}

// Remove All Occurrences of a Substring
/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
*/

string removeOccurrences(string s, string part)
{
        while(s.length() != 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s;
}

// Permutation in String
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.In other words, return true if one of s1's permutations is the substring of s2.

bool checkEqual(int arr1[26],int arr2[26])
{
        for(int i = 0;i<26;i++)
        {
            if(arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
}
bool checkInclusion(string s1, string s2)
{
        int arr1[26] = {0};
        for(int i = 0;i<s1.length();i++)
        {
            int index = s1[i] - 'a';
            arr1[index]++;
        }

        int i = 0;
        int windowSize = s1.length();
        int arr2[26] = {0};
        while(i<windowSize && i<s2.length())
        {
            int index = s2[i] - 'a';
            arr2[index]++;
            i++;
        }

        if(checkEqual(arr1,arr2))
        {
            return 1;
        }

        while(i<s2.length())
        {
            int newChar = s2[i] - 'a';
            arr2[newChar]++;
            char oldChar = s2[i - windowSize];
            int oldIndex = oldChar - 'a';
            arr2[oldIndex]--;
            i++;

            if(checkEqual(arr1,arr2))
            {
                return 1;
            }
        }

        return 0;

}

// Remove All Adjacent Duplicates In String
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.We repeatedly make duplicate removals on s until we no longer can.Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
string removeDuplicates(string s) {
        string ans;
        ans.push_back(s[0]);

        for(int i = 1;i<s.length();i++)
        {
            if(s[i] == ans.back())
            {
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
}

// String Compression
/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/
int compress(vector<char>& chars)
{
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        while(i<n)
        {
            int j = i+1;
            while(j<n && chars[i] == chars[j])
            {
                j++;
            }

            // old char stored
            chars[ansIndex++] = chars[i];
            int count = j-i;

            if(count>1)
            {
                string cnt = to_string(count);
                for(char ch: cnt)
                {
                    chars[ansIndex++] = ch;
                }

            }
            i=j;
        }

        return ansIndex;
}

int main()
{
    // null character means string is ending here
    // '\0' is NULL character
    // cin stops working as it sees space, tab, newline
    char name[10];
    cout<<"Enter your name"<<endl;
    cin>>name;

    cout<<"Your name is "<<endl;
    cout<<name<<endl;

    // Length of string
    cout<<"Count of string is "<<get_Length(name)<<endl;

    // Reverse a string
    int length = get_Length(name);
    reverse_string(name,length);
    cout<<"Reversed string is "<<name<<endl;


    return 0;
}