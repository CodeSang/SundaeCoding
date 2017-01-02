#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	int check_store[10001] = { 0, };
	int sum =0;
	int min_result =0;

	int input_1;
	int input_2;

	cin >> input_1;
	cin >> input_2;

	for (int i = 2; i <= 10000; i++)
	{
		check_store[i] = i;
	}

	for (int i = 2; i <= 10000; i++)
	{
		for (int j = 2; j <= 10000; j++)
		{
			if (check_store[j] != i && check_store[j] % i == 0)//자신과 같지 않고 나머지가 0이면 소수 아님
			{
				check_store[j] = 0;
			}
		}
	}

	int temp = 0;
	temp = input_1 - input_2;
	for (int i = input_1; i <= input_2; i++)
	{
		if (check_store[i] != 0)
		{
			min_result = check_store[i];
			break;
		}
	}

	if (min_result == 0)
	{
		cout << "-1" << endl;
		return 0;
	}

	for (int i = input_1; i <= input_2; i++)
	{
		sum += check_store[i];
	}

	cout << sum << endl;
	cout << min_result << endl;

	return 0;
}