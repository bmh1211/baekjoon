// ************** 숫자 카드 2 ***************//

#include<iostream>
#include<algorithm>
using namespace std;

int card[500001];

int findStartIndex(int target, int first, int last) {
	bool isSuccess=false;
	int mid; // 얘가 찾는 수의 인덱스 역할

	while (first <= last) {
		mid = (first + last) / 2;

		if (first == last) {
			if (card[mid] == target) {
				isSuccess = true;
				break;
			}
			else
				break;
		}

		if (card[mid] >= target) {
			last = mid;
		}
		else
			first = mid + 1;
	}

	if (isSuccess)
		return mid;
	else
		return -1;
}

int findFinishIndex(int target, int first, int last) {
	bool isSuccess = false;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (first == last) {
			if (card[mid] == target) {
				isSuccess = true;
				break;
			}
			else
				break;
		}

		if (card[mid] > target) {
			last = mid;
		}
		else if (card[mid] < target) {
			first = mid + 1;
		}
		else {
			if (card[mid + 1] > target)
				last = mid;
			else
				first = mid + 1;
		}
	}

	if (isSuccess)
		return mid;
	else
		return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	sort(card, card + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp, startIndex, finishIndex;
		cin >> temp;
		
		// 1. 찾으려는 숫자 이상의 수가 처음 나오는 위치찾기
		startIndex = findStartIndex(temp, 0, N - 1);
		// 2. 찾으려는 숫자 초과의 수가 처음 나오는 위치찾기
		finishIndex = findFinishIndex(temp, 0, N - 1);
		// 3. 2번에서 1번을 빼면 찾으려는 숫자의 개수가 나옴
		if (startIndex == -1)
			cout << 0 << " ";
		else
			cout << finishIndex - startIndex + 1 << " ";
	}

	return  0;
}