// ����� ���ؿ�

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
			// ����� ������ front�� ������ 1�� �ø�
			if (temp > back.top()) {
				front.push(back.top());
				back.pop();
				back.push(temp);
			}
			else
				front.push(temp);
		}
		else if (front.size() == back.size() + 1) {
			// back�� ������ 1�� �ø�
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

// pq �ΰ� ���� ���ݾ�
// �տ� pq�� �ڿ� pq�� ũ�Ⱑ ���ų� �ϳ� ŭ
// �� pq�� ��������, �� pq�� ��������
// �� pq�� �� ���� �׻� �߾Ӱ�
// �� pq�� ����� ������ �� pq�� �ְ�, �� pq�� ����� 1 �� ũ�� �ڿ� �ֱ�