#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int prime(int);
int main()
{
	int temp =1;
	vector<int> input;
	int result = 0;

	while (true)
	{
		cin >> temp;
		if (temp == 0)
			break;

		input.push_back(temp);
	}


	for (int i = 0; i < input.size(); i++)
	{
		temp = 2 * input[i];
		for (int j = input[i]+1; j <= temp; j++)
		{
			if (prime(j) == 1)
				result++;
		}
		cout << result << endl;
		result = 0;
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