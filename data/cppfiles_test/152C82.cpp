#include <bits/stdc++.h>
using namespace std;
long long dp[1000006][2];
long long pre[1000006][2];
void chkMinLog(long long& goal, long long t1, bool t2, bool curr) {
  if (dp[t1][t2] > goal) {
    dp[t1][t2] = goal;
    pre[t1][t2] = curr;
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 2);
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  for (long long i = (1); i <= (n); i++)
    for (long long j = (0); j <= (1); j++) dp[i][j] = 1e18;
  a[0] = n + 1;
  dp[0][0] = dp[0][1] = -n - 1;
  for (long long i = (0); i <= (n - 1); i++)
    for (long long isPos = (0); isPos <= (1); isPos++) {
      long long sv = (isPos ? 1 : -1) * a[i], v = dp[i][isPos];
      if (-a[i + 1] > v) chkMinLog(sv, i + 1, false, isPos);
      if (a[i + 1] > v) chkMinLog(sv, i + 1, true, isPos);
      if (-a[i + 1] > sv) chkMinLog(v, i + 1, false, isPos);
      if (a[i + 1] > sv) chkMinLog(v, i + 1, true, isPos);
    }
  if (dp[n][0] <= n || dp[n][1] <= n) {
    cout << "YES" << endl;
    long long ti = n, ts = 0;
    if (dp[n][1] <= n) ts = 1;
    while (ti >= 1) {
      if (ts == 0) a[ti] = -a[ti];
      ts = pre[ti][ts], ti--;
    }
    for (long long i = (1); i <= (n); i++) cout << a[i] << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
