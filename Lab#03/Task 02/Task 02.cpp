#include <iostream>
using namespace std;

int BinomialCoefficient(int n, int k)
{
	if (k == 0 || n == k) //base case for c(n,0) and c(n,n) 
	{
		return 1;
	}
	if(n > 0) //to handle negative n 
	{
		if (k > n) //case for binomial coefficient property 
		{
			return 0;
		}
		return BinomialCoefficient(n - 1, k - 1) + BinomialCoefficient(n - 1, k);  //recursion if the base cases are not satisfied
	}
	else
	{
		return -1; //to make the negative error handling possible/easy
	}
}
		
int main()
{
	int n, k;
	cout << "Enter Value of 'n' : ";
	cin >> n;
	cout << "Enter Value of 'k' : ";
	cin >> k;
	int result = BinomialCoefficient(n, k);
	if (result != -1) //To check if the number entered was negative and give the output as required
	{
		cout << "The value of C(" << n << ", " << k << ") is " << result;
	}
	else
	{
		cout << "\n'n' cannot be negative";
	}
	return 0;
}