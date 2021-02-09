// �����ڸ���

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
			// N������ ���� ������� ��
			last = mid - 1;
		else {
			// N������ ���ų� ���� ������� ��
			long long lineCount_next = 0;

			for (long long i = 0; i < size; i++) {
				lineCount_next += (line[i] / (mid + 1));
			}

			if (lineCount_next >= goal)
				// �������̰� �� �� ��Ȳ�� �����ϴ� ���
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
	// ������ �ִ� K���� ������ �߶� N���� ��������
	// �׶� �ڸ� �� �ִ� �ִ� ���̰� ��
	// ó�� ��� �� �� ���� ���̸� N���� �������� ������ �������̰� ª�������� �̿�
	long long K, N, result, temp = 0;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		temp += line[i];
	}
	temp /= N; // ��ó�� ������ �� �������� temp (1~temp ���̿��� �� ã��)

	result = findLength(1, temp, K, N);

	cout << result;

	return  0;
}