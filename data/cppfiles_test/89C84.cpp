#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 998244353;
const double eps = 1e-10;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<int> G[maxn], gg;
int p[maxn];
void dfs(int u, int fa) {
  if (u == 1)
    p[u] = G[u].size();
  else
    p[u] = G[u].size() - 1;
  for (auto v : G[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
  if (p[u]) {
    p[fa]--;
    gg.push_back(p[u]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    gg.clear();
    p[0] = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, 0);
    int miao = 0;
    for (auto x : gg) {
      if (miao == 0)
        miao += x;
      else
        miao += (x - 1);
    }
    cout << miao << endl;
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      p[i] = 0;
    }
  }
  return ~~(0 - 0);
}
