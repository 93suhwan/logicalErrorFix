#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 1e6 + 15;
const long long M = 2e4;
const long long mod1 = 1e9 + 7;
const long long mod = 998244353;
const long long base = 131;
const double pi = 3.1415926;
const double eps = 1e-6;
long long n, m, k, ans, x, y, mid, sx = -1, sy = -1, mi = INF, cnt, z, sz, mx;
long long a[N], l[N], r[N], b[N];
vector<long long> ve, ve1;
string s;
void solve() {
  long long pos = 0, f1 = 0, s1 = 0, s2 = 0;
  ans = 0;
  mx = INF;
  cin >> x >> y >> k;
  if (k & 1) {
    ans = 3;
  } else
    ans = 0;
  if (ans == 3 && x && y) {
    ans = 0;
    x--;
    y--;
  }
  if (y & 1) {
    ans = 2;
  } else
    ans = 0;
  if (ans == 3 && x >= 3) {
    ans = 0;
    x -= 3;
  }
  if (ans == 2 && x >= 2) {
    ans = 0;
    x -= 2;
  }
  if (x & 1)
    ans = 1;
  else
    ans = 0;
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T;
  for (cin >> T; T--;) solve();
}
