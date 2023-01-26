#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int N = 300001;
int parent[N];
int rnk[N];
void make_set(int v) {
  parent[v] = v;
  rnk[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) ++rnk[a];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int zz = 0; zz < t; zz++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e;
    set<int> v;
    set<int> kek;
    for (int i = 0; i < n; i++) make_set(i);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      c--;
      if (find_set(a) == find_set(c)) continue;
      e.emplace_back(a, c);
      union_sets(a, c);
    }
    for (int i = 1; i < n; i++) {
      if (find_set(0) != find_set(i)) {
        e.emplace_back(0, i);
        union_sets(0, i);
      }
    }
    for (auto p : e) {
      cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
  }
}
