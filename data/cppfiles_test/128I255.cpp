#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const long long N = 0;
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      long long ne = n / i;
      if (ne >= 6) {
        cout << i << " " << 2 * i << " " << (ne - 3) * i << "\n";
        return;
      }
      if (ne != i) {
        long long nq = i;
        if (i >= 6) {
          cout << ne << " " << 2 * ne << " " << (i - 3) * ne << "\n";
          return;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
