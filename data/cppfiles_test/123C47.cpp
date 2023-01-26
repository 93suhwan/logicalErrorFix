#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
std::vector<std::vector<int> > g;
std::vector<int> dd;
int dfs(int v, int p) {
  int ret = 0;
  std::vector<int> d;
  for (auto u : g[v]) {
    if (u != p) d.push_back(dfs(u, v) + 1);
  }
  sort((d).begin(), (d).end());
  reverse((d).begin(), (d).end());
  while (d.size() > 1) {
    dd.push_back(d.back());
    d.pop_back();
  }
  if (!d.empty()) ret = d[0];
  if (v == 0) dd.push_back(ret + 1);
  return ret;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  sort((dd).begin(), (dd).end());
  reverse((dd).begin(), (dd).end());
  long long ans = -1e18;
  int mb = n;
  for (int tk = 0; tk < k + 1; tk++) {
    if (mb <= tk)
      ans = max(ans, long long(tk - mb) * (n - tk - mb));
    else {
      int madd = min((n - 2 * tk) / 2, mb - tk);
      ans = max(ans, long long(-madd) * (n - 2 * tk - madd));
    }
    if (tk < dd.size()) mb -= dd[tk];
  }
  cout << ans;
}
