#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int test_case =0;
	int queue_num =0;
	
	int temp;
	int result = 1;
	bool result_end = false;

	vector <queue <int>> print;
	vector<int> max_temp;
	vector<int> know_num;

	cin >> test_case;





	for (int i = 0; i < test_case; i++)
	{
		cin >> queue_num;
		cin >> temp;
		know_num.push_back(temp);
		print.push_back(queue<int>());
		for (int j = 0; j < queue_num; j++)
		{
			cin >> temp;
			print[i].push(temp);
		}
	}


	for (int i = 0; i < test_case; i++)
	{
		max_temp.push_back(0); //max 초기화

		while (result_end == false)
		{
			for (int j = 0; j < print[i].size(); j++)//max 찾기
			{
				if (print[i].front() > max_temp[i])
				{
					max_temp[i] = print[i].front();
				}
				temp = print[i].front();
				print[i].pop();
				print[i].push(temp);
			}
			for (int j = 0; j < print[i].size(); j++)
			{
				if (max_temp[i] > print[i].front())
				{
					if (know_num[i] == 0) // front가 know_num 이면 know_num 바꾸기
						know_num[i] = print[i].size() - 1;
					else
						know_num[i]--;

					temp = print[i].front();
					print[i].pop();
					print[i].push(temp);

				}
				//else if (max_temp[i] == print[i].front())
				else
				{
					if (know_num[i] == 0) // 알고 싶은 번호의 값이 나오면 결과 출력하고 break;
					{
						result_end = true;
						cout << result << endl;
						break;
					}
					print[i].pop();
					max_temp[i] = 0;
					know_num[i]--;
					result++; //현재 front값이 가장 중요도가 높으면 빼고, result++
					break; // 하나 뺏으니깐 다시 max값 찾기 위해 break;
				}
			}
		}
		result_end = false;
		result = 1;
	}
	return 0;
}