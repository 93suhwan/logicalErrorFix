#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
void TestCase() {
  int n, m, ans = INT_MAX;
  cin >> n >> m;
  vector<vector<char> > g(n + 1, vector<char>(m + 1));
  vector<vector<int> > a(n + 1, vector<int>(m + 1, 0)),
      b(n + 1, vector<int>(m + 1, 0)), sum(n + 1, vector<int>(m + 1, 0));
  vector<int> use(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> g[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) a[i][j] = a[i][j - 1] + (g[i][j] == '1');
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) b[i][j] = b[i - 1][j] + (g[i][j] == '1');
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      sum[i][j] =
          sum[i - 1][j - 1] + a[i][j - 1] + b[i - 1][j] + (g[i][j] == '1');
  }
  for (int i1 = 1; i1 <= n; i1++) {
    for (int i2 = i1 + 4; i2 <= n; i2++) {
      for (int j = 0; j <= m; j++) {
        use[j] = -1 * (b[i2 - 1][j] - b[i1][j]) + (-1 * j + a[i1][j]) +
                 (-1 * j + a[i2][j]) - sum[i2 - 1][j] + sum[i1][j];
        if (j) use[j] = min(use[j], use[j - 1]);
      }
      for (int j = 4; j <= m; j++) {
        int aa = (i2 - i1 - 1) - (b[i2 - 1][j] - b[i1][j]);
        int ab = (i2 - i1 - 1);
        int ac = (j - 1) - a[i1][j - 1];
        int ad = (j - 1) - a[i2][j - 1];
        int ae = sum[i2 - 1][j - 1] - sum[i1][j - 1];
        ans = min(ans, aa + ab + ac + ad + ae + use[j - 3]);
      }
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}
