#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
const long long maxSize = 1e5 + 5;
void solve() {
  long long n;
  cin >> n;
  long long m = ((n + 1) / 2) * 5;
  long long ans = 0;
  if (m % 15 == 0) {
    ans = m;
  } else if (m % 20 == 0) {
    ans = m;
  } else if (m % 25 == 0) {
    ans = m;
  } else {
    ans += 25 * (m / 25);
    m %= 25;
    if (m > 20) {
      ans += 25;
    } else if (m <= 15) {
      ans += 15;
    } else {
      ans += 20;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
