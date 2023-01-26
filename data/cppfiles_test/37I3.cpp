#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 998244353;
int n;
vector<int> dsk[N];
long long f[N];
int cur[N];
bool ok = 1;
void dfs(int u, int pre, int val) {
  if (((int)(dsk[u]).size()) == 1) {
    cur[u] = 1;
    return;
  }
  for (int v : dsk[u])
    if (v != pre) {
      dfs(v, u, val);
      cur[u] += cur[v];
    }
  if (cur[u] % val == 0)
    cur[u] = 1;
  else if (u != pre && (cur[u] + 1) % val == 0)
    cur[u] = 0;
  else
    ok = 0;
}
int solve(int val) {
  for (int i = 1; i <= n; ++i) cur[i] = 0;
  ok = 1;
  dfs(1, 1, val);
  return ok;
}
void gogo() {
  cin >> n;
  for (int i = 1; i <= n; ++i) dsk[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    dsk[u].push_back(v);
    dsk[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) f[i] = 0;
  f[1] = 1;
  for (int i = 1; i < n; ++i) (f[1] *= 2) %= mod;
  for (int i = 2; i <= n - 1; ++i)
    if ((n - 1) % i == 0) f[i] = solve(i);
  for (int i = n; i >= 1; --i)
    for (int j = 2 * i; j <= n; j += i) f[i] = (f[i] - f[j] + mod) % mod;
  for (int i = 1; i <= n; ++i) cout << f[i] << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("sol"
            ".inp",
            "r")) {
    freopen(
        "sol"
        ".inp",
        "r", stdin);
    freopen(
        "sol"
        ".out",
        "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) gogo();
}
