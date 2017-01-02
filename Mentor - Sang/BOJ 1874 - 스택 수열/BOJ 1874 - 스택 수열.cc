#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int n;
queue<int> answer;
queue<char> log_;
stack<int> tempStack;
bool check = false;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		answer.push(x);
	}

}

void proccess() {

	int pos = 1;
	tempStack.push(pos);
	log_.push('+');
	pos++;

	while (!answer.empty())
	{
		int fAnswer = answer.front();
		answer.pop();

		if (tempStack.empty())
		{
			if (pos > n)
			{
				check = true;
				return;
			}

			tempStack.push(pos);
			pos++;
			log_.push('+');

		}

		while (tempStack.top() != fAnswer)
		{
			if (pos > n)
			{
				check = true;
				return;
			}

			tempStack.push(pos);
			pos++;
			log_.push('+');
		}

		tempStack.pop();
		log_.push('-');
	}
}

void output() {
	if (check)
		cout << "NO" << '\n';
	else
	{
		while (!log_.empty())
		{
			cout << log_.front() << '\n';
			log_.pop();
		}
	}
}

int main() {
	input();
	proccess();
	output();
}