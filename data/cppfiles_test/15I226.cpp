#include <bits/stdc++.h>
using namespace std;
long long TC;
long long N, K, a, b;
vector<long long> adj[101], B[101];
long long twok[101][10];
void dfs(long long x, long long p, long long d) {
  B[d].push_back(x);
  twok[x][0] = p;
  for (long long i = 1; i <= long long(9); ++i) {
    if (twok[x][i - 1] == -1) break;
    twok[x][i] = twok[twok[x][i - 1]][i - 1];
  }
  for (auto i : adj[x])
    if (i != p) dfs(i, x, d + 1);
}
long long kpar(long long x, long long k) {
  for (long long i = 0; i <= long long(9); ++i)
    if (k & (1 << i)) x = twok[x][i];
  return x;
}
long long C[101];
long long qexp(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) (res *= x) %= 1000000007;
    y >>= 1;
    (x *= x) %= 1000000007;
  }
  return res;
}
long long dp[101][101];
long long getnum(vector<long long> &v, long long k) {
  if (k > v.size()) return 0;
  for (long long i = 0; i <= long long(v.size() - 1); ++i)
    for (long long j = 0; j <= long long(k); ++j) {
      if (j == 0)
        dp[i][j] = 0;
      else if (i + 1 < j)
        dp[i][j] = 0;
      else if (i == 0)
        dp[i][j] = v[i];
      else
        dp[i][j] = (((v[i] * dp[i - 1][j - 1]) % 1000000007) + dp[i - 1][j]) %
                   1000000007;
    }
  return dp[v.size() - 1][k];
}
void solve() {
  cin >> N >> K;
  for (long long i = 1; i <= long long(N); ++i) adj[i].clear();
  for (long long i = 1; i <= long long(N - 1); ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (K == 2) {
    cout << (N * (N - 1)) / 2 << '\n';
    return;
  }
  long long ans = 0;
  for (long long i = 1; i <= long long(N); ++i) {
    for (long long j = 0; j <= long long(N - 1); ++j) B[j].clear();
    memset(twok, -1, sizeof twok);
    dfs(i, -1, 0);
    for (long long c = 2; c < N; c += 2) {
      for (auto j : B[c]) {
        C[kpar(j, c / 2 - 1)]++;
      }
      for (auto j : B[c / 2]) {
        vector<long long> v;
        for (auto k : adj[j])
          if (k != twok[j][0])
            if (C[k] > 0) v.push_back(C[k]);
        ans += getnum(v, K - 1);
        ans %= 1000000007;
      }
      for (auto j : B[c]) {
        C[kpar(j, c / 2 - 1)] = 0;
      }
    }
  }
  cout << (ans * qexp(K, 1000000007 - 2)) % 1000000007 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> TC;
  for (long long i = 1; i <= long long(TC); ++i) solve();
}
