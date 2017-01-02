#include<iostream>
#include<string>
#include<stack>
using namespace std;


struct Sang {
	int integer;
	char character;
};
int main() {
	string str;
	cin >> str;

	int len = str.length();
	stack<Sang> s;
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '[' || str[i] == '(')
			s.push({ 0,str[i] });
		else
		{
			if (str[i] == ']')
			{
				int temp = 0;
				while (!s.empty())
				{
					auto iter = s.top();
					s.pop();

					if (iter.character == '[')
					{
						if (temp == 0)
							s.push({3, '*'});
						else
							s.push({ temp*3, '*' });
						break;
					}
					else if (iter.integer != 0)
					{
						temp += iter.integer;
					}
					else
					{

						cout << "0" << endl;
						return 0;
					}
				}
			}
			else
			{
				int temp = 0;
				while (!s.empty())
				{
					auto iter = s.top();
					s.pop();

					if (iter.character == '(')
					{
						if (temp == 0)
							s.push({ 2, '*' });
						else
							s.push({ temp * 2, '*' });
						break;
					}
					else if (iter.integer != 0)
					{
						temp += iter.integer;
					}
					else
					{

						cout << "0" << endl;
						return 0;
					}
				}
			}

		}
	}


	while (!s.empty())
	{
		auto iter = s.top();
		s.pop();

		if (iter.integer == 0)
		{
			cout << "0" << endl;
			return 0;
		}
		cnt += iter.integer;
	}
	cout << cnt << endl;
	return 0;
}