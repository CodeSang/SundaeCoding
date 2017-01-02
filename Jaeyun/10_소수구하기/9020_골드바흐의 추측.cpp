#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int T, N, part1 = 1, part2 = 10000;
	vector<int> v(1e4 + 1, 1);
	v[1] = 0;

	for (int i = 2; i <= sqrt(1e4); i++) {
		for (int j = 2; i*j <= 1e4; j++) {
			v[i*j] = 0;
		}
	}

	cin >> T;
	while (T--) {
		cin >> N;
		part1 = 1;
		part2 = 10000;

		for (int i = 1; i <= N / 2; i++) {
			if (v[N / 2]) {
				part1 = N / 2;
				part2 = N / 2;
				break;
			}
			if (v[N / 2 - i] && v[N / 2 + i]) {
				part1 = N / 2 - i;
				part2 = N / 2 + i;
				break;
			}
		}
		printf("%d %d\n", part1, part2);
	}
	
	return 0;
}

