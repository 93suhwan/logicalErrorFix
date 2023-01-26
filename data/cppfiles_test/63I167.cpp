#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long INF = -9999999999999;
const int maxn = 1000006;
const int maxm = 1000006;
const int ox3f = 1061109567;
const int fox3f = -2139062144;
const long long ox3fll = 4557430888798830399;
int n, m, t, T;
struct Node {
  int first, second;
};
int f[2][2000];
int cnt[2];
int find(int x, int i) { return f[i][x] == x ? x : f[i][x] = find(f[i][x], i); }
void merge(int x, int y, int i) {
  int u = find(x, i);
  int v = find(y, i);
  if (u == v) return;
  cnt[i]--;
  f[i][y] = u;
}
void solve() {
  int m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) f[0][i] = i, f[1][i] = i;
  vector<Node> ans;
  cnt[1] = cnt[0] = n;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v, 0);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v, 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int u = find(i, 0), v = find(j, 0);
      if (u == v) continue;
      u = find(i, 1), v = find(j, 1);
      if (u == v) continue;
      merge(i, j, 0);
      merge(i, j, 1);
      ans.push_back({i, j});
    }
  }
  if (cnt[0] == 0 || cnt[1] == 0) {
    if (ans.size() == 0) {
      cout << 0 << endl;
      return;
    }
    ans.pop_back();
  }
  cout << ans.size() << endl;
  for (auto& an : ans) {
    cout << an.first << " " << an.second << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
