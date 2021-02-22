// ���ٲ���

#include<iostream>
#include<queue>
using namespace std;

#define MAX 200001 // ó����ġ�� 100000�� �ִ����� �̵� ���� ��ġ�� 100000�� ���� �� ����
int N, K;
int position[MAX]; // �湮�ϴµ� �ɸ��� �ð�, 0�� �ƴϸ� �湮�� �߾��ٴ� ���� ��
queue<int> q;

void bfs(int x) {
	q.push(x);
	position[x] = 1; // ���������� 0�̸� ���߿� �ѹ� �� �鸱�� �����Ƿ� 1�� �ϰ�, ������� 1����

	while (position[K]==0) {
		x = q.front();
		q.pop();

		// ������ �� �ִ� 3���� => +1, -1, *2
		if (x < MAX - 1 && position[x + 1] == 0) {
			q.push(x + 1);
			position[x + 1] = position[x] + 1;
		}
		if (x > 0 && position[x - 1] == 0) {
			q.push(x - 1);
			position[x - 1] = position[x] + 1;
		}
		if (x < MAX / 2 && position[x * 2] == 0) {
			q.push(x * 2);
			position[x * 2] = position[x] + 1;
		}

		if (position[K] != 0)
			break;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K;

	if (N == K)
		cout << 0;
	else {
		bfs(N);
		cout << position[K] - 1;
	}

	return 0;
}