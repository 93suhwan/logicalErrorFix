#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void _do(T x) {
  cerr << x << "\n";
}
template <typename T, typename... U>
void _do(T x, U... y) {
  cerr << x << ", ";
  _do(y...);
}
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 3e18;
const long double PI = atan(1) * 4;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fpow(long long a, long long b, long long m) {
  if (!b) return 1;
  long long ans = fpow(a * a % m, b / 2, m);
  return (b % 2 ? ans * a % m : ans);
}
long long inv(long long a, long long m) { return fpow(a, m - 2, m); }
vector<pair<long long, long long> > ed[200005];
long long id[200005], cnt = 0, tmp = 0;
bool can = 1;
void dfs(long long n, long long c) {
  tmp++;
  if (c == 2) cnt++;
  id[n] = c;
  for (pair<long long, long long> u : ed[n]) {
    long long x = (u.second ? 3 - c : c);
    if (id[u.first] == 0)
      dfs(u.first, x);
    else if (id[u.first] != x)
      can = 0;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      ed[i].clear();
      id[i] = 0;
    }
    can = 1;
    for (long long i = 0; i < m; i++) {
      long long u, v;
      string s;
      cin >> u >> v >> s;
      bool w = 0;
      if (s == "imposter") w = 1;
      ed[u].push_back({v, w});
      ed[v].push_back({u, w});
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      if (id[i] != 0) continue;
      cnt = tmp = 0;
      dfs(i, 1);
      if (!can) break;
      ans += max(cnt, tmp - cnt);
    }
    if (can)
      cout << ans << "\n";
    else
      cout << "-1\n";
  }
}
