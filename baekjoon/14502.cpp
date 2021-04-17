// ������

#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

queue<pair<int, int>> q;
int result = 0;
int virus_origin[8][8];
int virus[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M;

void bfs() {
	// ���׸��� ������ �Լ�
	// 0�� ��ĭ, 1�� ��, 2�� ���̷���

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && virus[nx][ny] == 0) {
				virus[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	// �� ���� �� �� �������� ���� Ȯ��
	int safezone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 0)
				safezone++;
		}
	}
	if (result < safezone)
		result = safezone;
}

void three_wall() {
	// ���� 3�� ������ ��
	// ���� �����ٰ� ���� ������ ���� ���� �� �ڸ��� ���� �����ְ� �����ڸ��� ���� ��������

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus[i][j] == 0) {
				// �� �ϳ� ������
				virus[i][j] = 1;
				virus_origin[i][j] = 1;
				
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						if (virus[k][l] == 0) {
							// �� �ΰ� ������
							virus[k][l] = 1;
							virus_origin[k][l] = 1;

							for (int m = 0; m < N; m++) {
								for (int n = 0; n < M; n++) {
									if (virus[m][n] == 0) {
										// �� ���� ������
										virus[m][n] = 1;
										virus_origin[m][n] = 1;

										bfs();

										// ���� ������⿡ ������ ���� �ʵ��� ���� ��������
										virus_origin[m][n] = 0;
										memcpy(virus, virus_origin, sizeof(virus_origin));
									}
								}
							}
							// ���� ������⿡ ������ ���� �ʵ��� ���� ��������
							virus_origin[k][l] = 0;
							memcpy(virus, virus_origin, sizeof(virus_origin));
						}
					}
				}
				// ���� ������⿡ ������ ���� �ʵ��� ���� ��������
				virus_origin[i][j] = 0;
				memcpy(virus, virus_origin, sizeof(virus_origin));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// ���̷����� ������ ���� BFS�� ����
	// ���� 3���� ��������

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> virus[i][j];
		}
	}
	
	// ��� �����Ǵ� virus�� ���������� virus_origin
	memcpy(virus_origin, virus, sizeof(virus));

	three_wall();

	cout << result << "\n";

	return 0;
}