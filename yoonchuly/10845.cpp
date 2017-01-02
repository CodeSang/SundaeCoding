#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int main()
{

	queue <int> q;
	int test_case = 0;
	string command;
	int push_num = 0;
	int pop_temp = 0;

	cin >> test_case;


	for (int i = 0; i < test_case; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> push_num;
			q.push(push_num);
		}
		else if (command == "pop")
		{
			if (q.empty())
				cout << "-1" << endl;
			else {
				pop_temp = q.front();
				q.pop();
				cout << pop_temp << endl;
			}
		}
		else if (command == "size")
		{
			cout << q.size() << endl;
		}
		else if (command == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (command == "front")
		{
			if (q.empty())
				cout << "-1" << endl;
			else {
				cout << q.front() << endl;
			}
		}
		else if (command == "back")
		{
			if (q.empty())
				cout << "-1" << endl;
			else {
				cout << q.back() << endl;
			}
		}

	}
	return 0;

}