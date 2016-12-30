#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main() {

	int N;
	stack<int> stack_;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int temp;
			cin >> temp;
			stack_.push(temp);
		}
		else if (str == "pop")
		{
			if (stack_.empty()) cout << "-1" << endl;
			else {
				cout << stack_.top() << endl;
				stack_.pop();
			}
		}
		else if (str == "top")
		{
			if (stack_.empty()) cout << "-1" << endl;
			else cout << stack_.top() << endl;
		}
		else if (str == "empty")
		{
			cout << stack_.empty() << endl;
		}
		else if (str == "size")
		{
			cout << stack_.size() << endl;
		}
	}
}