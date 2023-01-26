#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long infty = 1000000000000000ll;

/*input
3 4 5
10 30 15
12 31 14 18
0 1 2 3 4
*/

typedef tree <
pair<int, int>,
	 null_type,
	 less<pair<int, int>>,
	 rb_tree_tag,
	 tree_order_statistics_node_update >
	 ordered_set;

long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(n), b(m);
	vector<pair<long long, int>>qq(q);

	for (auto &&x : a) {
		cin >> x;
	}

	for (auto &&x : b) {
		cin >> x;
	}

	for (int i = 0; i < q; ++i) {
		cin >> qq[i].first;
		qq[i].second = i;
	}

	sort(qq.begin(), qq.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	debug(a);
	debug(b);

	vector<pair<int, int>>bb;
	vector<pair<int, pair<int, int>>> aa;

	for (int i = 1; i < m; ++i) {
		bb.push_back({b[i] - b[i - 1], i});
	}

	typedef pair<ordered_set *, int> Repr;
	set<pair<int, Repr>>bi;

	int al[n] = {};

	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(b.begin(), b.end(), a[i]);

		if (it != b.end())
			aa.push_back({*it - a[i], {i, it - b.begin()}});

		if (it != b.begin()) {
			it--;
			aa.push_back({a[i] - *it, {i, it - b.begin()}});
		}

		ans += a[i];
		al[i] = -1;
	}

	sort(aa.begin(), aa.end());
	debug(aa);
	debug(bb);
	sort(bb.begin(), bb.end());

	int xxx = 0;

	auto uno = [&](int v, int k) -> Repr {
		auto t = new ordered_set();
		t->insert({v, xxx++});
		return {t, k};
	};

	for (int i = 0; i < m; ++i) {
		bi.insert({i, uno(b[i], 0)});
	}

	auto merges = [&](Repr i, Repr j) -> Repr {
		if (i.first->size() < j.first->size()) {
			swap(i, j);
		}

		for (auto &&x : *j.first) {
			auto t = i.first->find_by_order(i.first->size() - i.second);

			if (i.second > 0 and x > *t) {
				ans -= t->first;
				ans += x.first;
			}

			i.first->insert(x);
		}

		for (int o = 0; o < j.second; ++o) {
			auto t2 = j.first->find_by_order(j.first->size() - 1 - o);
			ans -= t2->first;

			i.second++;
			auto t = i.first->find_by_order(i.first->size() - i.second);
			ans += t->first;
		}

		return i;
	};

	auto mergb = [&](int i, int j) -> void {
		auto it1 = bi.upper_bound({min(i, j), {(ordered_set *)infty, 0}});
		auto it2 = it1;

		if (it1 == bi.end() or it1->first > max(i, j) or bi.begin() == it2) {
			return;
		}

		it2--;

		bi.insert({min(it1->first, it2->first), merges(it1->second, it2->second)});
		bi.erase(it1);
		bi.erase(it2);
	};

	auto merga = [&](int i, int j) -> void {
		auto it1 = --bi.upper_bound({j, Repr{(ordered_set *)infty, 0}});

		if (al[i] == -1) {
			bi.insert({it1->first, merges(it1->second, uno(a[i], 1))});
			al[i] = it1->first;
			bi.erase(it1);
		}
		else {
			mergb(j, al[i]);
		}
	};

	int bbp = 0;
	int aap = 0;

	for (int i = 0; i < q; ++i) {
		int k = qq[i].first;

		while (bbp < bb.size() and bb[bbp].first <= k) {
			mergb(bb[bbp].second, bb[bbp].second - 1);
			bbp++;
		}

		while (aap < aa.size() and aa[aap].first <= k) {
			merga(aa[aap].second.first, aa[aap].second.second);
			aap++;
		}

		qq[i].first = ans;
	}

	sort(qq.begin(), qq.end(), [](const auto & i, const auto & j) -> bool {
		return i.second < j.second;
	});

	for (int i = 0; i < q; ++i) {
		cout << qq[i].first << "\n";
	}
}