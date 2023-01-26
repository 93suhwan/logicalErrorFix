#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(vector<bool>::reference b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename T = typename A::value_type>
string to_string(A v) {
	string res = "{";
	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);
	return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
using ll = long long;
using ld = long double;
const int MOD = 998244353;
struct Mint {
	int val;
	Mint() { val = 0; }
	Mint(ll x) {
		val = (-MOD <= x && x < MOD) ? x : x % MOD;
		if (val < 0) val += MOD;
	}
	template <typename U>
	explicit operator U() const { return (U)val; }
	friend bool operator==(const Mint& a, const Mint& b) { return a.val == b.val; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.val < b.val; }
	Mint& operator+=(const Mint& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Mint& operator-=(const Mint& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	Mint& operator*=(const Mint& m) { val = (ll)val * m.val % MOD; return *this; }
	friend Mint modex(Mint a, ll p) {
		assert(p >= 0);
		Mint ans = 1;
		for (; p; p >>= 1, a *= a) if (p & 1) ans *= a;
		return ans;
	}
	Mint& operator/=(const Mint& m) { return *this *= modex(m, MOD - 2); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	Mint operator++(int) { Mint result(*this); *this += 1; return result; }
	Mint operator--(int) { Mint result(*this); *this -= 1; return result; }
	Mint operator-() const { return Mint(-val); }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const Mint& x) { return os << x.val; }
	friend string to_string(const Mint& b) { return to_string(b.val); }
};
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	// Note: when casting y to unsigned x, x will be least unsigned int congruent to y mod 2^64.
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template <typename K, typename V>
using Hashmap = gp_hash_table<K, V, chash>;
int main() {
	int k, A, h;
	scanf("%d%d%d", &k, &A, &h);
	vector<Mint> powA(33);
	powA[0] = 1;
	for (int i = 1; i <= 32; ++i) powA[i] = powA[i - 1] * A;
	// 0..5 per person.
	array<Hashmap<int, ll>, 2> val;
	auto solve = [&](int rot, auto&& f) {
		int init = 1 + (rot << (k - 1));
		vector<int> p = {-1};
		for (int i = 0; i < k - 1; ++i) {
			for (int j = 0; j < (1 << i); ++j) p.push_back(i + 1);
		}
		db(p.size());
		do {
			bool bad = false;
			for (int b = 1; !bad && b < k; ++b) {
				for (int i = 0; !bad && i < p.size(); i += (1 << b)) {
					int num = 0;
					for (int j = i; j < i + (1 << b); ++j) num += p[j] == (k - b);
					if (num != 1) bad = true;
				}
			}
			if (bad) continue;
			Mint cur = 0;
			int z = -1;
			ll q = 0;
			for (int i = (int)p.size() - 1; i >= 0; --i) {
				cur += (init + i) * powA[p[i] == -1 ? 1 : 1 + (1 << p[i])];
				if (p[i] == -1) z = i;
				q <<= 3;
				q += p[i] + 1;
			}
			f(cur, q, 0);
			q += (1 << (3 * z));
			cur += (init + z) * (powA[2] - powA[1]);
			f(cur, q, 1);
		} while (next_permutation(p.begin(), p.end()));
	};
	solve(1, [&](Mint cur, ll q, int t) {
//		val[t].push_back({cur.val, q});
		val[t][cur.val] = q;
	});
	db(val[0].size());
	db(val[1].size());
//	for (int t = 0; t < 2; ++t) sort(val[t].begin(), val[t].end());
	solve(0, [&](Mint cur, ll q, int t) {
		auto& hay = val[1 - t];
		int need = (h - cur).val;
		auto it = hay.find(need);
//		auto it = lower_bound(hay.begin(), hay.end(), make_pair(need, 0LL));
		if (it == hay.end()) return;
//		if (it->first != need) return;
		ll tmp = q;
		for (int i = 0; i < (1 << (k - 1)); ++i) {
			int x = tmp % 8;
			printf("%d ", x == 0 ? 1 : 1 + (1 << (x - 1)));
			tmp >>= 3;
		}
		tmp = it->second;
		for (int i = 0; i < (1 << (k - 1)); ++i) {
			int x = tmp % 8;
			printf("%d ", x == 0 ? 1 : 1 + (1 << (x - 1)));
			tmp >>= 3;
		}
		printf("\n");
		exit(0);
	});
	printf("-1\n");
}

