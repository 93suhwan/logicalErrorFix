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
const long double PI = 3.14159265358979323846;
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
const long long N = 3e5 + 5;
long long c[N], cnt[N], len[N], dp[N];
vector<long long> a[N], ed[N], re[N];
bool bad[N], vis[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> c[i];
    bool x = 1;
    for (long long j = 0; j < c[i]; j++) {
      long long u;
      cin >> u;
      a[i].push_back(u);
      cnt[u]++;
      if (cnt[u] > 1 || bad[u]) x = 0;
    }
    for (long long j = 0; j < c[i]; j++) {
      cnt[a[i][j]]--;
      if (!x)
        bad[a[i][j]] = 1;
      else if (j > 0) {
        ed[a[i][j - 1]].push_back(a[i][j]);
        re[a[i][j]].push_back(a[i][j - 1]);
      }
    }
  }
  for (long long i = 1; i <= k; i++) {
    sort(ed[i].begin(), ed[i].end()),
        ed[i].resize(
            distance(ed[i].begin(), unique(ed[i].begin(), ed[i].end())));
    sort(re[i].begin(), re[i].end()),
        re[i].resize(
            distance(re[i].begin(), unique(re[i].begin(), re[i].end())));
    if (ed[i].size() > 1 || re[i].size() > 1) bad[i] = 1;
  }
  for (long long i = 1; i <= k; i++) {
    if (bad[i] || vis[i] || re[i].size() != 0) continue;
    long long cur = i, tmp = 0;
    bool x = 1;
    while (1) {
      vis[cur] = 1, tmp++;
      if (bad[cur]) {
        x = 0;
        break;
      }
      if (ed[cur].size() == 0) break;
      cur = ed[cur][0];
    }
    if (x) len[tmp]++;
  }
  vector<pair<long long, long long> > v;
  for (long long i = 1; i <= k; i++)
    if (len[i] > 0) v.push_back({i, len[i]});
  dp[0] = 1;
  for (long long i = 1; i <= m; i++) {
    for (pair<long long, long long> p : v) {
      if (i < p.first) break;
      dp[i] = (dp[i] + dp[i - p.first] * p.second % MOD2) % MOD2;
    }
  }
  cout << dp[m];
}
