#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int tt, n, lf, bd;
bool tk[maxn];
vector<int> E[maxn];
void dfs(int nd, int pr) {
  int cnt = 0;
  for (auto i : E[nd]) {
    if (i != pr) {
      dfs(i, nd);
      if (!tk[i]) cnt++;
    }
  }
  if (!cnt)
    lf++;
  else {
    tk[nd] = 1;
    if (nd != 1) bd++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n;
    lf = bd = 0;
    for (int i = 1; i <= n; i++) E[i].clear(), tk[i] = 0;
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      E[x].push_back(y);
      E[y].push_back(x);
    }
    dfs(1, 0);
    cout << lf - bd << '\n';
  }
}
