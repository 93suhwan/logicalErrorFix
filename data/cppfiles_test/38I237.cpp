#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
template <typename T>
struct sparse_table {
  using F = std::function<T(const T &, const T &)>;
  int N, k;
  F f;
  vector<vector<T>> mat;
  sparse_table(vector<T> &v, F fun) {
    f = fun;
    N = v.size();
    k = 32 - __builtin_clz(N) - 1;
    mat.resize(N, vector<T>(k + 1));
    for (int i = 0; i < N; i++) mat[i][0] = v[i];
    for (int j = 1; j <= k; j++)
      for (int i = 0; i + (1 << j) <= N; i++)
        mat[i][j] = f(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
  }
  T query(int l, int r) {
    int j = 32 - __builtin_clz(r - l + 1) - 1;
    return f(mat[l][j], mat[r - (1 << j) + 1][j]);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int n, m;
  cin >> n >> m;
  bool g[n + 1][m + 1], val[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      if (ch == '.') {
        g[i][j] = true;
      } else
        g[i][j] = false;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 or j == 0)
        val[i][j] = true;
      else if (g[i][j])
        val[i][j] = val[i - 1][j] or val[i][j - 1];
      else
        val[i][j] = false;
    }
  }
  vector<int> v(m + 1, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (val[i][j] != g[i][j]) v[j] = 0;
    }
  }
  sparse_table<int> table(v, [](int a, int b) { return a < b ? a : b; });
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "YES\n";
      continue;
    }
    int val1 = table.query(a + 1, b);
    if (val1 == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
