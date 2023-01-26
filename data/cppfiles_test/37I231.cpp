//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<cmath>
#include<unordered_set>
#include<numeric>
#include<set>
#include<memory>
#include<deque>
#include<array>
#include<map>
#include<queue>
#include<unordered_map>
#include<iterator>
#include<stack>
#include<fstream>
#include<sstream>
#include<bitset>
#include<random>
#include<ranges>
using namespace std;

const int64_t mod = 998244353;

int64_t bin_pow(int64_t n, int64_t p) {
	if (p < 0) {
		return 0;
	}
	int64_t result = 1;
	int64_t powered = n;
	for (int64_t i = 0; (p >> i) > 0; ++i) {
		if ((p >> i) & 1) {
			result *= powered;
			if (result >= mod) {
				result %= mod;
			}
		}
		powered *= powered;
		if (powered >= mod) {
			powered %= mod;
		}
	}
	return result;
}

int64_t divm(int64_t lhs, int64_t rhs) {
	lhs *= bin_pow(rhs, mod - 2);
	lhs %= mod;
	return lhs;
}

int64_t diffm(int64_t lhs, int64_t rhs) {
	return lhs - rhs + mod * (lhs < rhs);
}

int64_t addm(int64_t lhs, int64_t rhs) {
	return lhs + rhs - mod * (lhs + rhs >= mod);
}

vector<int64_t> fact(2000);
vector<int64_t> rev_fact(2000);

void pre_calc() {
	fact[0] = 1;
	rev_fact[0] = bin_pow(fact[0], mod - 2);
	for (int64_t i = 1; i < fact.size(); ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
		rev_fact[i] = bin_pow(fact[i], mod - 2);
	}
}

int64_t comb(int64_t n, int64_t k) {
	return divm(fact[n], (fact[k] * fact[n - k]) % mod);
}


void solve(istream& cin, ostream& cout) {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> amount(n, 0);
	for (size_t i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		++amount[b];
	}
	auto it = ranges::find(amount, 0);
	int ind = it - amount.begin();
	for (size_t i = 0; i < n; ++i) {
		if (i != ind) {
			cout << i+1 << " " << ind+1 << "\n";
		}
	}
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve(cin, cout);
	return 0;
}