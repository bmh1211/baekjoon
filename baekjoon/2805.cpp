// 나무 자르기

#include<iostream>
using namespace std;

typedef long long ll;

ll tree_height[1000001] = { 0 };

ll findHeight(ll first, ll last, ll tree_count, ll target) {
	// 절단기 높이(mid)를 잡고 절단기 높이를 뺀 모든 나무길이의 합이 적어도 M 이상(target)
	// M보다 작으면 절단기 높이 다시 지정해줘야함
	bool isSuccess = false;
	ll mid;

	while (first <= last) {
		mid = (first + last) / 2;
		ll cut_sum = 0;

		for (ll i = 0; i < tree_count; i++) {
			if (tree_height[i] - mid >= 0) {
				// cut_temp가 음수이면 나무가 잘리지 않은것 - 가져갈 것 없음
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
				// 절단기의 높이가 더 높아도 M값을 만족할 때는 더 높힘
				first = mid + 1;
			else {
				isSuccess = true;
				break;
			}
		}
		else {
			// 잘린 나무 길이가 원했던것보다 짧다면 더 많이 잘라야함 => 절단기의 높이를 낮춰야함
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