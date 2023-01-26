#include <bits/stdc++.h>
using ld = long double;
const long long maxn = 2e5 + 5;
const long long INF = 1e18 + 1;
const long long mod = 1e9 + 7;
using namespace std;
long long suf[maxn][4];
long long to_id(pair<long long, long long> z) {
  long long fi = z.first;
  long long se = z.second;
  if (fi == 0 && se == 0)
    return 0;
  else if (fi == 0 && se == 2)
    return 1;
  else if (fi == 2 && se == 0)
    return 2;
  else if (fi == 2 && se == 2)
    return 3;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    x %= 4;
    y %= 4;
    a.push_back({x, y});
  }
  for (long long i = n - 1; i >= 0; i--) {
    long long fi = a[i].first % 4;
    long long se = a[i].second % 4;
    if (fi == 0 && se == 0)
      suf[i][0]++;
    else if (fi == 0 && se == 2)
      suf[i][1]++;
    else if (fi == 2 && se == 0)
      suf[i][2]++;
    else if (fi == 2 && se == 2)
      suf[i][3]++;
    else
      return 1;
    for (long long j = 0; j < 4; j++) {
      suf[i][j] += suf[i + 1][j];
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      long long ij = 2;
      if (a[i] == a[j]) ij = 0;
      long long ik = to_id(a[i]);
      long long jk = to_id(a[j]);
      for (long long id = 0; id < 4; id++) {
        long long z = ij;
        if (id != ik) z += 2;
        if (id != jk) z += 2;
        if (z % 4 == 0) {
          ans += suf[j + 1][id];
        }
      }
    }
  }
  cout << ans;
  return 0;
}
