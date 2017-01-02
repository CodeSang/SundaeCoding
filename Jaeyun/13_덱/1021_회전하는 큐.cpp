#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
	int N, M, cnt=0, op2=0, op3=0, pos;
	deque<int> dq;

	cin >> N >> M;

	vector<int> val(M, 0);

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> val[i];
		op2 = 0;
		op3 = 0;
		pos = (val[i]-op2+op3+dq.size()-1)%dq.size();
		if (pos <= dq.size() / 2) {
			while (dq.front() != val[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				
				op2++;
				cnt++;
			}
			dq.pop_front();
		}
		else {
			while (dq.back() != val[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
			
				op3++;
				cnt++;
			}
			dq.pop_back();
		}
	}
	cout << cnt << endl;
	return 0;
}
