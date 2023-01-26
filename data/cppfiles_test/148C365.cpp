#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
long double eps = 1e-20;
long double pi = 3.141592653589793;
long double e = 2.718281828459045;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long x0;
  cin >> x0;
  long long a[x0];
  for (long long i = 0; i < x0; i++) cin >> a[i];
  sort(a, a + x0);
  long long ans = h * (a[x0 - 1] - a[0]);
  long long x1;
  cin >> x1;
  long long a1[x1];
  for (long long i = 0; i < x1; i++) cin >> a1[i];
  sort(a1, a1 + x1);
  ans = max(ans, h * (a1[x1 - 1] - a1[0]));
  long long y0;
  cin >> y0;
  long long a3[y0];
  for (long long i = 0; i < y0; i++) cin >> a3[i];
  sort(a3, a3 + y0);
  ans = max(ans, w * (a3[y0 - 1] - a3[0]));
  long long y1;
  cin >> y1;
  long long a4[y1];
  for (long long i = 0; i < y1; i++) cin >> a4[i];
  sort(a4, a4 + y1);
  ans = max(ans, w * (a4[y1 - 1] - a4[0]));
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
