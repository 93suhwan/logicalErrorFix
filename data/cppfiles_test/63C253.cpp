#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
const int N = 1005;
int dsu[2][N];
int solve(int id, int u) {
  if (dsu[id][u] == -1) return u;
  return dsu[id][u] = solve(id, dsu[id][u]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    memset(dsu, -1, sizeof(dsu));
    for (int i = 0; i < m1; ++i) {
      int u, v;
      cin >> u >> v;
      int fu = solve(0, u), fv = solve(0, v);
      dsu[0][fu] = fv;
    }
    for (int i = 0; i < m2; ++i) {
      int u, v;
      cin >> u >> v;
      int fu = solve(1, u), fv = solve(1, v);
      dsu[1][fu] = fv;
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i < n + 1; ++i) {
      for (int j = i + 1; j < n + 1; ++j) {
        if (solve(0, i) != solve(0, j) && solve(1, i) != solve(1, j)) {
          ans.push_back({i, j});
          dsu[0][solve(0, i)] = solve(0, j);
          dsu[1][solve(1, i)] = solve(1, j);
        }
      }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x.first << " " << x.second << endl;
  }
  return 0;
}
