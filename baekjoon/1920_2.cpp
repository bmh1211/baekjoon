// ************** �� ã�� ***************//

#include<iostream>
#include<algorithm>
using namespace std;

int A[100000] = { 0 };

int findNumber(int target, int first, int last) {
	bool isSuccess = false;

	while (first <= last) {
		int mid = (first + last) / 2;

		if (A[mid] == target) {
			isSuccess = true;
			break;
		}
		else if (A[mid] > target) {
			last = mid - 1;
		}
		else
			first = mid + 1;
	}

	if (isSuccess)
		return 1;
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		// A�迭�� ���� �ֱ�
		cin >> A[i];
	}
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		// �Է¹��� ���ڰ� A�迭 �ȿ� �����ϴ��� ã��
		int target;
		cin >> target;

		result = findNumber(target, 0, N - 1);
		cout << result << "\n";
	}

	return 0;
}