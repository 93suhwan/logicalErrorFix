#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
void solve() {
  long long i, j, k, n, m, mid, sum, f, x, y, ans, finalAns, w, h;
  cin >> n;
  vector<long long> l(n), r(n);
  vector<set<long long, greater<long long>>> lpp(n + 1);
  vector<set<long long>> rpp(n + 1);
  for (i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    lpp[l[i]].insert(r[i]);
    rpp[r[i]].insert(l[i]);
  }
  if (n == 1) {
    cout << "1 1 1";
    cout << "\n";
  } else {
    long long dp[n + 1][n + 1];
    for (i = 1; i <= n; i++) {
      long long p = n + 1;
      for (auto x : lpp[i]) {
        dp[i][p] = x + 1;
        p = x;
      }
      if (i == p) {
        dp[i][p] = p;
      }
      p = 0;
      for (auto x : rpp[i]) {
        dp[p][i] = x - 1;
        p = x;
      }
      if (i == p) {
        dp[p][i] = p;
      }
    }
    for (i = 0; i < n; i++) {
      cout << l[i] << " " << r[i] << " " << dp[l[i]][r[i]] << "\n";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
