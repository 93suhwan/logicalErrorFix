#include <bits/stdc++.h>
using namespace std;
int get_set(int v, vector<int> &dsu) {
  if (dsu[v] == v) return v;
  dsu[v] = get_set(dsu[v], dsu);
  return dsu[v];
}
void dsu_union(int a, int b, vector<int> &dsu, vector<int> &my_rank) {
  a = get_set(a, dsu);
  b = get_set(b, dsu);
  if (my_rank[a] > my_rank[b]) swap(a, b);
  dsu[a] = b;
  my_rank[b]++;
}
void dfs(int v, int c, vector<int> &color, vector<vector<int>> &g,
         vector<int> &my_rank, vector<bool> &used) {
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u]) {
      dsu_union(u, v, color, my_rank);
      dfs(u, c, color, g, my_rank, used);
    }
  }
}
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<int> color1;
  vector<int> color2;
  color1.resize(n, -1);
  color2.resize(n, -1);
  vector<vector<int>> g1(n), g2(n);
  vector<bool> used1(n, false);
  vector<bool> used2(n, false);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g1[u].push_back(v);
    g1[v].push_back(u);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g2[u].push_back(v);
    g2[v].push_back(u);
  }
  for (int i = 0; i < n; i++) color1[i] = i;
  for (int i = 0; i < n; i++) color2[i] = i;
  vector<int> my_rank1(n, 1), my_rank2(n, 1);
  for (int i = 0; i < n; i++) {
    if (!used1[i]) {
      dfs(i, i, color1, g1, my_rank1, used1);
    }
    if (!used2[i]) {
      dfs(i, i, color2, g2, my_rank2, used2);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (get_set(i, color1) != get_set(j, color1) &&
          get_set(i, color2) != get_set(j, color2)) {
        ans.emplace_back(i, j);
        dsu_union(i, j, color1, my_rank1);
        dsu_union(i, j, color2, my_rank2);
      }
    }
  }
  unordered_set<int> pot1, pot2;
  for (int i = 1; i < n; i++) {
    if ((get_set(i, color1) != get_set(0, color1) &&
         get_set(i, color2) == get_set(0, color2))) {
      pot2.insert(i);
    } else if ((get_set(i, color1) == get_set(0, color1) &&
                get_set(i, color2) != get_set(0, color2))) {
      pot1.insert(i);
    }
  }
  while (!pot1.empty() && !pot2.empty()) {
    while (!pot1.empty() &&
           get_set(*pot1.begin(), color2) == get_set(0, color2))
      pot1.erase(pot1.begin());
    while (!pot2.empty() &&
           get_set(*pot2.begin(), color1) == get_set(0, color1))
      pot2.erase(pot2.begin());
    if (pot1.empty() || pot2.empty()) break;
    ans.emplace_back(*pot1.begin(), *pot2.begin());
    dsu_union(*pot1.begin(), *pot2.begin(), color1, my_rank1);
    dsu_union(*pot1.begin(), *pot2.begin(), color2, my_rank2);
    pot1.erase(pot1.begin());
    pot2.erase(pot2.begin());
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i.first + 1 << ' ' << i.second + 1 << '\n';
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
