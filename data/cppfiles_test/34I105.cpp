#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
const long long inf = 0x3f3f3f3f3f3f3f;
const long long mod = 998244353;
const double eps = 1e-6;
const double PI = acos(-1);
const long long HASH = 131;
using namespace std;
long long a[maxn];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    cout << (n - 1) * n - k * (a[n] | a[n - 1]) << endl;
  }
  return 0;
}
