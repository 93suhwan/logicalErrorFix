#include <stdio.h>
#include <assert.h>

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;


template <class T>
void Output(const T& v, bool print_new_line = true) {
	bool first = true;
	for (auto element : v) {
		if (!first)
			cout << " ";
		else
			first = false;
		cout << element;
	}
	if (print_new_line) cout << endl;
}

template <class T>
void Input(vector<T>& v, int n) {
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
}

template <class T>
vector<int> Query(const T& c, int answer_counts) {
	cout << "? " << c.size();
	for (auto it = c.begin(); it != c.end(); ++it) {
		cout << " " << (*it);
	}
	cout << endl;
	cout.flush();
	vector<int> s(answer_counts);
	for (int i = 0; i < answer_counts; ++i) {
		cin >> s[i];
	}
	return s;
}

#define MULTIPLE_CASES 1

/******** problem code  *********/

void GetFactorAndIfac(int n, int module, std::vector<int>& fac, std::vector<int>& ifac) {
    std::vector<int> inv(n + 1);
    fac.resize(n + 1);
    ifac.resize(n + 1),
        inv[1] = ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = (long long)fac[i - 1] * i % module;
        inv[i] = (long long)(module - module / i) * inv[module % i] % module;
        ifac[i] = (long long)ifac[i - 1] * inv[i] % module;
    }
}

const int M = 998244353;
int main() {
    ordered_set<int> s;
	for (int i = 0; i < 200000; ++i) {
		s.insert(i);
	}

	vector<int> fac, ifac;
    GetFactorAndIfac(200000, M, fac, ifac);

#if MULTIPLE_CASES
	int case_number;
	cin >> case_number;
	for (int case_index = 0; case_index < case_number; ++case_index) {
#endif
        int n, m;
        cin >> n >> m;
		vector<int> x(m), y(m);
		for (int i = 0; i < m; ++i) {
			cin >> x[i] >> y[i];
			--x[i];
			--y[i];
		}
		unordered_set<int> f;
		vector<int> st;
		for (int i = m - 1; i >= 0; --i) {
			auto it = s.find_by_order(y[i]);
			if (it != s.end()) {
				auto it2 = it;
				++it2;
				f.insert(*it2);
			}
			st.push_back(*it);
			s.erase(it);
		}

		cout << (long long)fac[n + n - 1 - f.size()] * ifac[n] % M * ifac[n - 1 - f.size()] % M << endl;
		
		for (auto sv : st) {
			s.insert(sv);
		}
#if MULTIPLE_CASES
	}
#endif
	return 0;
}