#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int ffa[maxn];
int n;
vector<int> es[maxn];
int typ[maxn];
void dfs(int now, int fa) {
  int leaf = 0;
  for (auto to : es[now]) {
    if (to == fa) continue;
    ffa[to] = now;
    dfs(to, now);
    if (typ[to] == 0) leaf += 1;
  }
  typ[now] = leaf;
  ;
}
void solve() {
  int one = 0;
  int two = 0;
  int two_num = 0;
  for (int i = 2; i <= n; i++)
    if (ffa[i] == 1 && typ[i] == 0)
      one++;
    else if (typ[i] > 0)
      two += typ[i], two_num += 1;
  ;
  int ans = two - two_num + one;
  if (one == 0) ans += 1;
  cout << ans << '\n';
}
void I() {
  for (int i = 1; i <= n; i++) es[i].clear();
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    I();
    for (int i = 1; i <= n - 1; i++) {
      int a, b;
      cin >> a >> b;
      es[a].push_back(b);
      es[b].push_back(a);
    }
    dfs(1, -1);
    solve();
  }
  return 0;
}
