#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int prime(int);
int main()
{
	int input_1;
	int input_2;

	cin >> input_1;
	cin >> input_2;

	for (int i = input_1; i <= input_2; i++)
	{
		if (prime(i) == 1)
			cout << i << "\n";
	}

	return 0;
}
int prime(int num)
{
	int i;
	if (num == 1)
		return 0;

	for (i = 2; i*i <= num; i++)
	{
		if (num%i == 0)
			return 0;
	}
	return 1;
}