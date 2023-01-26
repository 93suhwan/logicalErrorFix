#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e18;
long long ninf = -1e18;
long long pown(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (x * res) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long x = n / 3;
  long long a = (n - x);
  long long fi = inf, se = inf;
  if (a % 2 == 0) {
    a = a / 2;
    fi = abs(a - x);
  }
  long long b = (n - 2 * x);
  se = abs(b - x);
  if (fi > se) {
    cout << b << " " << x << "\n";
  } else {
    cout << x << " " << a << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
