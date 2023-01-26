#include <bits/stdc++.h>
const int mod = 998244353, MAXN = 1e5 + 1;
const long long inf = 1e18;
const double eps = 1e-12;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < a; i++) {
      ans++;
      curr ^= i;
    }
    if (curr == b)
      cout << ans;
    else if ((curr ^ b) != a)
      cout << ans + 1;
    else
      cout << ans + 2;
    cout << '\n';
  }
}
