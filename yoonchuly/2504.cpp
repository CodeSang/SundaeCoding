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

			if (str[i + 1] == ')')//��ȣ�� �ٷ� ������ result�� ������� ���Ѱ� ���ϱ�
				result += mul;
		}
		else if (str[i] == '[') {
			mul *= 3;
			st.push(str[i]);

			if (str[i + 1] == ']')
				result += mul;
		}
		else if (!st.empty() && str[i] == ')')//������ ���̰�, ��ȣ�� ������ mul ������� �ϱ� ���ƿ���
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