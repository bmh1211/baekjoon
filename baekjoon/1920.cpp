#include<iostream>
#include<algorithm>
using namespace std;

int A[100000] = { 0 };

int findNumber(int target, int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;

		if (target == A[mid])
			return 1;
		else if (target < A[mid])
			return findNumber(target, first, mid - 1);
		else
			return findNumber(target, mid + 1, last);
	}
	else {
		if (first == last) {
			if (target == A[first])
				return 1;
			else
				return 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		// A배열에 숫자 넣기
		cin >> A[i];
	}
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		// 입력받은 숫자가 A배열 안에 존재하는지 찾기
		int target;
		cin >> target;

		result = findNumber(target, 0, N - 1);
		cout << result << "\n";
	}

	return 0;
}