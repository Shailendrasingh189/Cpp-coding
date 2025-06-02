#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.size() == 0)
            {
                return false; // Stack is empty, no matching opening bracket
            }
            if (st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']')
            {
                st.pop(); // match found
            }
            else
            {
                return false; // Mismatched brackets
            }
        }
    }
    return st.size() == 0; // If stack is empty, all brackets matched
}

int main()
{
    string s1 = "()[]{}";
    string s2 = "({}]";

    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;

    return 0;
}