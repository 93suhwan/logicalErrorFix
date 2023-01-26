#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cases; cin >> cases;
	for (int c = 0; c < cases; c++) {
		long long nums, cables; cin >> nums >> cables;
		nums--;
		long long l = 0, r = 2'000'000'000, ans;
		while (l <= r) {
			long long m = (l + r) / 2;
			if ((m * m + m) / 2 >= nums) {
				ans = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if (ans <= cables) cout << ans << '\n';
		else {
			nums -= (cables * cables + cables) / 2;
			cout << cables + ceil((long double)(nums) / cables) << '\n';
		}
	}
	return 0;
}