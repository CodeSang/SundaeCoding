#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

deque<int> dq;
int count(int N)
{
	int len = dq.size();
	int cnt = 0;

	while (dq.front() != N)
	{
		cnt++;
		dq.push_back(dq.front());
		dq.pop_front();
	}

	dq.pop_front();
	return min(cnt, len - cnt);
}

int main() {

	int N, M,cnt = 0;	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cnt += count(temp);
	}
	
	cout << cnt << endl;
	return 0;
}