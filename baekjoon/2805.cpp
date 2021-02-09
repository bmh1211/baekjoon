// ���� �ڸ���

#include<iostream>
using namespace std;

typedef long long ll;

ll tree_height[1000001] = { 0 };

ll findHeight(ll first, ll last, ll tree_count, ll target) {
	// ���ܱ� ����(mid)�� ��� ���ܱ� ���̸� �� ��� ���������� ���� ��� M �̻�(target)
	// M���� ������ ���ܱ� ���� �ٽ� �����������
	bool isSuccess = false;
	ll mid;

	while (first <= last) {
		mid = (first + last) / 2;
		ll cut_sum = 0;

		for (ll i = 0; i < tree_count; i++) {
			if (tree_height[i] - mid >= 0) {
				// cut_temp�� �����̸� ������ �߸��� ������ - ������ �� ����
				cut_sum += (tree_height[i] - mid);
			}
		}

		if (cut_sum >= target) {
			ll cut_sum_next = 0;
			for (ll i = 0; i < tree_count; i++) {
				if(tree_height[i]-(mid+1) >= 0)
					cut_sum_next += (tree_height[i] - (mid + 1));
			}
			
			if (cut_sum_next >= target)
				// ���ܱ��� ���̰� �� ���Ƶ� M���� ������ ���� �� ����
				first = mid + 1;
			else {
				isSuccess = true;
				break;
			}
		}
		else {
			// �߸� ���� ���̰� ���ߴ��ͺ��� ª�ٸ� �� ���� �߶���� => ���ܱ��� ���̸� �������
			last = mid - 1;
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
	
	ll N, M, result;
	cin >> N >> M;
	
	for (ll i = 0; i < N; i++) {
		cin >> tree_height[i];
	}

	result = findHeight(0, 2000000000, N, M);

	cout << result;

	return 0;
}