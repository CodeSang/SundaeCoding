#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	stack<int> store;
	int max = 0;
	int test_case = 0;
	vector<int> input;
	vector<int> num;
	int temp;

	cin >> test_case;


	for (int i = 0; i < test_case; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	for (int i = 1; i <= test_case; i++)//1~test_case 넣은 벡터
	{
		num.push_back(i);
	}


		while (!num.empty()) // 1~test_case 의 값들이 다 없어질때 까지
		{
			for (int i = 0; i < input.size(); i++)
			{
				if (input[i] > max)
				{

				}
			}
		}

	return 0;
}