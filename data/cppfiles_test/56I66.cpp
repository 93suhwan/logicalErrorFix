#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) { return (rng() % (y - x + 1)) + x; };
const long long mod = (long long)1e9 + 7;
const long long MOD = (long long)998244353;
const long long INF = (long long)1e9;
inline long long add(long long a, long long b) {
  return (a + b >= mod ? a + b - mod : a + b);
}
inline long long mul(long long a, long long b) {
  return (long long)a * b % mod;
}
long long power(long long a, long long n) {
  if (n == 0) return 1;
  long long p = power(a, n / 2);
  p = mul(p, p);
  return n & 1 ? mul(p, a) : p;
}
long long mbit(long long x) {
  long long mx = 0;
  for (__typeof(61) i = (0) - ((0) > (61)); i != (61) - ((0) > (61));
       i += 1 - 2 * ((0) > (61)))
    if ((x >> i) & 1) mx = i + 1;
  return mx;
}
void solve() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  long long ans = 6;
  map<long long, long long> m;
  map<long long, set<long long>> S;
  for (__typeof(k) i = (0) - ((0) > (k)); i != (k) - ((0) > (k));
       i += 1 - 2 * ((0) > (k))) {
    long long x;
    cin >> x;
    string s;
    cin >> s;
    if (s[0] == 'y' || s[0] == 'w')
      m[x] = 1;
    else if (s[0] == 'g' || s[0] == 'b')
      m[x] = 2;
    else
      m[x] = 3;
    if (x == 1)
      ans = mul(ans, power(6, mod - 2));
    else
      ans = mul(ans, power(4, mod - 2));
  }
  for (long long i = 2; i <= n; ++i) {
    ans = mul(ans, power(4, 1ll << (i - 1)));
  }
  for (auto [x, s] : m) {
    if (m.count(2 * x) && s == m[2 * x]) {
      cout << 0;
      return;
    }
    if (m.count(2 * x + 1) && s == m[2 * x + 1]) {
      cout << 0;
      return;
    }
    if (x / 2 && !m.count(x / 2)) S[x / 2].insert(s);
    if (mbit(2 * x) <= n && !m.count(2 * x)) S[2 * x].insert(s);
    if (mbit(2 * x + 1) <= n && !m.count(2 * x + 1)) S[2 * x + 1].insert(s);
  }
  for (auto [x, s] : S) {
    if (x == 1)
      ans = mul(ans, power(6, mod - 2));
    else
      ans = mul(ans, power(4, mod - 2));
    ans = mul(ans, 6 - 2 * (long long)(s).size());
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  solve();
  return 0;
}
