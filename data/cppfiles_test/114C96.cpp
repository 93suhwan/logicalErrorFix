#include <bits/stdc++.h>
using namespace std;
long long n, m;
set<vector<long long>> s;
vector<long long> c, cur;
vector<vector<long long>> a;
bool check(long long i, long long rem) {
  for (long long j = c[i]; j > 0 and a[i][c[i]] - a[i][j] <= rem; --j) {
    if (i == n) {
      cur[i] = j;
      if (!s.count(cur)) return true;
    } else {
      cur[i] = j;
      if (check(i + 1, rem - (a[i][c[i]] - a[i][j]))) return true;
    }
  }
  return false;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    cin >> n;
    c.resize(n + 1), cur.resize(n + 1), a.resize(n + 1);
    for (long long i = 1; i <= n; ++i) {
      cin >> c[i];
      a[i].resize(c[i] + 1);
      for (long long j = 1; j <= c[i]; ++j) cin >> a[i][j];
    }
    cin >> m;
    for (long long i = 0; i < (m); ++i) {
      vector<long long> b(n + 1);
      for (long long j = 1; j <= n; ++j) cin >> b[j];
      s.insert(b);
    }
    long long lo = -1;
    long long hi = 0;
    for (long long i = 1; i <= n; ++i) hi += a[i][c[i]] - a[i][1];
    while (hi - lo > 1) {
      long long mid = hi + lo >> 1;
      if (check(1, mid))
        hi = mid;
      else
        lo = mid;
    }
    check(1, hi);
    for (long long i = 1; i <= n; ++i) cout << cur[i] << ' ';
  }
  return 0;
}
