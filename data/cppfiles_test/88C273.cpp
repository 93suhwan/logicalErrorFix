#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("arch=sandybridge")
#pragma GCC target("popcnt")
#pragma comment(linker, "/STACK:16777216")
const long double pi = 3.14159265;
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> q(n);
    for (long long i = 0; i < n; i++) cin >> q[i];
    bool flag = (n % 2 == 0);
    for (long long i = 1; i < n; i++) {
      if (q[i] <= q[i - 1]) {
        flag = true;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
