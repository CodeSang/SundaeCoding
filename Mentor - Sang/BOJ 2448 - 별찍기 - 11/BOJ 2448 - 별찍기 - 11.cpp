#include<iostream>
#include<vector>
using namespace std;


vector<vector<char>> v(6150, vector<char>(6150, ' '));

void setStar(int N, int x, int y)
{

	if (N / 3 == 1)
	{
		v[y][x + 2] = v[y + 1][x + 1] = v[y + 1][x + 3] = v[y + 2][x] = v[y + 2][x + 1] = v[y + 2][x + 2] = v[y + 2][x + 3] = v[y + 2][x + 4] = '*';
		return;
	}
	
	setStar(N / 2, x + N / 2, y);
	setStar(N / 2, x    , y + N / 2);
	setStar(N / 2, x + N, y + N / 2);
}


void printStar(int N)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0 ; x < N *2 -1 ; x++)
			cout << v[y][x];
		cout << endl;
	}
}
int main() {

	int N;
	cin >> N;

	setStar(N, 0 , 0);
	printStar(N);
}