#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double esp = 1e-7;
long long a[maxn];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long m = max(l, r / 2 + 1);
    cout << r % m << '\n';
  }
}
