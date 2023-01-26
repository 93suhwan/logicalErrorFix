#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 9;
vector<long long> g[maxn];
long long n, cnt_p, cnt_l;
long long dfs(long long v, long long pr) {
  long long cur = 0;
  for (long long to : g[v]) {
    if (to == pr) continue;
    cur += dfs(to, v);
  }
  cnt_l += cur;
  if (v == 0) {
    if (cur >= 1) {
      cout << cnt_l - cnt_p << "\n";
    } else {
      cout << cnt_l - cnt_p + 1 << "\n";
    }
    return 0;
  }
  if (cur >= 1) {
    cnt_p++;
    return 0;
  }
  return 1;
}
void solve() {
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  cnt_p = 0, cnt_l = 0;
  dfs(0, -1);
  for (long long i = 0; i < n; i++) {
    g[i].resize(0);
    g[i].shrink_to_fit();
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
