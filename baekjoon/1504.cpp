// Ư���� �ִ� ���

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321
#define MAX 801

int path[MAX];
vector<pair<int, int>> vertex[MAX]; // connected vertex, cost (vertex�� �ε����� 1~800 ���)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q; // cost, index, cost�� ��������(�Ǿ��� �ּڰ�)

void bfs(int start) {
	q.push(make_pair(0, start)); // ��������
	path[start] = 0;

	while (!q.empty()) {
		int start = q.top().second;
		int start_cost = q.top().first;
		q.pop();

		// start�� ����� ��� vertex�� ���ؼ� �Ÿ� ������Ʈ
		for (int i = 0; i < vertex[start].size(); i++) {
			int next = vertex[start][i].first;
			int next_cost = vertex[start][i].second;
			int new_cost = start_cost + next_cost;

			if (path[next] > new_cost) {
				path[next] = new_cost;
				q.push(make_pair(new_cost, next));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// 1 -> ... -> v1 -> ... -> v2 -> ... -> N
	// 1 -> ... -> v2 -> ... -> v1 -> ... -> N
	// 1���� v1,v2������ �ּҰ��, v1���� v2������ �ּҰ��(������̹Ƿ� v2->v1�� �Ÿ� ����), v2���� N������ �ּҰ��, v1���� N������ �ּҰ�� => �� 4���� ���ͽ�Ʈ�� ����

	int N, E, v1, v2;
	cin >> N >> E; // N : ��������, E : ��������

	if (E == 0) {
		// ������ �ϳ��� ���� ��쿡�� ������ �Ұ��� !!!!!!!!!!!�߿�!!!!!!!!!!!!!!!
		cout << -1 << "\n";
		return 0;
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c; 
		// a�� b ������ ����� ���� ����, ����ġ c (c�� ���)

		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2; 
	// �ݵ�� ���ľ� �ϴ� �ΰ��� ���� �ٸ� ����

	int v1_v2, v2_v1, v1_N, v2_N, result;
	int flag = 0; 
	// 1 : 1->v1->v2->N ����, 2 : 1->v2->v1->N ����, 3 : �Ѵ� ����, 0 : �Ѵ� �Ұ���

	for (int i = 0; i < MAX; i++)
		path[i] = INF;
	bfs(1);

	v1_v2 = path[v1];
	// 1���� v1
	v2_v1 = path[v2];
	// 1���� v2

	if (v1_v2 == INF && v2_v1 != INF) flag = 2;
	else if (v1_v2 != INF && v2_v1 == INF) flag = 1;
	else if (v1_v2 != INF && v2_v1 != INF) flag = 3;

	if (flag == 1 || flag == 3) {
		for (int i = 0; i < MAX; i++)
			path[i] = INF;
		bfs(v1);

		v1_v2 += path[v2];
		// 1���� v1�� ��ģ v2
		v1_N = path[N];
		// v1���� N
	}

	if (flag == 2 || flag == 3) {
		for (int i = 0; i < MAX; i++)
			path[i] = INF;
		bfs(v2);

		v2_v1 += path[v1];
		// 1���� v2�� ��ģ v1
		v2_N = path[N];
		// v2���� N
	}
	
	if (flag == 0) {
		result = -1;
	}
	else if (flag == 1) { 
		v1_v2 += v2_N;
		result = v1_v2;
	}
	else if (flag == 2) { 
		v2_v1 += v1_N;
		result = v2_v1;
	}
	else if (flag == 3) {
		v1_v2 += v2_N;
		v2_v1 += v1_N;

		if (v1_v2 <= v2_v1)
			result = v1_v2;
		else
			result = v2_v1;
	}
	cout << result << "\n";

	return 0;
}