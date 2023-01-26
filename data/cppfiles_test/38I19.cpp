#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Union_Find {
  vector<int> par;
  vector<int> rank;
  vector<int> num;

 public:
  Union_Find(int n) {
    par = vector<int>(n);
    rank = vector<int>(n, 0);
    num = vector<int>(n, 1);
    for (int i = 0; i < (int)n; i++) par[i] = i;
  }
  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }
  int number(int x) { return num[find(x)]; }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    num[x] += num[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n + 1);
  for (int i = 0; i < (int)m; i++) s[0] += '.';
  for (int i = 0; i < (int)n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }
  Union_Find uf((n + 1) * (m + 1) + 1);
  int MAX = (n + 1) * (m + 1);
  for (int i = 0; i < (int)n + 1; i++) {
    for (int j = 0; j < (int)m + 1; j++) {
      if (i == 0 or j == 0)
        uf.unite(i * (m + 1) + j, MAX);
      else {
        if (s[i][j] == '.' and s[i - 1][j] == '.')
          uf.unite(i * (m + 1) + j, (i - 1) * (m + 1) + j);
        if (s[i][j] == '.' and s[i][j - 1] == '.')
          uf.unite(i * (m + 1) + j, i * (m + 1) + j - 1);
      }
    }
  }
  vector<int> sum(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!uf.same(i * (m + 1) + j, MAX) and s[i][j] == '.') sum[j]++;
    }
  }
  for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << (sum[y] - sum[x] == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
