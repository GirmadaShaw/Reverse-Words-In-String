/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at
least one space. Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. Do not include any
extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

*/

#include <iostream>
#include <string>
using namespace std ;

string reverse(string s, bool flag)
{
    string temp = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        temp += s[i];
    }
    if (flag == false)
        return temp;
    else
    {
        temp += " ";
    }
    return temp;
}

string reverseWords(string s)
{
    bool flag = false;
    int m = 0, n = s.length() - 1, startIndex = m, endIndex = n;

    while (isspace(s[m]))
    {
        m++;
        startIndex = m;
    }
    while (isspace(s[n]))
    {
        n--;
        endIndex = n;
    }

    string temp = "", str = "";

    for (int i = endIndex; i >= startIndex; i--)
    {
        if (!isspace(s[i]))
        {
            temp += s[i];
        }
        else
        {
            flag = true;
            while (isspace(s[i - 1]))
            {
                i--;
            }
            endIndex = i;
            str += reverse(temp, flag);
            temp = "";
        }
    }
    if (!flag)
        return reverse(temp, flag);
    for (int i = startIndex; i < endIndex; i++)
        str += s[i];
    return str;
}

int main()
{

    string s = "the sky is blue" ;
    cout << reverseWords( s ) ; 
}