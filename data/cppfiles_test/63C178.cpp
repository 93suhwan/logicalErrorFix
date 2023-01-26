#include <bits/stdc++.h>
using namespace std;
void init(int n, vector<int>& comp, vector<int>& ranc) {
  comp.assign(n, 0);
  ranc.assign(n, 1);
  for (int i = 0; i < n; ++i) {
    comp[i] = i;
  }
}
int get_comp(int i, vector<int>& comp) {
  if (comp[i] == i) {
    return i;
  } else {
    return comp[i] = get_comp(comp[i], comp);
  }
}
void join(int u, int v, vector<int>& comp, vector<int>& ranc) {
  u = get_comp(u, comp);
  v = get_comp(v, comp);
  if (ranc[v] > ranc[u]) swap(u, v);
  comp[v] = u;
  if (ranc[u] == ranc[v]) ++ranc[u];
}
int main() {
  long long n, m1, m2, a, b;
  cin >> n >> m1 >> m2;
  vector<int> comp1;
  vector<int> ranc1;
  vector<int> comp2;
  vector<int> ranc2;
  init(n, comp1, ranc1);
  init(n, comp2, ranc2);
  for (int i = 0; i < m1; ++i) {
    cin >> a >> b;
    join(a - 1, b - 1, comp1, ranc1);
  }
  for (int i = 0; i < m2; i++) {
    cin >> a >> b;
    join(a - 1, b - 1, comp2, ranc2);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (get_comp(i, comp1) != get_comp(j, comp1) &&
          get_comp(i, comp2) != get_comp(j, comp2)) {
        join(i, j, comp1, ranc1);
        join(i, j, comp2, ranc2);
        ans.push_back({i + 1, j + 1});
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}
