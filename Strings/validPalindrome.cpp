#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//valid palindrome TC - O(n) SC - O(1)

bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isValidPalindrome(string s)
{
    int st = 0, end = s.length() - 1;

    while (st < end)
    {
        if (!isAlphaNum(s[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNum(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main()
{
    string s = "Ac3?e3c&a";

    cout << "is valid Palindrome :" << isValidPalindrome(s) << endl;
}