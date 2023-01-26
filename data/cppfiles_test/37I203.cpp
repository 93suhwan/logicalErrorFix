#include <bits/stdc++.h>
using namespace std;
int n, m;
int par[100010];
int find(int x) {
  if (par[x] < 0) return x;
  return par[x] = find(par[x]);
}
bool onion(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return 0;
  par[x] += par[y];
  par[y] = x;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    vector<pair<int, int> > ans;
    for (int i = 0; i < m; i++) {
      int t1, t2, x;
      cin >> t1 >> t2 >> x;
      if (onion(t1, t2)) ans.push_back({t1, t2});
    }
    for (int i = 1; i < n; i++)
      if (onion(i, i + 1)) ans.push_back({i, i + 1});
    for (auto x : ans) {
      cout << x.first << " " << x.second << "\n";
    }
  }
}
