#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 5;
inline long long pow_mod(long long x, long long n, long long MOD = ::MOD) {
  n %= (MOD - 1);
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return res;
}
int n, m;
class FenwickTree {
  int n;
  vector<int> bit;

 public:
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }
  FenwickTree(vector<int> &a) : FenwickTree((int)a.size()) {
    for (int i = 1; i <= n; i++) update(i, a[i - 1]);
  }
  inline void update(int idx, int delta) {
    while (idx <= n) {
      bit[idx] = (bit[idx] + delta) % m;
      idx += (idx & -idx);
    }
  }
  inline void range_update(int l, int r, int delta) {
    update(l, delta);
    update(r + 1, -delta);
  }
  inline int sum(int idx) {
    int res = 0;
    while (idx > 0) {
      res = (res + bit[idx]) % m;
      idx -= (idx & -idx);
    }
    return res;
  }
};
FenwickTree t(N);
inline void solve() {
  cin >> n >> m;
  long long curr = 1, prev = 0;
  for (int i = 1; i <= n; i++) {
    if (i ^ 1) curr = t.sum(i);
    curr = (curr + prev) % m;
    for (int j = 2; i * j <= n; j++)
      t.range_update(i * j, min(n, i * j + j - 1), curr);
    prev = (prev + curr) % m;
  }
  curr = (curr + m) % m;
  cout << curr;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
}
