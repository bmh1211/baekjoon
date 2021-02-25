// ����Ʈ�� �̵�

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 300

int T, I, src_x, src_y, dest_x, dest_y;
int chess[MAX][MAX];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	chess[x][y] = 0; // ��������

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < I && 0 <= ny && ny < I) {
				if (chess[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					chess[nx][ny] = chess[x][y] + 1;
				}
			}
		}

		//����׽�Ʈ��
		/*cout << "\n===================\n";
		for (int i = 0; i < I; i++) {
			for (int j = 0; j < I; j++) {
				cout << chess[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "===================\n";*/

		if (chess[dest_x][dest_y] != -1)
			break;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	for (int t = 0; t < T; t++) {
		// ���� ������ �ʱ�ȭ
		memset(chess, -1, sizeof(chess)); // -1�̸� �湮���� �ʾҴٴ� ��
		while (!q.empty()) {
			q.pop();
		}

		// src�� �����ִ� ĭ, dest�� �̵��Ϸ��� ĭ
		cin >> I >> src_x >> src_y >> dest_x >> dest_y;

		if (src_x == dest_x && src_y == dest_y)
			cout << 0 << "\n";
		else {
			bfs(src_x, src_y);

			if (chess[dest_x][dest_y] == -1)
				// �������� �� �� ���
				cout << 0 << "\n";
			else
				cout << chess[dest_x][dest_y] << "\n";
		}
	}

	return 0;
}