#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 3e5 + 10;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<string> a(n);
    vector<vector<long long>> c(n, vector<long long>(26));
    vector<long long> u(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      for (long long j = 0; j < (long long)a[i].size(); j++) {
        c[i][a[i][j] - 'a']++;
      }
      for (long long j = 0; j < 26; j++) {
        if (c[i][j] > 0) u[i]++;
      }
    }
    long long ans = 0;
    for (long long i = 0; i < 26; i++) {
      vector<long long> v(n);
      iota(v.begin(), v.end(), 0);
      sort(v.begin(), v.end(), [&](long long x, long long y) {
        if (a[x].size() - c[x][i] == a[y].size() - c[y][i])
          return c[x][i] > c[y][i];
        return a[x].size() - c[x][i] < a[y].size() - c[y][i];
      });
      long long cnt = 0, tot = 0, cur = 0;
      for (long long j = 0; j < n; j++) {
        if (cnt + c[v[j]][i] <= tot + a[v[j]].size() - c[v[j]][i]) break;
        cnt += c[v[j]][i];
        tot += a[v[j]].size() - c[v[j]][i];
        cur++;
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}
