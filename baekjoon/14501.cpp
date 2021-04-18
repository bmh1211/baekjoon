// 퇴사

#include<iostream>
#include<vector>
using namespace std;

int N;
vector<pair<int, int>> vec; // int : 걸리는 기간, int : 수익
int max_time[17] = { 0 };

int findMax(int turn) {
	int max = 0;
	for (int i = 1; i <= turn; i++) {
		if (max < max_time[i])
			max = max_time[i];
	}

	return max;
}

void solution() {
	for (int turn = 1; turn <= N; turn++) {
		int finish_day = turn + vec[turn].first;
		int profit = vec[turn].second;
		int max = findMax(turn);

		if (finish_day <= N + 1 && max + profit > max_time[finish_day]) {
			max_time[finish_day] = max + profit;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	vec.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		int day, profit;
		cin >> day >> profit;
		vec.push_back(make_pair(day, profit));
	}

	solution();

	int result = 0;
	for (int i = 1; i <= N+1; i++)
		if (result < max_time[i])
			result = max_time[i];
	cout << result << "\n";

	return 0;
}