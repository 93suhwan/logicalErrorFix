#include <bits/stdc++.h>
using namespace std;
const int large = 2e5 + 5;
vector<pair<int, int> > edges;
vector<pair<int, int> > iedges[large];
vector<int> value;
bool contra = 0;
void dfs(int child, int val) {
  if (value[child] != -1) {
    if (val != value[child]) contra = 1;
    return;
  }
  value[child] = val;
  for (auto &a : iedges[child]) dfs(a.first, val ^ a.second);
}
void solve() {
  int n, m;
  cin >> n >> m;
  contra = 0;
  value.assign(n + 1, -1);
  edges.clear();
  for (int i = 0; i <= n; i++) iedges[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    edges.push_back({x, y});
    if (v != -1) {
      int val = 0;
      for (int push = 1; push <= v; push <<= 1) val += !!(v & push);
      v = val & 1;
      iedges[x].push_back({y, v});
      iedges[y].push_back({x, v});
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, p;
    cin >> a >> b >> p;
    iedges[a].push_back({b, p});
    iedges[b].push_back({a, p});
  }
  for (int i = 1; i <= n; i++)
    if (value[i] == -1) dfs(i, 0);
  if (contra)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (auto &a : edges) {
      cout << a.first << " " << a.second << " "
           << (value[a.first] ^ value[a.second]) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
