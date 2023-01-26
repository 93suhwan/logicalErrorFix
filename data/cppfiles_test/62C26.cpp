#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 10;
long long dp1[N][N], dp2[N][N];
long long a[N][N];
signed main() {
  ios::sync_with_stdio(false);
  long long n, m, q;
  cin >> n >> m >> q;
  for (long long i = n; i >= 1; i--)
    for (long long j = m; j >= 1; j--) {
      dp1[i][j] = dp2[i][j + 1] + 1;
      dp2[i][j] = dp1[i + 1][j] + 1;
    }
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) ans += dp1[i][j] + dp2[i][j];
  long long cnt = n * m;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    bool flag = false;
    if (a[x][y] == 0) {
      cnt--;
      flag = 1;
    } else {
      cnt++;
    }
    a[x][y] ^= 1;
    vector<pair<long long, long long> > tmp;
    tmp.push_back(make_pair(x, y));
    long long i = x, j = y + 1;
    while (true) {
      if (i > n || j > m) break;
      tmp.push_back(make_pair(i, j));
      i = i + 1;
      if (i > n || j > m) break;
      tmp.push_back(make_pair(i, j));
      j = j + 1;
    }
    reverse(tmp.begin(), tmp.end());
    i = x - 1, j = y;
    while (true) {
      if (i <= 0 || j <= 0) break;
      tmp.push_back(make_pair(i, j));
      j = j - 1;
      if (i <= 0 || j <= 0) break;
      tmp.push_back(make_pair(i, j));
      i = i - 1;
    }
    for (pair<long long, long long> v : tmp) {
      long long i = v.first, j = v.second;
      if (a[i][j] == 1) {
        ans -= dp1[i][j] + dp2[i][j];
        dp1[i][j] = 0, dp2[i][j] = 0;
      } else {
        ans -= dp1[i][j] + dp2[i][j];
        dp1[i][j] = dp2[i][j + 1] + 1;
        dp2[i][j] = dp1[i + 1][j] + 1;
        ans += dp1[i][j] + dp2[i][j];
      }
    }
    tmp.clear();
    tmp.push_back(make_pair(x, y));
    i = x + 1, j = y;
    while (true) {
      if (i > n || j > m) break;
      tmp.push_back(make_pair(i, j));
      j = j + 1;
      if (i > n || j > m) break;
      tmp.push_back(make_pair(i, j));
      i = i + 1;
    }
    reverse(tmp.begin(), tmp.end());
    i = x, j = y - 1;
    while (true) {
      if (i <= 0 || j <= 0) break;
      tmp.push_back(make_pair(i, j));
      i = i - 1;
      if (i <= 0 || j <= 0) break;
      tmp.push_back(make_pair(i, j));
      j = j - 1;
    }
    for (pair<long long, long long> v : tmp) {
      long long i = v.first, j = v.second;
      if (a[i][j] == 1) {
        ans -= dp1[i][j] + dp2[i][j];
        dp1[i][j] = 0, dp2[i][j] = 0;
      } else {
        ans -= dp1[i][j] + dp2[i][j];
        dp1[i][j] = dp2[i][j + 1] + 1;
        dp2[i][j] = dp1[i + 1][j] + 1;
        ans += dp1[i][j] + dp2[i][j];
      }
    }
    cout << ans - cnt << endl;
  }
  return 0;
}
