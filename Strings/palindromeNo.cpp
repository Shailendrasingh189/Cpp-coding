#include <iostream>
#include <limits.h>
using namespace std;

int reverseNo(int n)
{
    int revNum = 0;

    while (n != 0)
    {
        int dig = n % 10;
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
            return 0;
        revNum = revNum * 10 + dig;
        n = n / 10;
    }
    return revNum;
}

bool isPalindrome(int n) {
    if(n < 0) return false; 

    int revNum = reverseNo(n); 
    return revNum == n;
}

int main () {
    int n = 62456;

    cout << "The number is palindrome : " << isPalindrome(n) << endl; 

    return 0;
}