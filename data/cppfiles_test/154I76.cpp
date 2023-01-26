#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)(1e9 + 7);
const long long INF = (long long)(1e18);
const long long INFN = (long long)(-1e18);
const long long N = (long long)(1e6 + 5);
signed dulieu() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("CODE.inp", "r", stdin);
  freopen("CODE.OUT", "w", stdout);
  return 0;
}
template <class X, class Y>
bool minimize(X &x, const Y &y) {
  X eps = 1e-9;
  if (x > y + eps) {
    x = y;
    return true;
  } else
    return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y) {
  X eps = 1e-9;
  if (x + eps < y) {
    x = y;
    return true;
  } else
    return false;
}
long long a, b, c;
void solve() {
  cin >> a >> b >> c;
  if (a == b) {
    if (c % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (a == c) {
    if (b % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  if (b == b) {
    if (a % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return;
  }
  long long d[3] = {a, b, c};
  sort(d + 1, d + 1 + 3);
  if (d[3] == d[1] + d[2]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
