#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x7f7f7f7f7f7f7f7f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
int t, n, m, p[N];
vector<int> a[N];
multiset<int> B[N], R[N];
char ans[N];
bool pr[N], sf[N];
bool cmp(int x, int y) { return a[x][1] < a[y][1]; }
void rev(int i) {
  for (int j = 1; j <= m; j++) {
    R[j].erase(R[j].find(a[i][j]));
    B[j].insert(a[i][j]);
  }
}
int check() {
  for (int i = 1; i <= m; i++) sf[i] = pr[i] = 0;
  int mx = -inf, mn = inf;
  for (int i = 1; i <= m; i++) {
    mn = min(mn, *R[i].begin());
    mx = max(mx, *--B[i].end());
    if (mx < mn) pr[i] = 1;
  }
  mx = -inf, mn = inf;
  for (int i = m; i; i--) {
    mn = min(mn, *B[i].begin());
    mx = max(mx, *--R[i].end());
    if (mx < mn) sf[i] = 1;
  }
  for (int i = 1; i < m; i++)
    if (pr[i] && sf[i + 1]) return i;
  return 0;
}
void solve() {
  for (int i = 1; i <= n; i++) p[i] = i, ans[i] = 'R';
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i < n; i++) {
    int u = p[i];
    rev(u);
    ans[u] = 'B';
    int res = check();
    if (res) {
      cout << "YES" << '\n';
      for (int j = 1; j <= n; j++) cout << ans[j];
      cout << " " << res << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      a[i].push_back(0);
      for (int j = 1, x; j <= m; j++) {
        cin >> x, a[i].push_back(x);
        R[j].insert(x);
      }
    }
    solve();
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i <= m; i++) B[i].clear(), R[i].clear();
  }
  return 0;
}
