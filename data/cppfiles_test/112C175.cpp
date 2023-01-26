#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long INF = 1e18L + 5;
const int mxn = 2e5 + 1;
int c = 1;
void solve() {
  long long HA, KK, pp, t;
  cin >> HA >> KK >> pp >> t;
  if (HA - 1 > KK + pp + t || KK - 1 > HA + pp + t || pp - 1 > HA + KK + t)
    cout << "NO\n";
  else if (HA + KK + pp - 3 >= t)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tcs = 1;
  cin >> tcs;
  while (tcs--) {
    solve();
    c++;
  }
  return 0;
}
