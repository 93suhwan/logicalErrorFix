#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, mod = 998244353, L = 20;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> x(n);
  vector<long long> y(n);
  long long cnt[4];
  cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    x[i] /= 2;
    y[i] /= 2;
    if (x[i] % 2 == 0 && y[i] % 2 == 0) cnt[0]++;
    if (x[i] % 2 == 0 && y[i] % 2 == 1) cnt[1]++;
    if (x[i] % 2 == 1 && y[i] % 2 == 0) cnt[2]++;
    if (x[i] % 2 == 1 && y[i] % 2 == 1) cnt[3]++;
  }
  long long res = 0;
  for (long long i = 0; i < 4; ++i)
    res += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2)) / 6;
  for (long long i = 0; i < 4; ++i)
    for (long long j = 0; j < 4; ++j)
      if (i != j) res += cnt[j] * (cnt[i] * (cnt[i] - 1)) / 2;
  cout << res;
}
int32_t main() {
  long long t = 1;
  while (t--) solve();
}
