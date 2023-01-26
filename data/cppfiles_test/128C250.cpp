#include <bits/stdc++.h>
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC optimize("-Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
using namespace std;
using namespace chrono;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 2;; i++) {
      if (gcd(i, (n - i - 1)) == 1) {
        cout << i << ' ' << n - i - 1 << ' ' << 1 << '\n';
        break;
      }
    }
  }
  return 0;
}
