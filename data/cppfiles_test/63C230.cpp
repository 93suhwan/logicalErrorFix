#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
const long long int INF = 1000000009;
const long long int MAXN = 300050;
using namespace std;
class DSU {
 private:
  vector<int> par, ranks;

 public:
  DSU(int n) {
    par.resize(n + 1);
    ranks.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      par[i] = i;
      ranks[i] = 0;
    }
  }
  int find_parent(int u) {
    if (par[u] == u)
      return u;
    else
      return par[u] = find_parent(par[u]);
  }
  void merge(int u, int v) {
    int pu = find_parent(u), pv = find_parent(v);
    if (pu == pv) return;
    if (ranks[pu] > ranks[pv]) {
      par[pv] = pu;
    } else {
      par[pu] = pv;
      if (ranks[pu] == ranks[pv]) ranks[pv]++;
    }
  }
};
void solve() {
  long long int n, m1, m2;
  cin >> n >> m1 >> m2;
  DSU a(n), b(n);
  for (long long int i = 0; i < m1; i++) {
    long long int x, y;
    cin >> x >> y;
    x--;
    y--;
    a.merge(x, y);
  }
  for (long long int i = 0; i < m2; i++) {
    long long int x, y;
    cin >> x >> y;
    x--;
    y--;
    b.merge(x, y);
  }
  vector<pair<long long int, long long int>> ans;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (a.find_parent(i) != a.find_parent(j) &&
          b.find_parent(i) != b.find_parent(j)) {
        ans.push_back({i, j});
        a.merge(i, j);
        b.merge(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first + 1 << " " << x.second + 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
