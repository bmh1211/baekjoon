// 가운데를 말해요

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > front;
priority_queue<int, vector<int>, greater<int> > back;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (front.empty() && back.empty())
			front.push(temp);
		else if (front.size() == back.size()) {
			// 사이즈가 같으니 front의 개수를 1개 늘림
			if (temp > back.top()) {
				front.push(back.top());
				back.pop();
				back.push(temp);
			}
			else
				front.push(temp);
		}
		else if (front.size() == back.size() + 1) {
			// back의 개수를 1개 늘림
			if (temp < front.top()) {
				back.push(front.top());
				front.pop();
				front.push(temp);
			}
			else
				back.push(temp);
		}

		cout << front.top() << "\n";
	}

	return 0;
}

// pq 두개 만들어서 절반씩
// 앞에 pq는 뒤에 pq와 크기가 같거나 하나 큼
// 앞 pq는 내림차순, 뒤 pq는 오름차순
// 앞 pq의 맨 앞이 항상 중앙값
// 두 pq의 사이즈가 같으면 앞 pq에 넣고, 앞 pq의 사이즈가 1 더 크면 뒤에 넣기