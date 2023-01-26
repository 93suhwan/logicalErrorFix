#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void mkc() {
  long long int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<long long int>> p(n, vector<long long int>(m, 0));
  for (long long int i = 1; i < n; ++i) {
    for (long long int j = 1; j < m; ++j) {
      if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') {
        p[i][j] = 1;
      }
    }
  }
  long long int sum = 0;
  vector<long long int> pre(m);
  for (long long int j = 0; j < m; j++) {
    for (long long int i = 0; i < n; ++i) {
      sum += p[i][j];
    }
    pre[j] = sum;
  }
  long long int q, x, y;
  ;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << ((pre[y - 1] - pre[x - 1] == 0) ? "YES" : "NO") << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  mkc();
  return 0;
}
