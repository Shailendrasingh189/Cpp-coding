#include <iostream>
#include <vector>
using namespace std;
//reverse string - using character arrays

int main()
{
    vector<char> str = {'s', 'h', 'a', 'i', 'l', 'e', 'n', 'd', 'r', 'a'};

    int n = str.size();
    int st = 0, end = n - 1;

    while (st < end)
    {
        swap(str[st++], str[end--]);
    }

    for (int i = 0; i < str[i] != '\0'; i++)
    {
        cout << str[i] << "";
    }
    cout << endl;

    return 0;
}