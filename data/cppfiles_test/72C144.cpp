#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAX = 1e3 + 5;
const long long MOD = 998244353;
const long long MOD2 = 2010405347;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline long long pw(long long x, long long y, long long md = MOD) {
  long long ret = 1;
  x %= md;
  while (y) {
    if (y & 1) ret = ret * x % md;
    x = x * x % md, y >>= 1;
  }
  return ret;
}
inline void add(int &a, int b, int md = MOD) {
  a = a + b >= md ? a + b - md : a + b;
}
int tc, n, k, dp[10][1024][2], pre[1024], x[15];
string s;
bool f(int nw, int mask, bool st) {
  if (pre[mask] > k) return false;
  if (nw == n) return true;
  int &ret = dp[nw][mask][st];
  if (ret != -1) return ret;
  if (st) {
    for (int i = (0); i <= (9); ++i)
      if (f(nw + 1, mask | (1 << i), 1)) return ret = true;
  } else {
    if (f(nw + 1, mask | (1 << x[nw]), 0)) return ret = true;
    for (int i = (x[nw] + 1); i <= (9); ++i)
      if (f(nw + 1, mask | (1 << i), 1)) return ret = true;
  }
  return ret = false;
}
void bt(int nw, int mask, bool st) {
  if (nw == n) return;
  if (st) {
    for (int i = (0); i <= (9); ++i)
      if (f(nw + 1, mask | (1 << i), 1)) {
        cout << i;
        bt(nw + 1, mask | (1 << i), 1);
        return;
      }
  } else {
    if (f(nw + 1, mask | (1 << x[nw]), 0)) {
      cout << x[nw];
      bt(nw + 1, mask | (1 << x[nw]), 0);
      return;
    }
    for (int i = (x[nw] + 1); i <= (9); ++i)
      if (f(nw + 1, mask | (1 << i), 1)) {
        cout << i;
        bt(nw + 1, mask | (1 << i), 1);
        return;
      }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = (0); i <= (1023); ++i) pre[i] = __builtin_popcount(i);
  cin >> tc;
  for (int ntc = (1); ntc <= (tc); ++ntc) {
    cin >> s >> k;
    n = s.size();
    if (k == 10) {
      cout << s << '\n';
      continue;
    }
    for (int i = (0); i < (n); ++i) x[i] = s[i] - '0';
    memset(&dp, -1, sizeof dp);
    f(0, 0, 0);
    bt(0, 0, 0);
    cout << '\n';
  }
  return 0;
}
