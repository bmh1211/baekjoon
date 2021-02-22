// 숨바꼭질

#include<iostream>
#include<queue>
using namespace std;

#define MAX 200001 // 처음위치는 100000이 최대지만 이동 가능 위치는 100000을 넘을 수 있음
int N, K;
int position[MAX]; // 방문하는데 걸리는 시간, 0이 아니면 방문을 했었다는 뜻이 됨
queue<int> q;

void bfs(int x) {
	q.push(x);
	position[x] = 1; // 시작지점이 0이면 나중에 한번 더 들릴수 있으므로 1로 하고, 결과에서 1빼기

	while (position[K]==0) {
		x = q.front();
		q.pop();

		// 움직일 수 있는 3가지 => +1, -1, *2
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