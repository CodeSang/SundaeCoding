#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	stack <int> result;
	int test = 0;
	string command;
	int push_num = 0;
	int pop_temp = 0;

	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> push_num;
			result.push(push_num);
		}
		else if (command == "top")
		{
			if (result.empty())
				cout << "-1" << endl;
			else {
				cout << result.top() << endl;
			}
		}
		else if (command == "pop")
		{
			if(result.empty())
				cout << "-1" << endl;
			else{
				pop_temp = result.top();
				result.pop();
				cout << pop_temp << endl;
			}
		}
		else if (command == "size")
		{
			cout << result.size() << endl;
		}
		else if (command == "empty")
		{
			cout << result.empty() << endl;
		}
	}


	return 0;
}