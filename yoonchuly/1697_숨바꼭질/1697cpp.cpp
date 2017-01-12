#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//#define TEST

//void hanoi(int, int, int, int);
void func(int, int);
void bfs(int);

int s = 0, e;;
int thresh;
int check[1000001] = {0};
int main()
{
	for (int i = 0; i <= 100000; ++i)
		check[i] = 100000;

	cin >> s;
	check[s] = 0;
	cin >> e;
	bfs(s);
	cout << check[e];
	//hanoi(5, 1, 2, 3);
}

void bfs(int num)
{
	vector<int> list;
	list.push_back(num);
	
	for (int searched = 0; searched < list.size(); ++searched)
	{
		int cur = list.at(searched);
		if (cur == e)
			return;

		if (cur * 2 <= 100000 && check[cur * 2] > check[cur] + 1)
		{
			check[cur * 2] = check[cur] + 1;
			list.push_back(cur * 2);
		}
		if (cur + 1 <= 100000 && check[cur + 1] > check[cur] + 1)
		{
			check[cur + 1] = check[cur] + 1;
			list.push_back(cur + 1);
		}
		if (cur - 1 >= 0 && cur - 1 <= 100000 && check[cur - 1] > check[cur] + 1)
		{
			check[cur - 1] = check[cur] + 1;
			list.push_back(cur - 1);
		}
	}
}
/*
void func(int num, int time)
{
	if (time >= thresh)
		return;
	if (num >= e + thresh)
		return;
	if (num == e)
	{
		thresh = time;
		return;
	}
	else
	{
		func(num * 2, time + 1);
		func(num + 1, time + 1);
		func(num - 1, time + 1);
	}
}
*/

void func(int num, int time)
{
	if (num > 100000)
		return;
	if (num >= 0)
	{
#ifdef TEST
		printf("num : %d, time : %d\n", num, time);
		printf("check[num] : %d\n", check[num]);
#endif
		if (check[num] != 0 && check[num] < time)
			return;
		check[num] = time;
	}
	if (time >= thresh)
		return;
	if (num >= e + thresh)
		return;
	if (num == e)
	{
		thresh = time;
		return;
	}
	else
	{
		if (!(num * 2 > e))
			func(num * 2, time + 1);
		if (!(num + 1 > e))
			func(num + 1, time + 1);
		if (num > e)
		{
			thresh = time + e - num - 1;
			return;
		}
		func(num - 1, time + 1);
	}
}

/*
void hanoi(int n, int a, int b, int c) // n개의 원판을 a에서 b를 거쳐 c로 옮긴다.
{
	if (n == 1)
	{
		printf("%d에서 %d로 원판을 옮김\n", a, c);
		return;
	}
	hanoi(n - 1, a, c, b);
	hanoi(1, a, b, c);
	hanoi(n - 1, b, a, c);
}
*/