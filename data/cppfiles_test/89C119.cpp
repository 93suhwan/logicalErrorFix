#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    cout << '\n';
  }
  return 0;
}
bool bud[200005];
int cnt = 0;
vector<int> V[200005];
void dfs(int now, int from) {
  for (int x : V[now]) {
    if (x == from) {
      continue;
    }
    dfs(x, now);
  }
  if (now == 1) {
    return;
  }
  for (int x : V[now]) {
    if (x == from) {
      continue;
    }
    bud[now] |= !bud[x];
  }
  cnt += bud[now];
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    V[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  memset(bud, 0, sizeof(bud));
  cnt = 0;
  dfs(1, 0);
  int res = (n - cnt - 1) - (cnt - 1);
  bool yes = false;
  for (int x : V[1]) {
    yes |= !bud[x];
  }
  res -= yes;
  cout << res;
}
