#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 9;
int par1[N], par2[N];
int find1(int a) {
  if (par1[a] == a) return a;
  return par1[a] = find1(par1[a]);
}
int find2(int a) {
  if (par2[a] == a) return a;
  return par2[a] = find2(par2[a]);
}
void Union1(int a, int b) {
  int u, v;
  u = find1(a);
  v = find1(b);
  if (u != v) par1[v] = u;
}
void Union2(int a, int b) {
  int u, v;
  u = find2(a);
  v = find2(b);
  if (u != v) par2[v] = u;
}
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) par1[i] = par2[i] = i;
  while (m1--) {
    int u, v;
    cin >> u >> v;
    Union1(u, v);
  }
  while (m2--) {
    int u, v;
    cin >> u >> v;
    Union2(u, v);
  }
  int cnt = 0;
  vector<pair<int, int>> v;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (find1(i) != find1(j)) {
        if (find2(i) != find2(j)) {
          cnt++;
          v.push_back({i, j});
          Union1(i, j);
          Union2(i, j);
        }
      }
    }
  }
  cout << cnt << "\n";
  for (auto c : v) cout << c.first << " " << c.second << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) solve();
  return 0;
}
