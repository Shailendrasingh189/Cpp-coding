#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// reverse string - using string in C++

int main()
{
    string str = "apna college.";
    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}