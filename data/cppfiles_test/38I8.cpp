#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long INF = 1ll << 61;
const long long MOD = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> t(n);
  vector<int> d(m, 0);
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (d[j] == 0 && t[i][j] == '.' && t[i - 1][j] == 'X' &&
          t[i][j - 1] == 'X')
        d[j] = 1;
    }
  }
  for (int i = 1; i < m; i++) {
    d[i] += d[i - 1];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    r--;
    if (l > r || d[r] - d[l - 1] == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
