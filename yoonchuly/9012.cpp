#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	int test_case;
	string input;
	vector <string> store;
	stack <char> check;
	int check_temp=0;
	bool fail = false;

	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> input;
		store.push_back(input);
	}

	for (int i = 0; i < test_case; i++)
	{
		for (int j = 0; j < store[i].size(); j++) //check ���ٰ� �ֱ�
		{
			check.push(store[i][j]);
		}

		while (check.size() != 0) // check ������ ��ŭ Ȯ���ϸ鼭 ����
		{
			if (check.top() == ')')
			{
				check_temp++;
				check.pop();
			}
			else if (check.top() = '(')
			{
				check_temp--;
				check.pop();
			}
			if (check_temp < 0) // ���ÿ��� ���� ���ϱ� (�� �� ������
			{
				fail = true;
				//�߰��� �����Ƿ� �� �����
				while (check.size() != 0)
				{
					check.pop();
				}
			}
		}

	
		if ((check_temp == 0) && (fail == false))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		check_temp = 0;
		fail = false;
		
	}

	return 0;
}