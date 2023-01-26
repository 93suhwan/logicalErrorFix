#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n;
long long ans = 1, now;
long long qmi(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans % mod;
}
int main() {
  now = 4 * 4;
  cin >> n;
  ans = 6 * qmi(now, (1ll << (n - 1)) - 1) % mod;
  cout << ans << endl;
  return 0;
}
