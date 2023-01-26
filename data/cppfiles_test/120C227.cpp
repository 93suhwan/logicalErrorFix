#include <bits/stdc++.h>
using namespace std;
const long long iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 7;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const long long maxn = 2e5 + 5;
long long cnt[20][maxn];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  for (long long i = 0; i < 20; ++i) {
    for (long long j = 1; j <= maxn - 1; ++j) {
      cnt[i][j] = cnt[i][j - 1] + ((j & (1 << i)) != 0);
    }
  }
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long re = 0;
    for (long long i = 0; i < 20; ++i) {
      re = max(re, (__typeof__(re))(cnt[i][r] - cnt[i][l - 1]));
    }
    cout << (r - l + 1) - re << '\n';
  }
}
