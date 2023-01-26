#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = 1e18;
void solve() {
  long long l, r;
  cin >> l >> r;
  long long n{};
  long long out = (r - l + 1);
  r++;
  while ((1 << n) <= r) {
    long long a = (r >> (n + 1)) << n;
    if (r & (1 << n)) {
      a += r & ((1 << n) - 1);
    }
    long long b = (l >> (n + 1)) << n;
    if (l & (1 << n)) {
      b += l & ((1 << n) - 1);
    }
    out = min(out, (r - l) - (a - b));
    n++;
  }
  cout << out << '\n';
}
long long main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
