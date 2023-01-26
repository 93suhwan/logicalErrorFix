#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long long mod2 = 998244353;
const long long N = 1000 + 10;
const long double pi = 3.141592653589793;
long long power(long long x, long long y, long long p = LLONG_MAX) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long ncr(long long n, long long r, long long m) {
  if (r > n) return 0;
  long long a = 1, b = 1, i;
  for (i = 0; i < r; i++) {
    a = (a * n) % m;
    --n;
  }
  while (r) {
    b = (b * r) % m;
    --r;
  }
  return (a * power(b, m - 2, m)) % m;
}
long long a[N][N], n, m, vis[N][N], cnt;
void dfs(long long i, long long j) {
  if (i > n || j > m) return;
  if (i <= 0 || j <= 0) return;
  if (vis[i][j]) return;
  cnt++;
  vis[i][j] = 1;
  if (!vis[i - 1][j] && !(a[i][j] & 8)) dfs(i - 1, j);
  if (!vis[i + 1][j] && !(a[i][j] & 2)) dfs(i + 1, j);
  if (!vis[i][j - 1] && !(a[i][j] & 1)) dfs(i, j - 1);
  if (!vis[i][j + 1] && !(a[i][j] & 4)) dfs(i, j + 1);
}
void solve() {
  cin >> n >> m;
  vector<long long> p;
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < m + 1; j++) cin >> a[i][j];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (vis[i][j] == 0) {
        cnt = 0;
        dfs(i, j);
        p.push_back(cnt);
      }
    }
  }
  sort(p.begin(), p.end(), greater<long long>());
  for (auto i : p) {
    cout << i << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
