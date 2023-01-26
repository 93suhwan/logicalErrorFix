#include <bits/stdc++.h>
using namespace std;
int find_parent(int v, vector<int> &parent) {
  if (v == parent[v]) return v;
  return parent[v] = find_parent(parent[v], parent);
}
void union_set(int a, int b, vector<int> &parent, vector<int> &sz) {
  a = find_parent(a, parent);
  b = find_parent(b, parent);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<int> > ans;
  vector<int> parent(n + 1);
  vector<int> sz(n + 1);
  vector<int> parent1(n + 1);
  vector<int> sz1(n + 1);
  for (int i = 1; i <= n; i++) {
    sz[i] = 1;
    sz1[i] = 1;
    parent[i] = i;
    parent1[i] = i;
  }
  int u, v;
  for (int i = 0; i < a; i++) {
    cin >> u >> v;
    union_set(u, v, parent, sz);
  }
  for (int i = 0; i < b; i++) {
    cin >> u >> v;
    union_set(u, v, parent1, sz1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      if (parent[i] != parent[j] && parent1[i] != parent1[j]) {
        ans.push_back({i, j});
        union_set(i, j, parent1, sz1);
        union_set(i, j, parent, sz);
      }
    }
  }
  cout << ans.size();
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}
