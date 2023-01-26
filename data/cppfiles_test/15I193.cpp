#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
const long long maxn = 105;
vector<long long> a[maxn];
bool used[maxn];
long long l[maxn][maxn];
long long ans;
long long c;
long long k;
long long slv1(vector<long long> v, long long k) {
  long long dp[v.size() + 1][k + 1];
  for (long long i = 0; i <= v.size(); ++i)
    for (long long j = 0; j <= k; ++j) dp[i][j] = 0;
  dp[0][0] = 1;
  for (long long i = 0; i < v.size(); ++i)
    for (long long j = 0; j <= k; ++j) {
      if (j != k) {
        dp[i + 1][j + 1] += (dp[i][j] * v[j]);
        dp[i + 1][j + 1] %= p;
      }
      {
        dp[i + 1][j] += (dp[i][j]);
        dp[i + 1][j] %= p;
      }
    }
  return dp[v.size()][k];
}
void dfs(long long x) {
  for (long long i = 0; i < maxn; ++i) l[x][i] = 0;
  l[x][0]++;
  used[x] = true;
  vector<long long> z;
  for (auto v : a[x]) {
    if (used[v]) continue;
    dfs(v);
    z.push_back(v);
    for (long long i = 0; i < maxn; ++i) l[x][i + 1] += l[v][i];
  }
  used[x] = false;
  if (x == c) {
    for (long long i = 0; i < maxn; ++i) {
      vector<long long> v;
      for (auto h : z) {
        v.push_back(l[h][i]);
      }
      long long o = slv1(v, k);
      ans += o;
      ans %= p;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n >> k;
    ans = 0;
    for (long long i = 0; i < maxn; ++i) {
      a[i].clear();
      used[i] = false;
    }
    for (long long i = 0; i < (n - 1); ++i) {
      long long x, y;
      cin >> x >> y;
      x--;
      y--;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << endl;
      continue;
    }
    for (long long i = 0; i < n; ++i) {
      c = i;
      dfs(i);
    }
    cout << ans << endl;
  }
  return 0;
}
