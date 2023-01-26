#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100 * 1000 + 7;
int od[N], il[N];
vector<int> ed[N];
set<int> kol;
void Answer(int n) {
  int p, v, w;
  p = n + 1;
  w = 0;
  while (kol.size() > 0) {
    if (kol.upper_bound(p) != kol.end())
      v = (*kol.upper_bound(p));
    else
      v = (*kol.begin());
    kol.erase(v);
    od[v] = 1;
    if (v < p) ++w;
    for (int i = 0; i < (int)ed[v].size(); ++i) {
      --il[ed[v][i]];
      if (il[ed[v][i]] == 0) kol.insert(ed[v][i]);
    }
    p = v;
  }
  for (int i = 1; i <= n; ++i) {
    if (od[i] == 0) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << w << "\n";
}
void Solve() {
  int n, m, v;
  cin >> n;
  for (int i = 1; i <= n; ++i) ed[i].clear();
  for (int i = 1; i <= n; ++i) {
    od[i] = 0;
    cin >> m;
    il[i] = m;
    if (m == 0) kol.insert(i);
    for (int j = 1; j <= m; ++j) {
      cin >> v;
      ed[v].push_back(i);
    }
  }
  Answer(n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
