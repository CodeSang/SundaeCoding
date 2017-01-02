#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
int main()
{
	int test_case;
	vector <int> input;
	int temp;
	int result_1=0;
	int result_2=0;
	int result_1_temp = 0;
	int result_2_temp = 0;
	int gap = 10000;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	int check_store[10001] = { 0, };

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

	for (int i = 0; i < test_case; i++)
	{
		for (int j = 1; j < input[i]; j++)
		{
			for (int k = 1; k < input[i]; k++)
			{
				if (check_store[j] + check_store[k] == input[i])
				{
					result_1_temp = check_store[j];
					result_2_temp = check_store[k];
					if (abs(result_2_temp - result_1_temp) < gap)
					{
						result_1 = result_1_temp;
						result_2 = result_2_temp;
						gap = abs(result_2_temp - result_1_temp);
					}
					
				}
			}
		}
		cout << result_1 << " " << result_2 << endl;
		result_1 = 0;
		result_2 = 0;
		gap = 10000;
	}


	return 0;
}