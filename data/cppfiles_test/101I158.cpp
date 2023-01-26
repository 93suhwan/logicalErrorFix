#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1000005 + 5], col[1000005];
void solve(long long kk) {
  cin >> n;
  long long neg = 0, mm = 0, nn = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s1;
  cin >> s1;
  s1 = 'X' + s1;
  bool ok = 1;
  for (long long i = 1; i <= n; i++) {
    if (a[i] <= 0 && s1[i] == 'B') {
      ok = 0;
      break;
    }
    if (a[i] >= n && s1[i] == 'R')
      mm++;
    else if (a[i] == 1 && s1[i] == 'B')
      nn++;
  }
  if (mm >= 2 || nn >= 2) ok = 0;
  ok ? cout << "YES\n" : cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
