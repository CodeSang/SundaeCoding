#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	string str; 
	cin >> str;
	int result = 0;
	int mul = 1;
	stack<char> st;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			mul *= 2;
			st.push(str[i]);

			if (str[i + 1] == ')')//괄호가 바로 닫히면 result에 현재까지 곱한거 더하기
				result += mul;
		}
		else if (str[i] == '[') {
			mul *= 3;
			st.push(str[i]);

			if (str[i + 1] == ']')
				result += mul;
		}
		else if (!st.empty() && str[i] == ')')//스택이 쌓이고, 괄호가 닫히면 mul 원래대로 하기 돌아오기
		{
			mul /= 2;
			st.pop();
		}
		else if (!st.empty() && str[i] == ']')
		{
			mul /= 3;
			st.pop();
		}
	}

	if (st.empty())
		cout << result << endl;
	else
		cout << 0 << endl;


	return 0;
}