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
map<long long, vector<long long> > g;
vector<long long> col[7];
map<long long, long long> m;
map<pair<long long, long long>, long long> dp;
long long f(long long node, long long c) {
  if (m.count(node) && m[node] != c) return 0;
  if (dp.count({node, c})) return dp[{node, c}];
  long long sum[2] = {};
  for (auto i : col[c]) {
    for (long long j = 0; j < (long long)(g[node]).size(); j++) {
      sum[j] = add(sum[j], f(g[node][j], i));
    }
  }
  if ((long long)(g[node]).size() < 2) sum[1] = 1;
  if ((long long)(g[node]).size() < 1) sum[0] = 1;
  return dp[{node, c}] = mul(sum[0], sum[1]);
}
void solve() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  long long ans, cnt = (1ll << n) - 1;
  col[1] = {3, 4, 5, 6};
  col[2] = {3, 4, 5, 6};
  col[3] = {1, 2, 5, 6};
  col[4] = {1, 2, 5, 6};
  col[5] = {3, 4, 1, 2};
  col[6] = {3, 4, 1, 2};
  for (__typeof(k) i = (0) - ((0) > (k)); i != (k) - ((0) > (k));
       i += 1 - 2 * ((0) > (k))) {
    long long x;
    cin >> x;
    string s;
    cin >> s;
    if (s[0] == 'w')
      m[x] = 1;
    else if (s[0] == 'y')
      m[x] = 2;
    else if (s[0] == 'g')
      m[x] = 3;
    else if (s[0] == 'b')
      m[x] = 4;
    else if (s[0] == 'r')
      m[x] = 5;
    else
      m[x] = 6;
  }
  set<long long> S;
  for (auto [x, s] : m) {
    if (m.count(x / 2) && s == m[x / 2]) {
      cout << 0;
      return;
    }
    long long t = x;
    while (t / 2 > 0) {
      S.insert(t / 2);
      if (g[t / 2].empty())
        g[t / 2].push_back(t);
      else if ((long long)(g[t / 2]).size() < 2) {
        if (g[t / 2][0] != t) g[t / 2].push_back(t);
      }
      t /= 2;
    }
    S.insert(x);
  }
  cnt -= (long long)(S).size();
  ans = power(4, cnt);
  long long t = 0;
  for (__typeof(7) i = (1) - ((1) > (7)); i != (7) - ((1) > (7));
       i += 1 - 2 * ((1) > (7)))
    t = add(t, f(1, i));
  ans = mul(ans, t);
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  solve();
  return 0;
}
