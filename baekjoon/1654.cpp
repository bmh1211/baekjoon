// 랜선자르기

#include<iostream>
using namespace std;

long long line[10001] = { 0 };

long long findLength(long long first, long long last, long long size, long long goal) {
	bool isSuccess = false;
	long long mid;

	while (first <= last) {
		mid = (first + last) / 2;
		long long lineCount = 0;
		
		for (int i = 0; i < size; i++) {
			lineCount += (line[i] / mid);
		}

		if (lineCount < goal)
			// N개보다 적게 만들어질 때
			last = mid - 1;
		else {
			// N개보다 같거나 많이 만들어질 때
			long long lineCount_next = 0;

			for (long long i = 0; i < size; i++) {
				lineCount_next += (line[i] / (mid + 1));
			}

			if (lineCount_next >= goal)
				// 단위길이가 더 긴 상황이 존재하는 경우
				first = mid + 1;
			else {
				isSuccess = true;
				break;
			}
		}
	}

	if (isSuccess)
		return mid;
	else
		return -1;
}

int main() {
	// 가지고 있는 K개의 랜선을 잘라서 N개로 만들어야함
	// 그때 자를 수 있는 최대 길이가 답
	// 처음 모든 수 다 더한 길이를 N으로 나누었을 때보다 단위길이가 짧을것임을 이용
	long long K, N, result, temp = 0;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		temp += line[i];
	}
	temp /= N; // 맨처음 기준이 될 단위길이 temp (1~temp 사이에서 값 찾기)

	result = findLength(1, temp, K, N);

	cout << result;

	return  0;
}