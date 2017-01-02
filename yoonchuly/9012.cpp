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
		for (int j = 0; j < store[i].size(); j++) //check 에다가 넣기
		{
			check.push(store[i][j]);
		}

		while (check.size() != 0) // check 사이즈 만큼 확인하면서 증가
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
			if (check_temp < 0) // 스택에서 빼다 보니깐 (가 더 많아짐
			{
				fail = true;
				//중간에 빠지므로 다 비워줌
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