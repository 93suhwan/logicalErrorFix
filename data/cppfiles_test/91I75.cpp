#include "bits/stdc++.h"
#include <unordered_map>
#define DEBUG
#undef DEBUG
using namespace std;
typedef int ll;
typedef pair<int, int> pt;

const int MOD = 998'244'353;

void solve_std() {
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
				all_cnt = (all_cnt + cnt - 1) % MOD;
			}
			else {
				mini[i] = a[k];
			}
			//printf("%d ", mini[i]);
		}
		//printf("\n");
		all_cnt %= MOD;
		sum = (sum + all_cnt) % MOD;
	}

	cout << sum << endl;
}

void solve1() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& ai : a)cin >> ai;

	ll sum = 0;
	ll all_cnt = 0;

	vector<pt> miniMap;
	vector<pt> newMap;

	for (int k = n - 1; k >= 0; k--) {
		newMap.clear();
		int cur = a[k];
		newMap.emplace_back(cur, 1);
		for (auto mi : miniMap) {
			int mini = mi.first;
			int occur = mi.second;
			if (cur <= mini) {
				newMap[0].second += occur;
			}
			else {
				int cnt = ceil(1. * cur / mini);
				mini = min((int)(cur / cnt), mini);
				all_cnt = (all_cnt + (cnt - 1LL) * occur) % MOD;
				if (newMap.back().first == mini)
					newMap.back().second += occur;
				else
					newMap.emplace_back(mini, occur);
			}
		}

		miniMap.swap(newMap);
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
	
	unordered_map<int,int> miniMap;
	unordered_map<int, int> newMap;

	for (int k = n - 1; k >= 0; k--) {
		newMap.clear();
		int cur = a[k];
		newMap.emplace(cur, 1);
		for (auto mi : miniMap) {
			int mini = mi.first;
			int occur = mi.second;
			if (cur <= mini) {
				newMap[cur] += occur;
			}
			else {
				int cnt = (cur + mini - 1)/ mini;
				//mini = min(cur / cnt, mini);
				int tmp = (cnt - 1) * occur % MOD;
				all_cnt = (all_cnt + tmp) % MOD;
				newMap[cur / cnt] += occur;
			}
		}

		miniMap.swap(newMap);
		sum = (sum + all_cnt) % MOD;
	}

	cout << sum << '\n';
}

int main() {
#ifdef DEBUG    
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		//solve_std();
		solve();
	}
	return 0;
}