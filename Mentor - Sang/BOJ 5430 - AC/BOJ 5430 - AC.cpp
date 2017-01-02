#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
using namespace std;

int main() {

	int T; 
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		char temp;
		int  tempi;

		deque<int> dq;
		string str;
		int len;
		
		cin >> str;
		cin >> len;

		cin >> temp;

		for (int j = 0; j < len; j++)
		{
			cin >> tempi;
			if( j != len - 1)
			cin >> temp;
			dq.push_back(tempi);
		}
		cin >> temp;


		int f = 1;
		bool error = false;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'R')
				f *= -1;
			else
			{
				if (dq.empty())
				{
					error = true;
					break;
				}

				if (f == 1)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (error)
		{
			cout << "error" << '\n';
			continue;
		}
		cout << "[";
		if (f == 1)
		{
			while (!dq.empty())
			{
				int iter = dq.front();
				dq.pop_front();

				if (dq.empty())
					cout << iter;
				else
					cout << iter <<",";
			}
		}
		else
		{
			while (!dq.empty())
			{
				int iter = dq.back();
				dq.pop_back();

				if (dq.empty())
					cout << iter;
				else
					cout << iter << ",";
			}
		}

		cout << "]" << endl;
	}
}