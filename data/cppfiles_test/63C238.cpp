#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int n, m1, m2, lab1[N], lab2[N];
vector<pair<int, int>> edge1, edge2, res;
int root1(int u) { return u == lab1[u] ? u : lab1[u] = root1(lab1[u]); }
int root2(int u) { return u == lab2[u] ? u : lab2[u] = root2(lab2[u]); }
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    edge1.push_back({u, v});
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    edge2.push_back({u, v});
  }
  for (int i = 1; i <= n; i++) lab1[i] = lab2[i] = i;
  for (auto [u, v] : edge1) {
    int r_u = root1(u), r_v = root1(v);
    if (r_u != r_v) lab1[r_v] = r_u;
  }
  for (auto [u, v] : edge2) {
    int r_u = root2(u), r_v = root2(v);
    if (r_u != r_v) lab2[r_v] = r_u;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (root1(i) != root1(j) && root2(i) != root2(j)) {
        res.push_back({i, j});
        lab1[root1(i)] = root1(j);
        lab2[root2(i)] = root2(j);
      }
    }
  cout << res.size() << '\n';
  for (auto [u, v] : res) {
    cout << u << ' ' << v << '\n';
  }
}
