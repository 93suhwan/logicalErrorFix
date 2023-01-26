#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> g[maxn];
vector<int> ans;
vector<int> used;
bool cycles(int v) {
  used[v] = 1;
  for (auto u : g[v]) {
    if (used[u] == 1) return true;
    if (used[u] != 2) {
      bool cyc = cycles(u);
      if (cyc) return true;
    }
  }
  used[v] = 2;
  return false;
}
void calcAns(int v) {
  used[v] = true;
  ans[v] = 1;
  for (auto u : g[v]) {
    if (!used[u]) calcAns(u);
    ans[v] = max(ans[v], ans[u] + (u < v));
  }
}
void solveC() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int v;
      cin >> v;
      --v;
      g[v].push_back(i);
    }
  }
  used.assign(n, 0);
  for (int v = 0; v < n; ++v) {
    if (!used[v]) {
      bool cyc = cycles(v);
      if (cyc) {
        cout << -1 << endl;
        return;
      }
    }
  }
  ans.assign(n, 2 * maxn);
  used.assign(n, 0);
  int idx = 0;
  for (int v = 0; v < n; ++v) {
    if (!used[v]) calcAns(v);
    if (ans[v] > ans[idx]) idx = v;
  }
  cout << ans[idx] << endl;
}
int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solveC();
  return 0;
}
