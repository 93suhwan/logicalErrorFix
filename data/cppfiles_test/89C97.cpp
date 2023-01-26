#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int T, n, ans, cnt[MAXN];
vector<int> e[MAXN];
void dfs(int u, int fa) {
  for (auto v : e[u]) {
    if (v == fa) continue;
    dfs(v, u);
    if (cnt[v] == 0) cnt[u]++;
  }
}
void solve() {
  ans = 0;
  cin >> n;
  for (int i = (1); i <= (n); i++) e[i].clear(), cnt[i] = 0;
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  ans = cnt[1];
  for (int i = (2); i <= (n); i++) {
    if (cnt[i] != 0) {
      if (ans)
        ans += cnt[i] - 1;
      else
        ans += cnt[i];
    }
  }
  printf("%d\n", ans);
}
int main() {
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
