#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;
ll binpow(ll a, ll p, int mod = MOD) {
  ll res = 1;
  a %= mod;
  while (p) {
    if (p & 1) {
      (res *= a) %= mod;
    }
    p >>= 1;
    (a *= a) %= mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 1e6 + 5;
int p[N * 2];
int getRoot(int v) { return p[v] == v ? v : p[v] = getRoot(p[v]); }
void unite(int v, int u) { p[getRoot(v)] = getRoot(u); }
void solve() {
  vector<int> lp(N);
  for (int i = 2; i < N; i++) {
    if (lp[i]) continue;
    for (int j = i; j < N; j += i) {
      if (!lp[j]) lp[j] = i;
    }
  }
  iota(p, p + N * 2, 0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      unite(i, n + lp[x]);
      x /= lp[x];
    }
  }
  set<pair<int, int>> setik;
  for (int i = 0; i < n; i++) {
    int x = a[i] + 1;
    while (x > 1) {
      setik.insert({getRoot(i), getRoot(n + lp[x])});
      setik.insert({getRoot(n + lp[x]), getRoot(i)});
      x /= lp[x];
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    s = getRoot(s - 1);
    t = getRoot(t - 1);
    if (s == t) {
      cout << "0\n";
    } else if (setik.count({s, t})) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  for (int tc = 1; tc <= T; tc++) {
    solve();
  }
  return 0;
}
