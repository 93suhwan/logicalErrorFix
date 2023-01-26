#include <bits/stdc++.h>
using namespace std;
int r[8192];
vector<int> g[8192];
int ans[8192] = {
    0,
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  ans[0] = 1;
  for (int i = 0; i < 8192; i++) {
    g[i].push_back(0);
  }
  for (int i = 0; i < 8192; i++) {
    r[i] = 8192;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (const auto& key : g[x]) {
      int to = (key ^ x);
      ans[to] = 1;
      while (--r[to] > x) {
        g[r[to]].emplace_back(to);
      }
    }
    g[x].clear();
  }
  int cnt = 0;
  for (int i = 0; i < 8192; i++) {
    cnt += ans[i];
  }
  cout << cnt << "\n";
  for (int i = 0; i < 8192; i++) {
    if (ans[i]) cout << i << " ";
  }
  cout << "\n";
}
