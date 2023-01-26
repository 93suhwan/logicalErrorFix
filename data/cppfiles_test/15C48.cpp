#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 1e2 + 10;
vector<long long> g[N];
void dfs(long long node, long long par, long long dd, vector<long long>& fre) {
  fre[dd]++;
  for (auto x : g[node])
    if (x != par) dfs(x, node, dd + 1, fre);
}
long long n, k;
long long get(vector<long long>& arr) {
  vector<long long> cur(k + 1, 0);
  cur[0] = 1;
  for (auto x : arr) {
    for (long long i = k; i >= 1; i--) {
      cur[i] += cur[i - 1] * x;
      cur[i] %= MOD;
    }
  }
  return cur[k];
}
long long solve(long long x) {
  long long sz = g[x].size();
  vector<vector<long long> > go(sz, vector<long long>(n + 1, 0));
  for (long long i = 0; i < sz; i++) dfs(g[x][i], x, 1, go[i]);
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    vector<long long> arr;
    for (auto v : go)
      if (v[i] > 0) arr.push_back(v[i]);
    res += get(arr);
    res %= MOD;
  }
  return res;
}
void solve() {
  cin >> n >> k;
  long long u, v;
  for (long long i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long res = 0;
  if (k == 2) {
    res = (n * (n - 1)) / 2;
    res %= MOD;
  } else {
    for (long long i = 1; i <= n; i++) {
      res += solve(i);
      res %= MOD;
    }
  }
  cout << res << '\n';
  for (long long i = 1; i <= n; i++) g[i].clear();
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
