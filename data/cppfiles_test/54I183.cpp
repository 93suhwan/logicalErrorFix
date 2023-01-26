#include <bits/stdc++.h>
using namespace std;
mt19937 gen(239);
const long long N = 2e5 + 5, mod = 1e9 + 7;
long long c[N], cnt, one;
vector<pair<long long, long long>> g[N];
bool bipart;
void dfs(long long i, long long cur) {
  c[i] = cur;
  cnt++;
  one += cur;
  for (auto [to, w] : g[i]) {
    if (c[to] == -1) {
      dfs(to, (cur + w) & 1);
    } else if (c[to] != (cur + w) % 2) {
      bipart = false;
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  fill(g, g + n + 1, vector<pair<long long, long long>>());
  fill(c, c + n + 1, -1);
  bipart = true;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    string s;
    cin >> s;
    if (s == "imposter") {
      g[u].push_back({v, 1});
      g[v].push_back({u, 1});
    } else {
      g[u].push_back({v, 0});
      g[v].push_back({u, 0});
    }
  }
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    if (c[i] == -1) {
      cnt = one = 0;
      dfs(1, 0);
      if (!bipart) {
        cout << -1 << '\n';
        return;
      }
      res += max(one, cnt - one);
    }
  }
  cout << res << '\n';
}
signed main() {
  cout << setprecision(12) << fixed;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
}
