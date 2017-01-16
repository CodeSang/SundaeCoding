#include <iostream>
#include <vector>
using namespace std;

//피보나치?
vector<int> tyle;
int fibonaci(int );
int main()
{
	for (int i = 0; i < 1001; i++)
	{
		tyle.push_back(0);
	}
	tyle[1] = 1;
	tyle[2] = 2;
	int n;
	cin >> n;

	if (n == 1)
		cout << 1 << endl;
	else if (n == 2)
		cout << 2 << endl;
	else
		cout << fibonaci(n)%10007 << endl;


	return 0;
}


int fibonaci(int n)
{
	if (tyle[n] == 0)
	{
		return tyle[n] = (fibonaci(n - 1)+ fibonaci(n - 2)) %10007;
	}
	else
		return tyle[n];
}