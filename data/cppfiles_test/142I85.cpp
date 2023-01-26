#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100003;
const int INF = int(1e9) + 5;
void test_case() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > mat(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> mat[i][j];
  for (int i = 1; i <= n; i++) sort(mat[i].begin() + 1, mat[i].begin() + m + 1);
  auto f = [&](int h) -> bool {
    vector<bool> a(m + 1);
    bool pair = false;
    for (int i = 1; i <= n; i++) {
      int c = 0;
      for (int j = 1; j <= m; j++)
        if (mat[i][j] >= h) {
          a[j] = 1;
          c++;
        }
      if (c > 1) pair = 1;
    }
    if (!pair && m > 1) return false;
    for (int i = 1; i <= m; i++)
      if (!a[i]) return 0;
    return 1;
  };
  int st = 1, dr = INF, last = 0;
  while (dr - st >= 0) {
    int mid = (st + dr) >> 1;
    if (f(mid)) {
      st = mid + 1;
      last = mid;
    } else
      dr = mid - 1;
  }
  cout << last << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) test_case();
  return 0;
}
