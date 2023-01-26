#include <iostream>
#include <fstream>
#include <cstdio>

#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <stack>

#include <functional>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <numeric>

#include <cassert>
#include <random>
#include <chrono>

#include <complex>
#include <climits>

using namespace std;

#define ll long long
#define prll pair<ll,ll>
#define prii pair<int,int>
#define m_p make_pair
#define INF (ll)LLONG_MAX
#define int long long

namespace __time {
	clock_t t;
	double get_time() {
		return (double)(clock() - t) / CLOCKS_PER_SEC;
	}
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 100;
int p[N], sz[N], mn[N];
vector<prii> pnts_x[N];
vector<prii> pnts_y[N];

int get(int v) {
	if (v == p[v]) return v;
	return (p[v] = get(p[v]));
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) return;
	if (sz[a] < sz[b])swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	mn[a] = min(mn[a], mn[b]);
}

void clear(int n) {
	for (int i = 0; i < n; ++i) {
		p[i] = i;
		sz[i] = 1;
		pnts_x[i].clear();
		pnts_y[i].clear();
		mn[i] = INT_MAX;
	}
}

struct Sjatie {
	vector<ll> mas;

	Sjatie(vector<ll>& init) {
		mas = init;
		sort(mas.begin(), mas.end());
		mas.erase(unique(mas.begin(), mas.end()), mas.end());
	}

	int get_id_r(ll x) {
		auto it = upper_bound(mas.begin(), mas.end(), x);
		return (it - mas.begin());
	}

	int get_id_l(ll y) {
		auto it = lower_bound(mas.begin(), mas.end(), y);
		return (it - mas.begin()) + 1;
	}
};

void $main() {
	int n, k; cin >> n >> k;
	clear(n);

	vector<int> x_, y_;
	vector<pair<prii, int>> all;
	for (int i = 0; i < n; ++i) {
		int x, y, t; cin >> x >> y >> t;
		x_.push_back(x);
		y_.push_back(y);
		all.emplace_back(m_p(x, y), i);
		mn[i] = t;
	}
	sort(x_.begin(), x_.end());
	sort(y_.begin(), y_.end());

	auto fita = Sjatie(x_);
	auto vita = Sjatie(y_);

	sort(all.begin(), all.end());
	for (auto& el : all) {
		int x = el.first.first;
		int y = el.first.second;
		int id = el.second;

		int y_id = vita.get_id_l(y);
		pnts_y[y_id].emplace_back(x, id);

		auto l = lower_bound(pnts_y[y_id].begin(), pnts_y[y_id].end(), m_p(x, -INF));
		if (l != pnts_y[y_id].begin()) {
			--l;
			if (x - l->first <= k) {
				merge(id, l->second);
			}
		}
		auto r = upper_bound(pnts_y[y_id].begin(), pnts_y[y_id].end(), m_p(x, INF));
		if (r != pnts_y[y_id].end()) {
			if (r->first - x <= k) {
				merge(id, r->second);
			}
		}
	}

	sort(all.begin(), all.end(), [](auto& a, auto& b) {
		if (a.first.second == b.first.second) return a.first.first < b.first.first;
		return a.first.second < b.first.second;
		});
	for (auto& el : all) {
		int x = el.first.first;
		int y = el.first.second;
		int id = el.second;

		int x_id = fita.get_id_l(x);
		pnts_x[x_id].emplace_back(y, id);

		auto l = lower_bound(pnts_x[x_id].begin(), pnts_x[x_id].end(), m_p(y, -INF));
		if (l != pnts_x[x_id].begin()) {
			--l;
			if (y - l->first <= k) {
				merge(id, l->second);
			}
		}
		auto r = upper_bound(pnts_x[x_id].begin(), pnts_x[x_id].end(), m_p(y, INF));
		if (r != pnts_x[x_id].end()) {
			if (r->first - y <= k) {
				merge(id, r->second);
			}
		}
	}
	vector<int> used(n), comps;
	for (int i = 0; i < n; ++i) {
		int cur = get(i);
		if (used[cur])continue;
		comps.emplace_back(mn[cur]);
		used[cur] = 1;
	}
	sort(comps.begin(), comps.end());

	int ans = 0;
	comps.pop_back();

	while (!comps.empty() && comps.back() > ans) {
		comps.pop_back();
		ans++;
	}
	cout << ans << '\n';

	clear(n);
}

signed main()
{
	setlocale(LC_ALL, "Russian");

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	//freopen("kbest.in", "r", stdin);
	//freopen("kbest.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//__time::t = clock();
	int t; cin >> t;
	while (t--)
		$main();

	return 0;
}