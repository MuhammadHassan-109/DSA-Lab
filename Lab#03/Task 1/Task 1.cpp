#include <iostream>

using namespace std;



void recursiveNumberPrinting(int n)
{
    if (n == 0) //base case 
    {
        cout << n << " ";
        return;
    }   
    if (n > 0) //recursive case for positive numbers
    {
        cout << n << " ";
        recursiveNumberPrinting(n - 1);
    }
    else //recursive case for negative numbers
    {
        cout << n << " ";
        recursiveNumberPrinting(n + 1);
    }
}


int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    recursiveNumberPrinting(n);
    return 0;
}
