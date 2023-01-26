#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<vector<long long>> vec(2, vector<long long>(2, 0));
  for (long long i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    x %= 4;
    y %= 4;
    x /= 2;
    y /= 2;
    ++vec[x][y];
  }
  vector<long long> vv(4);
  vv[0] = vec[0][0];
  vv[1] = vec[0][1];
  vv[2] = vec[1][0];
  vv[3] = vec[1][1];
  long long ans = 0;
  for (long long i = 0; i < 4; ++i)
    ans += vv[i] * (vv[i] - 1) * (vv[i] - 2) / 6;
  for (long long i = 0; i < 4; ++i) {
    for (long long j = 0; j < 4; ++j) {
      if (i == j) continue;
      ans += vv[i] * (vv[i] - 1) * vv[j] / 2;
    }
  }
  cout << ans << '\n';
}
