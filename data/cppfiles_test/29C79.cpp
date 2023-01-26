#include <bits/stdc++.h>
using namespace std;
long long mod = 1e19;
long long inf = 1e19;
long long get_pow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long o = 0, z = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == 0) z++;
      if (a[i] == 1) o++;
    }
    if (z == n)
      cout << 0 << endl;
    else
      cout << o * get_pow(2, z) << endl;
  }
}
