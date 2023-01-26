#include <bits/stdc++.h>
using namespace std;
const int maxN = 1 << 17;
vector<int> g[maxN], gr[maxN];
vector<char> used;
vector<int> order, component;
int color[maxN];
void dfs1(int v) {
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); ++i)
    if (!used[g[v][i]]) dfs1(g[v][i]);
  order.push_back(v);
}
void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (size_t i = 0; i < gr[v].size(); ++i)
    if (!used[gr[v][i]]) dfs2(gr[v][i]);
}
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> ordA(n), ordB(n);
    for (int i = 0; i < n; i++) {
      ordA[i] = ordB[i] = i;
      g[i].clear();
      gr[i].clear();
    }
    sort(ordA.begin(), ordA.end(), [&](int i, int j) { return a[i] < a[j]; });
    sort(ordB.begin(), ordB.end(), [&](int i, int j) { return b[i] < b[j]; });
    for (int i = 1; i < n; i++) {
      g[ordA[i]].push_back(ordA[i - 1]);
      gr[ordA[i - 1]].push_back(ordA[i]);
      g[ordB[i]].push_back(ordB[i - 1]);
      gr[ordB[i - 1]].push_back(ordB[i]);
    }
    order.clear();
    component.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
      if (!used[i]) dfs1(i);
    int cnt = 0;
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
      int v = order[n - 1 - i];
      if (!used[v]) {
        dfs2(v);
        for (auto u : component) color[u] = cnt;
        cnt++;
        component.clear();
      }
    }
    vector<int> bad(cnt, 0);
    for (int i = 0; i < n; i++) {
      for (int to : g[i])
        if (color[i] != color[to]) bad[color[to]] = 1;
    }
    for (int i = 0; i < n; i++) cout << (!bad[color[i]]);
    cout << endl;
  }
  return 0;
}
