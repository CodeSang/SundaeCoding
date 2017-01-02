#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int num;
	int del_num;
	int temp;

	queue <int> input;
	vector <int> result;

	cin >> num;
	cin >> del_num;

	for (int i = 0; i < num; i++)
	{
		input.push(i+1);
	}

	while (!input.empty())
	{
		for (int i = 0; i < del_num-1; i++)
		{
			temp = input.front();
			input.pop();
			input.push(temp);
		}
		temp = input.front();
		input.pop();
		result.push_back(temp);

	}
	cout << "<";
	for (int i = 0; i < result.size()-1; i++)
	{
		cout << result[i] << ", ";
	}
	cout << result[result.size()-1] << ">" << endl;


	return 0;
}