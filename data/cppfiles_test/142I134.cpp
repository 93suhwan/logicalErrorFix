#include <bits/stdc++.h>
using namespace std;
long long ans;
vector<vector<long long>> a;
long long n, m;
set<pair<long long, long long>> s;
void helper(long long row, vector<long long> temp, long long cnt) {
  if (row == m) {
    if (cnt <= n - 1) {
      long long tt = 1e18;
      for (auto x : temp) {
        tt = min(tt, x);
      }
      ans = max(ans, tt);
    }
    return;
  }
  if (s.find({row, cnt}) != s.end()) {
    return;
  }
  helper(row + 1, temp, cnt);
  vector<long long> t = temp;
  for (long long i = 0; i < n; i++) {
    t[i] = max(t[i], a[row][i]);
  }
  helper(row + 1, t, cnt + 1);
  s.insert({row, cnt});
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin.ignore();
    s.clear();
    cin >> m >> n;
    a = vector<vector<long long>>(m, vector<long long>(n, 0));
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    ans = 0;
    vector<long long> tt(n, 0);
    helper(0, tt, 0);
    cout << ans << "\n";
  }
}
