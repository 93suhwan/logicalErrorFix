#include <bits/stdc++.h>
using namespace std;
int long long mod = 1e9 + 7;
int long long dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int long long dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int long long timer = 0, n, m, t, k, eq = 0;
int long long a[1000001];
int long long power(int long long x, unsigned int long long y,
                    unsigned int long long m);
int long long modInverse(int long long a, int long long m) {
  { return power(a, m - 2, m); }
}
int long long power(int long long x, unsigned int long long y,
                    unsigned int long long m) {
  if (y == 0) return 1;
  int long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  cin >> t;
  a[0] = 1;
  a[1] = 1;
  for (int long long i = 1; i <= 1000000; i++) {
    a[i] = i * a[i - 1];
    a[i] %= mod;
  }
  while (t--) {
    cin >> n;
    int long long x = modInverse(2, mod);
    int long long y = a[2 * n];
    int long long ans = (x % mod * y % mod) % mod;
    cout << ans << "\n";
  }
}
