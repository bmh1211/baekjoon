// ÃÖ¼Ò Èü

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp, index_count = 0;
		cin >> temp;

		if (temp > 0) {
			pq.push(temp);
		}
		else if (temp == 0) {
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

	return 0;
}