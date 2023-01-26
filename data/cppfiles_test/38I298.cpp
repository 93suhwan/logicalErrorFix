#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  vector<vector<long long>> b(n, vector<long long>(m));
  for (long long i = 1; i < n; ++i) {
    for (long long j = 1; j < m; ++j) {
      if (a[i][j] == '.' && a[i][j - 1] == 'X' && a[i - 1][j] == 'X')
        b[i][j] = 1;
    }
  }
  vector<long long> sum(m);
  for (long long j = 1; j < m; ++j) {
    long long s = 0;
    for (long long i = 1; i < n; ++i) {
      if (b[i][j] == 1) s++;
    }
    sum[j] = s;
  }
  long long q;
  cin >> q;
  while (q--) {
    long long c1, c2;
    cin >> c1 >> c2;
    c1--, c2--;
    if (c1 == c2)
      cout << "YES\n";
    else {
      long long t = sum[c2] - sum[c1];
      if (t > 0)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
}
int32_t main() {
  long long nt;
  nt = 1;
  long long ct = 1;
  while (nt--) {
    solve();
  }
}
