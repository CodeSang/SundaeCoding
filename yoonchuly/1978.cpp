#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int check_store[1001] = {0,};
	int test_case;
	vector<int> check_num;
	int temp;
	int result=0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> temp;
		check_num.push_back(temp);
	}

	for (int i = 2; i <= 1000; i++)
	{
		check_store[i] = i;
	}

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			if (check_store[j] != i && check_store[j] % i == 0)//�ڽŰ� ���� �ʰ� �������� 0�̸� �Ҽ� �ƴ�
			{
				check_store[j] = 0;
			}
			cout << "1" << endl;
		}
	}

	for (int i = 0; i < check_num.size(); i++)
	{
		if (check_store[check_num[i]] != 0)
			result++;
	}

	cout << result << endl;

	return 0;
}