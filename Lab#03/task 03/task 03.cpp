#include <iostream>
using namespace std;

string Prime(int x, int y)
{
  
    if (x <= 1)  //For 1,0 and negative numbers (They are neither composite nor prime)
    {
        return "neither composite nor prime";
    }
    
    if (y == 1) //This determines if a divisor other than 1 or the number itself is found
    {
        return "Prime";
    }
    if (x % y == 0) //To check the remainder 
    {
        return "not Prime";
    }
    return Prime(x, y - 1); //recursion
}

int main()
{
    int x;
    cout << "Enter a number : ";
    cin >> x;
    cout <<"\nThe Entered number is : "<< Prime(x, x - 1) << endl;
    return 0;
}
