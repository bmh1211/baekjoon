// �ִܰ��

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 20001
#define INF 987654321

int path[MAX]; // �ش� �ε������� ���� �ּҰŸ�
vector<pair<int, int>> vertex[MAX]; // int : ����� ���� ����, int : �׶��� ����ġ
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q; // ���� �������� ���� ����� ������ ã���� �������� ����
											  // int : �ش� �������� �ּ� �Ÿ�,  int : �� ������ �ε���

void bfs(int start) {
	q.push(make_pair(0, start)); // ó�� ������(�Ÿ� : 0, ������ : start), ���� INF���� 0���� �ٲ���Ƿ� ��Ž�� ����
	path[start] = 0;

	while (!q.empty()) {
		int value = q.top().first;
		int start = q.top().second;
		q.pop();
		
		for (int i = 0; i < vertex[start].size(); i++) {
			int next = vertex[start][i].first; // start�� ����� ��
			int distance = vertex[start][i].second; // start�� next ������ ����ġ

			if (path[next] > value + distance) {
				// ���� �ִ� next������ �Ÿ��� ���� üũ�� �Ÿ����� ũ�ٸ� ������Ʈ(�ݺ������Ͽ� �ּҰ����� ������Ʈ)
				path[next] = value + distance;
				q.push(make_pair(path[next], next)); // üũ�� ���� �� �߰�
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int V, E, K; // V : ��������, E : ��������, K : ��������
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w; // ���� u���� v�� ���� ����ġ w�� ����
		cin >> u >> v >> w;

		vertex[u].push_back(make_pair(v, w)); // i�� ������ ����� ��� ������ �� �������� ���� �Ÿ�
	}
	
	for (int i = 0; i < MAX; i++)
		path[i] = INF; // ���Ѵ�� �ʱ�ȭ
	
	bfs(K);
	for (int i = 1; i <= V; i++) {
		if (path[i] == INF)
			cout << "INF" << "\n";
		else
			cout << path[i] << "\n";
	}

	return 0;
}