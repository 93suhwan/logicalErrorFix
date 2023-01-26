#include <bits/stdc++.h>
using namespace std;
long long n, ch[200200], ans;
bool isb[200200], isl[200200], rem[200200];
vector<vector<long long>> g;
void dfs(long long node, long long par) {
  bool flag = 1, allbuds = 1;
  for (auto v : g[node]) {
    if (v == par) continue;
    dfs(v, node);
    if (isb[v]) continue;
    if (isl[v] == 0) flag = 0;
    if (isb[v] == 0) allbuds = 0;
    ch[node]++;
  }
  if (ch[node] == 0 and par) isl[node] = 1;
  if (ch[node] and flag and par) isb[node] = 1;
}
void solve() {
  ans = 0;
  g.clear();
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    isb[i] = isl[i] = ch[i] = rem[i] = 0;
  }
  dfs(1, 0);
  ans = n;
  for (int i = 1; i <= n; i++) {
    if (isb[i]) ans -= 2;
  }
  for (auto v : g[1]) {
    if (isl[v]) {
      ans--;
      break;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
