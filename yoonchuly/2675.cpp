#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector <string> s;
	string s_temp;
	vector <int> rein;
	int rein_temp;
	int test_case;

	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> rein_temp;
		rein.push_back(rein_temp);

		cin >> s_temp;
		s.push_back(s_temp);
	}

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			for (int k = 0; k < rein[i]; k++)
			{
				cout << s[i][j];
			}
		}
		cout << endl;
	}

	
	return 0;
}