#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int MOD = 998'244'353;

void solve1() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> mini(n);
	for (auto& ai : a)cin >> ai;

	ll sum = 0;
	ll all_cnt = 0;

	for (int k = n - 1; k >= 0; k--) {
		mini[k] = a[k];
		for (int i = k + 1; i < n; i++) {
			if (a[k] > mini[i]) {
				int cnt = ceil(1. * a[k] / mini[i]);
				mini[i] = min((int)(a[k] / cnt), mini[i]);
				all_cnt += cnt - 1;
			}
			else {
				mini[i] = a[k];
			}
		}
		all_cnt %= MOD;
		sum = (sum + all_cnt) % MOD;
	}

	cout << sum << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& ai : a)cin >> ai;

	ll sum = 0;
	ll all_cnt = 0;

	map<int, int> miniMap;

	for (int k = n - 1; k >= 0; k--) {
		map<int, int> newMap;
		newMap[a[k]] = 1;
		for (auto mi : miniMap) {
			int mini = mi.first;
			if (a[k] <= mini) {
				newMap[a[k]]++;
			}
			else {
				int occur = mi.second;
				int cnt = ceil(1. * a[k] / mini);
				mini = min((int)(a[k] / cnt), mini);
				all_cnt += (cnt - 1) * occur;
				if(newMap.find(mini)!=newMap.end())
					newMap[mini] += occur;
				else
					newMap[mini] = occur;
			}
		}

		miniMap.clear();
		miniMap.insert(newMap.begin(), newMap.end());

		all_cnt %= MOD;
		sum = (sum + all_cnt) % MOD;
	}

	cout << sum << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}