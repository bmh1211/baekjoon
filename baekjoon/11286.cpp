// ���� �� 

#include<iostream>
#include<queue>
using namespace std;

struct number {
	int input;
	int origin;
};

struct compare {
	bool operator()(number a, number b) {
		if (a.input != b.input)
			// �θ��� ���밪(input)�� �� Ŭ ��� ����
			return a.input > b.input;
		else
			// �θ��� ������(origin)�� �� Ŭ ��� ����
			return a.origin > b.origin;
	}
};

priority_queue<number, vector<number>, compare> pq;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp, index_count = 0;
		cin >> temp;

		if (temp == 0) {
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top().origin << "\n";
				pq.pop();
			}
		}
		else {
			number num;

			if (temp < 0)
				num.input = temp * -1;
			else
				num.input = temp;
			num.origin = temp;

			pq.push(num);
		}
	}

	return 0;
}