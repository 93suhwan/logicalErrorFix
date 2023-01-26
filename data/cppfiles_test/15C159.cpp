#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
long long gcd(long long i, long long j) {
  if (j == 0)
    return i;
  else
    return gcd(j, i % j);
}
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
const long long INF = 1e18 + 100;
const int mod = 1000000007;
const long double eps = 1e-10, pi = acosl(-1);
const long long maxN = 200010, maxT = 25000, A = 179, mid = 150;
mt19937 mt_rand(time(0));
long long bp(long long et, long long b) {
  b %= mod - 1;
  long long res = 1;
  for (int i = 30; i >= 0; --i) {
    res = (res * res) % mod;
    if ((b & (1 << i)) != 0) res = (res * et) % mod;
  }
  return res;
}
void panic() {
  cout << "-1\n";
  exit(0);
}
vector<vector<int>> g;
vector<int> cnt;
void dfs(int v, int d, int p = -1) {
  ++cnt[d];
  for (auto x : g[v]) {
    if (x == p) continue;
    dfs(x, d + 1, v);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  g.assign(n, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << "\n";
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i) dp[i][0] = 1;
    for (auto x : g[i]) {
      cnt.assign(n, 0);
      dfs(x, 1, i);
      for (int d = 0; d < n; ++d) {
        if (cnt[d] == 0) continue;
        for (int j = k - 1; j >= 0; --j) {
          dp[d][j + 1] = (dp[d][j + 1] + (long long)cnt[d] * dp[d][j]) % mod;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      ans = (ans + dp[i][k]) % mod;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
