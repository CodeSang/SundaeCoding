#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	string input;
	int alpha[26] = { 0, };
	int temp = 0;
	int result = 0;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		char c = input[i];
		temp = (c >= 'a') ? c - 'a' : c - 'A';
		alpha[temp]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > result)
		{
			temp = i;
			result = alpha[i];
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == result && i != temp)
		{
			cout << "?" << endl;
			return 0;
		}
	}

	cout << char(temp+'A') << endl;
	return 0;
}