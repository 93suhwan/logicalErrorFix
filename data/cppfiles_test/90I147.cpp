#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MINF = -INF;
const int mod = 1e9 + 7;
const double eps = 1e-6;
inline long long ksm(long long a, long long b) {
  long long r = 1, t = a;
  while (b) {
    if (b & 1) r = (r * t) % mod;
    b >>= 1;
    t = (t * t) % mod;
  }
  return r;
}
inline long long inv1(long long b) { return ksm(b, mod - 2); }
const int N = 1e5 + 5;
void solve() {
  int x, y;
  cin >> x >> y;
  int n = 0;
  if (x > y) {
    n = x + y;
  } else {
    if (y % x == 0)
      n = x;
    else
      n = x * (y / x + 1) + y;
  }
  cout << n << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
