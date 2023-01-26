#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> comp1;
vector<int> comp2;
int get_comp(vector<int>& comp, int i) {
  while (comp[i] != i) i = comp[i];
  return i;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  comp1.resize(n);
  for (int i = 0; i < n; ++i) comp1[i] = i;
  comp2.resize(n);
  for (int i = 0; i < n; ++i) comp2[i] = i;
  int m1, m2;
  cin >> m1 >> m2;
  for (int i = 0; i < m1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    comp1[get_comp(comp1, u)] = get_comp(comp1, v);
  }
  for (int i = 0; i < m2; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    comp2[get_comp(comp2, u)] = get_comp(comp2, v);
  }
  vector<pair<int, int>> pairs;
  for (int u = 0; u < n; ++u) {
    for (int v = u + 1; v < n; ++v) {
      if (get_comp(comp1, u) != get_comp(comp1, v) &&
          get_comp(comp2, u) != get_comp(comp2, v)) {
        pairs.push_back({u, v});
        comp1[get_comp(comp1, u)] = get_comp(comp1, v);
        comp2[get_comp(comp2, u)] = get_comp(comp2, v);
      }
    }
  }
  cout << pairs.size() << "\n";
  for (auto [u, v] : pairs) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
  return 0;
}
