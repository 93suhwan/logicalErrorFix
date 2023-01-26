#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  vector<long long> sum(m);
  for (long long j = 0; j < m; ++j) {
    long long sm = 0;
    for (long long i = 0; i < n; ++i)
      if (a[i][j] == 'X') sm++;
    sum[j] = sm;
    if (j != 0) sum[j] += sum[j - 1];
  }
  long long qr;
  cin >> qr;
  for (long long i = 0; i < qr; ++i) {
    long long c1, c2;
    cin >> c1 >> c2;
    c1--, c2--;
    long long tt = (sum[c2]) - ((c1 != 0) ? sum[c1 - 1] : 0);
    if (tt > 1)
      cout << "NO\n";
    else
      cout << "YES\n";
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
